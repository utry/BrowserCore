#include "UtmpWebView.h"

UtmpWebView::UtmpWebView():QWebView()
{
    QWebSettings* default_settings = QWebSettings::globalSettings();
    default_settings->setAttribute(QWebSettings::JavascriptEnabled,true);
    default_settings->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled,true);
    default_settings->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled,true);
    default_settings->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
    default_settings->setAttribute(QWebSettings::LocalStorageEnabled,true);
    default_settings->setAttribute(QWebSettings::JavascriptCanAccessClipboard,true);
    default_settings->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
    default_settings->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    default_settings->setAttribute(QWebSettings::PluginsEnabled,true);
    default_settings->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
    //setContextMenuPolicy(Qt::NoContextMenu);

    //如何防止框架页面不被业务页面刷掉：
    //一般业务页面都是套在iframe中的，主要考虑防止target=_top的链接和window.top=''的js事件
    //1：如下，可以截获所有链接的点击事件,但信号当中并不能确定这个链接是不是target = _top的
    //this->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    //connect(this,SIGNAL(linkClicked(QUrl)),SLOT(openUrl(QUrl)));
    //2：可以重写QWebPage类的acceptNavigationRequest方法,但只能截获前进、后退、表单提交、刷新等操作，也不行
    //3：可以考虑在框架页面中写JS，修改业务页面中的代码（下策）

    connect(this->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
    this, SLOT(populateJavaScriptWindowObject()));

    connect(this->page(), SIGNAL(printRequested(QWebFrame*)),this,SLOT(customPrintRequested(QWebFrame*)));
    this->page()->setForwardUnsupportedContent(true);
    //这个槽没什么用
    connect(this->page(),SIGNAL(downloadRequested(QNetworkRequest)),this,SLOT(download(QNetworkRequest)));
    connect(this->page(),SIGNAL(unsupportedContent(QNetworkReply*)),this,SLOT(unsupportedContent(QNetworkReply*)));
}
void UtmpWebView::customPrintRequested(QWebFrame* frame)
{
    QPrinter* p = new QPrinter(QPrinter::HighResolution);
    //frame->print(p);
    //QPrinter p;
    QPrintDialog printDialog(p, this);
    printDialog.setWindowTitle("UTMP打印");
    if(printDialog.exec() != QDialog::Accepted)
    {
        return;
    }
    frame->print(p);
}
void UtmpWebView::navigationRequest()
{
    qDebug()<<"navigationRequest";
}
void UtmpWebView::openUrl(const QUrl &url)
{
    qDebug()<<"new url";
}

void UtmpWebView::populateJavaScriptWindowObject()
{
    this->page()->mainFrame()->addToJavaScriptWindowObject("QtWinFrame", this);
}

void UtmpWebView::SetFrameWindow(int flag)
{
    switch(flag)
    {
        case 0:
            this->close();
            break;
        case 1:
            this->showMinimized();
            break;
        case 2:
        {
            //全局也就只能有一个
            QDialog* d = new QDialog(this,(Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint|Qt::WindowCloseButtonHint));
            d->setAttribute(Qt::WA_DeleteOnClose, true);
            QWebInspector* wi = new QWebInspector(d);
            wi->setPage(this->page());
            d->setLayout(new QVBoxLayout());
            d->layout()->setMargin(0);
            d->layout()->addWidget(wi);
            d->show();
            d->resize(600,350);
            break;
        }
        case 3:
        {
            QMessageBox::StandardButton rb = QMessageBox::information(NULL, "from QT", "这是网页让QT弹出的对话框", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if(rb == QMessageBox::Yes)
            {
                //这样直接调用，执行速度异常慢
                //this->page()->mainFrame()->evaluateJavaScript("Ext.Msg.alert('from ext','这是QT让网页弹出的对话框');");
                this->page()->mainFrame()->evaluateJavaScript("testFun();");
            }
            break;
        }
        case 4:
        {
            this->reload();
        }
    }
}


void UtmpWebView::changeEvent(QEvent * event)
{
    if(event->WindowStateChange)
    {
       switch(this->windowState())
       {
           case Qt::WindowMinimized:
                this->hide();
                event->ignore();
               break;
           case Qt::WindowMaximized:
               QDesktopWidget* desktopWidget =QApplication::desktop();
               QRect deskRect =desktopWidget->availableGeometry();
               this->resize(deskRect.width(), deskRect.height());
               break;
       }
    }
}

UtmpWebView* UtmpWebView::createWindow(QWebPage::WebWindowType type)
{
    qDebug()<<"new window";
    UtmpWebView* webView = new UtmpWebView;
    QWebPage* newWeb = new QWebPage;
    if(type == QWebPage::WebModalDialog)
    {
        webView->setWindowModality(Qt::ApplicationModal);
    }
    webView->setAttribute(Qt::WA_DeleteOnClose,true);
    webView->setPage(newWeb);
    webView->show();
    return webView;
}
void UtmpWebView::download(const QNetworkRequest &request)
{
    //此槽看起来没什么用
    qDebug()<<"test";
}
void UtmpWebView::unsupportedContent(QNetworkReply * reply)
{
    qDebug()<<"Unsupported Content: "<<reply->url().toString();
    ShellExecuteA(NULL, "open", reply->url().toString().toStdString().c_str(), "", "", SW_SHOW);
}

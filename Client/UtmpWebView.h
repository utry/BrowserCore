#ifndef UTMPWEBVIEW_H
#define UTMPWEBVIEW_H

#include <QtGui>
#include <QWebPage>
#include <QWebView>
#include <QDebug>

#include <QMainWindow>
#include <QtWidgets>
#include <QtNetwork>
#include <QtWebKit>
#include <QtWebKitWidgets>
#include <QtGui>
#include <windows.h>

class UtmpWebView:public QWebView
{
    Q_OBJECT
public:
    UtmpWebView();
    UtmpWebView* createWindow(QWebPage::WebWindowType type);
protected slots:
    void openUrl(const QUrl &url);
    void populateJavaScriptWindowObject();
    void SetFrameWindow(int flag);
    void changeEvent(QEvent* event);
    void navigationRequest();
    void customPrintRequested(QWebFrame *frame);
    void download(const QNetworkRequest &request);
    void unsupportedContent(QNetworkReply * reply);
};

#endif // UTMPWEBVIEW_H

#include <QApplication>
#include <UtmpWebView.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UtmpWebView w;
    w.setWindowFlags(Qt::FramelessWindowHint);

    //加载本地EXT，貌似不行啊。
    QDir dir(QDir::currentPath());
    QUrl url = url.fromLocalFile(dir.path()+"/debug/index1.html");
    qDebug()<<url.toString();
    w.load(url);
    //w.load(QUrl("http://www.baidu.com"));

    w.showMaximized();
    return a.exec();
}

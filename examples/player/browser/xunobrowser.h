#ifndef XUNOBROWSER_H
#define XUNOBROWSER_H

//#include <QtWidgets>
#include <QUrl>
#include <QLabel>
#include <QDialog>

class QWebView;
class QLineEdit;
class QLabel;


class XunoBrowser : public QDialog
 {
     Q_OBJECT

 public:
    explicit XunoBrowser(QWidget *parent = 0);
    ~XunoBrowser();
    void setUrl(const QUrl& url);
    void setXUNOContentUrl(const QString &url);
    QUrl getClikedUrl();

signals:
    void clicked();

 protected slots:

     void adjustTitle();
     void adjustBrowserSize();
     void setProgress(int p);
     void finishLoading(bool);
     void linkClicked(QUrl url);

 private:
     QWebView *view;
 //    QLineEdit *locationEdit;
 //    QAction *rotateAction;
     QLabel *loading;
     int progress;
     QUrl clickedUrl;
     QString XUNOContentUrl;

     virtual void hideEvent(QHideEvent* e);
     virtual void showEvent(QShowEvent* e);
     virtual void resizeEvent(QResizeEvent* e);

};
#endif // XUNOBROWSER_H

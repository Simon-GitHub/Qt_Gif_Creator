#ifndef XYGIFFRAME_H
#define XYGIFFRAME_H

#include "xymovablewidget.h"
#include "xygifcreator.h"
#include <QTimer>

namespace Ui {
class XYGifFrame;
}

class XYGifFrame : public XYMovableWidget
{
    Q_OBJECT
public:
    explicit XYGifFrame(QWidget *parent = nullptr);

public slots:
    void doResize();
    void active();
    void start();
    void stop();
    void frame();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    // 用于resize窗口
private:
    bool   mStartResize;
    QRect  mStartGeometry;

private:
    Ui::XYGifFrame *ui;
    XYGifCreator   *mGifCreator;
    QTimer          mTimer;
    int             mPixs;
};

#endif // XYGIFFRAME_H

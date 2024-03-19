#ifndef GRAPHICSSIN_H
#define GRAPHICSSIN_H

#include <QMainWindow>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtGui>


QT_BEGIN_NAMESPACE
namespace Ui { class GraphicsSin; }
QT_END_NAMESPACE

class GraphicsSin : public QOpenGLWidget
{
    Q_OBJECT

public:
    GraphicsSin(QWidget *parent = nullptr);
    ~GraphicsSin();

private:
    Ui::GraphicsSin *ui;
protected:
void initializeGL(float x,float y, float z);
void resizeGL(int nWidth, int nHeight);
void paintGL();
};
#endif // GRAPHICSSIN_H

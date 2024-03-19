#include "graphicssin.h"
#include "ui_graphicssin.h"

GraphicsSin::GraphicsSin(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::GraphicsSin)
{
resize(300,300);
}

GraphicsSin::~GraphicsSin()
{
    delete ui;
}


void GraphicsSin::initializeGL(float x,float y, float z)
{
glClearColor( x, y, z, 1.0f );
glEnable(GL_DEPTH_TEST);
glShadeModel(GL_FLAT);
glEnable(GL_CULL_FACE);
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void GraphicsSin::resizeGL(int nWidth, int nHeight)
{
glViewport(0, 0, nHeight, nHeight);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
}

void GraphicsSin::paintGL() // рисование
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка буфера изображения и глубины

glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования
glLoadIdentity(); // загружает единичную матрицу моделирования

glClear( GL_COLOR_BUFFER_BIT );
glBegin(GL_QUADS);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(-0.5, 0.5, 0.5);
glVertex3f(-0.5, -0.5, 0.5);
glVertex3f(0.5, -0.5, 0.5);
glEnd();

}

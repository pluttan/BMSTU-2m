#include "graphicssin.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <cmath>
#include <functional>
#include <QOpenGLWidget>
#include <QtGui/QOpenGLFunctions>
#define pi M_PI


std::vector<double> linspace(double start, double stop, int num)
{
    std::vector<double> result(num);
    double step = (stop - start) / (num - 1);

    for (int i = 0; i < num; i++)
    {
        result[i] = start + i * step;
    }

    return result;
}

std::vector<std::vector<double>> vector_transform(std::vector<std::vector<double>>& x, double (*transform_fn)(double))
{
    std::vector<std::vector<double>> result;
    for (int i = 0; i < x.size(); i++)
    {
        result.push_back({});
        for (int j = 0; j < x[i].size(); j++)
        {
            result[i].push_back(transform_fn(x[i][j]));
        }
    }
    return result;
}

std::vector<std::vector<double>> vector_elementwise_multiply(const std::vector<std::vector<double>>& v1, const std::vector<std::vector<double>>& v2)
{
    std::vector<std::vector<double>> result(v1.size());

    for (int i = 0; i < v1.size(); i++)
    {
        result[i].resize(v1[i].size());

        for (int j = 0; j < v1[i].size(); j++)
        {
            result[i][j] = v1[i][j] * v2[i][j];
        }
    }

    return result;
}

void meshgrid(const std::vector<double>& x, const std::vector<double>& y, std::vector<std::vector<double>>& X, std::vector<std::vector<double>>& Y)
{
    X.resize(y.size());
    Y.resize(y.size());

    for (int i = 0; i < y.size(); i++)
    {
        X[i].resize(x.size());
        Y[i].resize(x.size());

        for (int j = 0; j < x.size(); j++)
        {
            X[i][j] = x[j];
            Y[i][j] = y[i];
        }
    }
}
//x = linspace(-pi/4, 3*pi/4, 200);
//z = linspace(-pi, pi, 200);

//% Создание матриц X и Z
//[X,Z] = meshgrid(x,z);

//% Вычисление значений функции sin(x)
//Y = sin(X);

//% Построение поверхности вращения
//% Построение поверхности вращения
//surf(X, Y.*cos(Z), Y.*sin(Z), 'EdgeColor', 'none');
//axis equal;
cclass OpenGLWidget : public QGLWidget {
    public:
        OpenGLWidget(QWidget *parent = nullptr) : QGLWidget(parent) {}
            virtual void initializeGL()  {
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                glEnable(GL_DEPTH_TEST);
            }
            virtual void paintGL() override {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();
                glTranslatef(0.0f, 0.0f, -10.0f);
                qglColor(Qt::white);
                glBegin(GL_LINES);
                // нижняя грань куба
                glVertex3f(-1.0f, -1.0f, -1.0f);
                glVertex3f(1.0f, -1.0f, -1.0f);

                glVertex3f(1.0f, -1.0f, -1.0f);
                glVertex3f(1.0f, -1.0f, 1.0f);

                glVertex3f(1.0f, -1.0f, 1.0f);
                glVertex3f(-1.0f, -1.0f, 1.0f);

                glVertex3f(-1.0f, -1.0f, 1.0f);
                glVertex3f(-1.0f, -1.0f, -1.0f);

                // верхняя грань куба
                glVertex3f(-1.0f, 1.0f, -1.0f);
                glVertex3f(1.0f, 1.0f, -1.0f);

                glVertex3f(1.0f, 1.0f, -1.0f);
                glVertex3f(1.0f, 1.0f, 1.0f);

                glVertex3f(1.0f, 1.0f, 1.0f);
                glVertex3f(-1.0f, 1.0f, 1.0f);

                glVertex3f(-1.0f, 1.0f, 1.0f);
                glVertex3f(-1.0f, 1.0f, -1.0f);

                // вертикальные грани куба
                glVertex3f(-1.0f, -1.0f, -1.0f);
                glVertex3f(-1.0f, 1.0f, -1.0f);

                glVertex3f(1.0f, -1.0f, -1.0f);
                glVertex3f(1.0f, 1.0f, -1.0f);

                glVertex3f(1.0f, -1.0f, 1.0f);
                glVertex3f(1.0f, 1.0f, 1.0f);

                glVertex3f(-1.0f, -1.0f, 1.0f);
                glVertex3f(-1.0f, 1.0f, 1.0f);

                glEnd();
            }
    virtual void resizeGL(int w, int h) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
};

int main(int argc, char *argv[])
{
    std::vector<double> x  = linspace(-pi/4, 3*pi/4, 200);
    std::vector<double> z  = linspace(-pi, pi, 200);
    std::vector<std::vector<double>> X;
    std::vector<std::vector<double>> Z;
    meshgrid(x,z,X,Z);
    std::vector<std::vector<double>> Y = vector_transform(X, sin);
    Y = vector_elementwise_multiply(Y, vector_transform(Z, cos));
    Z = vector_elementwise_multiply(Y, vector_transform(Z, sin));

    QString filename = "/Users/pluttan/Desktop/_Сем2/ООП/Data.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        for (int i = 0; i < X.size(); i++){
            for (int j = 0; j < X.size(); j++){
                stream << X[i][j] << " ";
            }
            stream << "\n";
        }
        stream << "\n";
        for (int i = 0; i < X.size(); i++){
            for (int j = 0; j < X.size(); j++){
                stream << Y[i][j] << " ";
            }
            stream << "\n";
        }
        stream << "\n";
        for (int i = 0; i < X.size(); i++){
            for (int j = 0; j < X.size(); j++){
                stream << Z[i][j] << " ";
            }
            stream << "\n";
        }
    }
    QApplication app(argc, argv);
    OpenGLWidget widget;
    widget.show();
    return app.exec();
}

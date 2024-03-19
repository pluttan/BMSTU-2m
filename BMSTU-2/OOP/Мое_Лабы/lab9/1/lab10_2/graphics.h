#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Graphics; }
QT_END_NAMESPACE

class Graphics : public QMainWindow
{
    Q_OBJECT

public:
    Graphics(QWidget *parent = nullptr);
    ~Graphics();

private:
    Ui::Graphics *ui;
};
#endif // GRAPHICS_H

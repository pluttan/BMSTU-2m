#include "graphics.h"
#include "ui_graphics.h"

Graphics::Graphics(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Graphics)
{
    ui->setupUi(this);
}

Graphics::~Graphics()
{
    delete ui;
}


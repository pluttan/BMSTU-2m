#include "widget.h"
#include <QTextCodec>
#include <QHBoxLayout>

Win::Win(QWidget *parent)
  : QWidget(parent)
{
  QTextCodec *codec =
             QTextCodec::codecForName("Windows-1251");
  setWindowTitle(codec->toUnicode("�����������"));
  helloLabel = new QLabel(codec->toUnicode("������!"),this);
  exitButton =
       new QPushButton(codec->toUnicode("�����"),this);
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(helloLabel);
  layout->addWidget(exitButton);
  connect(exitButton,SIGNAL(clicked(bool)),
          this,SLOT(close()));
}

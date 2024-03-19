/** 
  @file painter.cpp
  @brief ���������� ������� ���������.
*/
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include "painter.h"

/// @brief ����������� �������� ����
/// @details ������������� ����� ������������ ��������� � ������� ��.
Painter::Painter()
{
  QVBoxLayout *layout = new QVBoxLayout;

  m_RenderArea = new RenderArea( this );
  QPushButton * btn = new QPushButton( "Close", this );
  QObject::connect(btn, SIGNAL(clicked(bool)), 
    this, SLOT(close()));  

  layout->addWidget( m_RenderArea );
  layout->addWidget( btn );	  

  setLayout(layout);
};


/// @brief ����������� ������� �����������
/// @param parent - ���� �������� NULL, �� ������� ����������� ������
///        ��������������� �����. � ��������� ������ - ��������-��������.
/// @details ������ � ���� ������ ����������� ����� ����������� ����������,
///          ������� ����� ���������� ��� �����������.
RenderArea::RenderArea(QWidget *parent)
: QWidget(parent)
{
  setBackgroundRole(QPalette::Base);
  // ��������� �������������
  m_Path.moveTo(20.0, 30.0);
  m_Path.lineTo(80.0, 30.0);
  m_Path.lineTo(80.0, 70.0);
  m_Path.lineTo(20.0, 70.0);
  // �������� ������ - �������� ����� �� ��������� ����� � ������
  m_Path.closeSubpath();

  // ��������� ������ ����� (� ����. - pie - ����� ������)
  m_Path.moveTo(50.0, 50.0);
  m_Path.arcTo(20.0, 30.0, 60.0, 40.0, 60.0, 240.0);
  // �������� ������
  m_Path.closeSubpath();
}

QSize RenderArea::minimumSizeHint() const
{
  return QSize(50, 50);
}
QSize RenderArea::sizeHint() const
{
  return QSize(100, 100);
}

void RenderArea::paintEvent(QPaintEvent *)
{
  // ������� ������ �����������
  QPainter painter(this);
  
  // ���������� ����� ��������������� �� ������������ 
  painter.setRenderHint(QPainter::Antialiasing);
  
  // ���������� ������� � ����������� �� ������� �������������� �������� 
  // ������� �����������
  painter.scale(width() / 100.0, height() / 100.0);

  // ������� ���� ��� ����������� ��������. ���������� ������� ���� � ������� 
  // ����� ������ 2.
  painter.setPen(
    QPen(QColor(255,0,0), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

  // ���������� �������
  painter.drawPath( m_Path );

  // �������� �������������� ������������  �����
  painter.setPen(
    QPen(QColor(0,127,0), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
  painter.drawLine(50.0, 0.0, 50.0, 100.0);
}

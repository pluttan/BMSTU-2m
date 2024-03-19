/** 
@file painter.cpp
@brief ���������� ������� ���������.
*/
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QLineEdit>
#include <QSpacerItem>
#include <QImage>
#include <QLabel>
#include "painter.h"

#define _USE_MATH_DEFINES
#include "math.h"

// ������ ���� �����������
const float _x_aspect=400;
const float _y_aspect=400;

/// @brief ����������� �������� ����
/// @details ������������� ����� ������������ ��������� � ������� ��.
Painter::Painter()
{
	QVBoxLayout *layout = new QVBoxLayout;
	QHBoxLayout *hlayout = new QHBoxLayout;

	// ������ ������ ��� ����� ������ � ������ ���� ��������
	m_InputArea = new InputImage( this);
	m_RenderArea = new RenderArea( this );

	// ��������� ��������� ������ ��� ������� ����������
	QFrame * controls = new QFrame();
	QVBoxLayout *controllayout = new QVBoxLayout;
	controls->setLayout( controllayout );
	controls->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Expanding);

	m_Exy=new QLineEdit( "30", this); 
	m_Exz=new QLineEdit( "0", this);
	m_Eyz=new QLineEdit( "50", this);
	QPushButton * btn_convert = new QPushButton( tr("Convert") );
	QPushButton * btn_clear = new QPushButton( tr("Clear") );

	QObject::connect(btn_clear, SIGNAL(clicked(bool)), 
		m_InputArea, SLOT(clearImage()));  

	QObject::connect(btn_convert, SIGNAL(clicked(bool)), 
		this, SLOT(convert()));

	// ��������� ������ � �������� ����������
	controllayout->addWidget( new QLabel(tr("xy step")) );
	controllayout->addWidget( m_Exy );
	controllayout->addWidget( new QLabel(tr("xz angle")) );
	controllayout->addWidget( m_Exz );
	controllayout->addWidget( new QLabel(tr("yz angle")) );
	controllayout->addWidget( m_Eyz );
	controllayout->addWidget( btn_convert );
	controllayout->addItem( new QSpacerItem(10,10, QSizePolicy::Minimum, QSizePolicy::Expanding) );
	controllayout->addWidget( btn_clear );

	// ������������� ������� ����������� �������
	hlayout->addWidget( m_InputArea );	
	hlayout->addWidget( controls );
	hlayout->addWidget( m_RenderArea );

	QPushButton * btn = new QPushButton( tr("Close"), this );
	QObject::connect(btn, SIGNAL(clicked(bool)), 
		this, SLOT(close()));  

	// ��������� ������������� ���, ��������� ������ Close
	layout->addLayout(hlayout);
	layout->addWidget( btn );	  

	setLayout(layout);
};

/// @details ��������� ������ �����, ����������� ��������� �������� �����,
///          ��������� ������������ ���� ��������
void Painter::convert()
{
	double xy_step_angle, yz_angle, xz_angle;
	QVector<BaseRenderArea::PointCoords> data;

	xy_step_angle =  m_Exy->text().toDouble()*M_PI/180.0;
	yz_angle =  m_Eyz->text().toDouble()*M_PI/180.0;
	xz_angle =  m_Exz->text().toDouble()*M_PI/180.0;

	m_InputArea->getPoints(data);
	m_RenderArea->setPoints(data, xy_step_angle, yz_angle, xz_angle);
};

/// @details ����������� �������� ������ ������� ����� � �����������.
///          ������������� ������ ����� � �������������� ����� ����������.
/// @param parent - ���� �������� NULL, �� ������� ����������� ������
///        ��������������� �����. � ��������� ������ - ��������-��������.
BaseRenderArea::BaseRenderArea(QWidget *parent):QFrame(parent)
{
	// ��������� ����� ������ �������
	setFrameStyle(QFrame::Panel | QFrame::Raised);
	setLineWidth(2);
	//��������� ���� �� ���������, ������ 2
	m_PenWidth=2;
};

// �����������������, ���� ���������� ��������� ��������� ������ 
// ��� ��������� �������� ����
//void BaseRenderArea::resizeEvent(QResizeEvent *event)
//{
//	QSize size=event->size();
//	if (size.width() > size.height() ) {
//		size.setWidth(size.height());
//	} else if (size.width() < size.height() ) {
//		size.setHeight(size.width());
//	}
//	resize(size);
//}

QSize BaseRenderArea::minimumSizeHint() const
{
	return QSize(100, 100);
}
QSize BaseRenderArea::sizeHint() const
{
	return QSize(_x_aspect, _y_aspect);
}

void BaseRenderArea::paintEvent(QPaintEvent *event)
{
	// ������� ������ �����������
	QPainter painter(this);

	// ���������� ����� ����������� �� ������������ 
	painter.setRenderHint(QPainter::Antialiasing);

	// ���������� ������� � ����������� �� ������� �������������� �������� 
	// ������� �����������
	painter.scale( width()/_x_aspect, height()/_y_aspect );

	// ������� ���� ��� ����������� ��������. ���������� ������� ���� � ������� 
	// ����� ������ m_PenWidth.
	painter.setPen(
		QPen(QColor(255,0,0), m_PenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

	// ���������� �������
	painter.drawPath( m_Path );

	QFrame::paintEvent(event); // ������ ����� ������ ������ ������� ������
}

/// @brief ����������� ������� �����������
RenderArea::RenderArea(QWidget *parent)
: BaseRenderArea(parent)
{
	setBackgroundRole(QPalette::Base);
	QFont font("Arial", 12);
	m_Path.addText( 10,_y_aspect/2, font, tr("Draw on the left panel"));
	m_PenWidth=0.5;
}

/// @param data - ������ ����� ������
/// @param xy_step_angle - ��� �������� ��� ������������ ���� �������� � ��������
/// @param yz_angle - ���� �������� � �������� ��������� yz
/// @param xz_angle - ���� �������� � �������� ��������� xz
void RenderArea::setPoints( const QVector<PointCoords> & data, 
						   double xy_step_angle, double yz_angle, double xz_angle )
{
	m_Path=QPainterPath();	// ������� ������� ������

	if(!data.size())return; // ���� �� ����� ������ ��� - �������

	double phi;
	double x,y,z;
	double xw, yw;

	// ��� ��������� ������ ���������, ������ � ��������
	// ��������� �������
	double cos_yz=cos(yz_angle), sin_yz=sin(yz_angle);
	double cos_xz=cos(xz_angle), sin_xz=sin(xz_angle);	

	// ����, ����������� ���� �������� �� �����
	for( phi=M_PI/24; phi<2*M_PI+M_PI/24; phi+=xy_step_angle){
		const PointCoords  *point;
		double sin_r1=sin(phi), cos_r1=cos(phi);
		for(int i=0; i<data.size();i++){
			point=&data[i];

			// ������������� ����������.
			z=point->x;
			x=point->y;
			// ������� ����� z.  ������������ ��������� x-y. 
			// ��������� y=0, ���������� ������������ y �����������
			xw=x*cos_r1; //-y*sin_fi;
			y=x*sin_r1; //+y*cos_fi;
			x=xw;

			// ������������ � ��������� y-z
			yw=y*cos_yz-z*sin_yz;
			z=y*sin_yz+z*cos_yz; 
			y=yw;

			// ������������ � ��������� x-z
			xw=x*cos_xz-z*sin_xz;
			//z=x*sin_fi+z*cos_fi;// z - ������ �� ������������
			x=xw;

			//���������� �� �����, �������� z
			//������� � �������� ������ � ������������ � ������������� 0.5
			xw=_x_aspect/2+x*0.5;
			yw=_y_aspect/2+y*0.5;

			if( !i ) m_Path.moveTo(xw,yw);
			else m_Path.lineTo(xw,yw);
		}		
	}
	update();
};

InputImage::InputImage(QWidget *parent)
:BaseRenderArea(parent)
{
};

/// @details ����������� ���������� ���� � ��������� ���������� �������
QPoint InputImage::from(const QPoint &point){
	
	QPoint pos = mapFrom( this, point );
	return QPoint( pos.x()* _x_aspect/ width(), pos.y()*_y_aspect/ height() );
};

void InputImage::mousePressEvent ( QMouseEvent * event )
{
	//���� ������ ����� ������ ���� - ������
	if (event->buttons () & Qt::LeftButton){
		m_Path.moveTo( from(event->pos()) );
	}
}
void InputImage::mouseMoveEvent ( QMouseEvent * event )
{
	if (event->buttons () & Qt::LeftButton){
		m_Path.lineTo( from(event->pos()) );
	}
	// ������������� ������������. ��������! ���������� ����������.
	// �� ������ �������� ���� ����� �������������� ��, ��� ���� ������� �����
	update(); 
};

void InputImage::clearImage()
{
	m_Path=QPainterPath(); // ������ ������ ������. 
	update();// ������� �����������.
};

void InputImage::getPoints( QVector<PointCoords> & data )
{
	data.clear(); // ������� ������ �� ������, ���� ��� ���-�� ����
	QColor color(255,0,0); QRgb rgb_color=color.rgb();
	// ��������� ���������� �����������
	QImage image( _x_aspect,_y_aspect, QImage::Format_RGB32 );
	QPainter painter(&image);
	painter.setPen( QPen(color, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	//������� ����������� �������
	painter.drawPath( m_Path );

	//��������� ������� ����������� � ������� ��������
	for(int x=0; x<_x_aspect; x++){
		// ��������� ����� �����������
		for(int y=image.height(); y>=0; y--){
			QRgb rgb=image.pixel(x,y);
			if( rgb==rgb_color ){
				//���������� ������ ����� ������� � ��������������� ������				
				data.push_back( PointCoords(x,image.height()-y));
				break;
			}
		}
	}
};

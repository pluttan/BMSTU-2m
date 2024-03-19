/** 
@file painter.h
@brief ���������� ������� ���������.
*/
#include <QWidget>
#include <QVector>
#include <QFrame>

class RenderArea;
class InputImage;
class QLineEdit;
/**
@class Painter
@brief ������� ���� ����������.
@details ������������ ������������ ���� ����������, ����������� 
������� ����������� ������� � ������ ������
*/
class Painter : public QWidget
{
	Q_OBJECT

public:
	Painter();

protected:
	RenderArea * m_RenderArea; ///< ������� ����������� �������.
	InputImage * m_InputArea;  ///< ������� ��������� ������ ��� ��������.
	QLineEdit * m_Exy;         ///< ��� �������� ��� ������������ ���� ��������.
	QLineEdit * m_Eyz;         ///< ���� �������� � �������� ��������� yz
	QLineEdit * m_Exz;         ///< ���� �������� � �������� ��������� xz

	public slots:
		void convert();
};

/// @class BaseRenderArea
/// @brief ������� ����� ��� ������� ����� � �����������.
class BaseRenderArea: public QFrame
{
	Q_OBJECT

public:  
	///@brief ��������� ��� �������� ��������� � �������
	struct PointCoords {
		int x;
		int y;
		PointCoords(){ x=y=0;};
		PointCoords(int x1, int y1){
			x=x1; y=y1;
		};
	};
	BaseRenderArea(QWidget *parent = 0);

	/// @brief ����������� ������ ������� ����������� 
	/// @details ��������� �������� ���� ���������� ������������ � ������ 
	/// ���������� �������� ���� ���������. ������� ������������ ���������� 
	/// ����������� ������� ����������� ����������
	/// @return ���������� ����������� �������
	QSize minimumSizeHint() const;

	/// @brief ������ ������� ����������� �� ���������
	/// @details ��� �������� ���� ������������� �������������� ������� 
	/// �� ��������� ��������������� �������� ���� ���������.
	/// @return ��������������� �������
	QSize sizeHint() const;

	/// @brief ��������� ���� �������� �� ���������� ������� ���������
	void setPoints( const QVector<PointCoords> &, 
		double xy_step_angle, double yz_angle, double xz_angle );

protected:	
	float m_PenWidth; ///< ������ ���� ����������� �� ���������.

	/// @brief ���������� ������� �����������  
	virtual void paintEvent(QPaintEvent * event);

	QPainterPath m_Path; ///< ������ ����������� ����������� ����������.

	//	void resizeEvent(QResizeEvent *event);	
};

/**
@class RenderArea
@brief ������� ����������� ���� ��������.
@details ��������� � ���������� �������
*/
class RenderArea : public BaseRenderArea
{
	Q_OBJECT

public:  
	RenderArea(QWidget *parent = 0);

	/// @brief ����� ��� ������������ ���� �������� �� ������� ��������
	void setPoints( const QVector<PointCoords> &, 
		double xy_step_angle, double yz_angle, double xz_angle );
};

/**
@class InputImage
@brief ������� ������������ ������.
@details ������������ ������������, ��������� ������.
*/
class InputImage : public BaseRenderArea
{
	Q_OBJECT

public:
	InputImage(QWidget *parent = 0);

	/// @brief ����� ��� ������������ ���������� �����������
	void getPoints( QVector<PointCoords> & );

	public slots:
		/// @brief ������� �����������
		void clearImage();

protected:
	/// @brief ���������� ������� ������� ������� ����
	virtual void mousePressEvent ( QMouseEvent * event );
	/// @brief ���������� ������� ����������� ����
	virtual void mouseMoveEvent ( QMouseEvent * event );

	/// @brief ��������������� ����� �������������� ���������
	QPoint from(const QPoint&);
};

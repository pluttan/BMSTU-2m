/** 
  @file painter.h
  @brief ���������� ������� ���������.
*/
#include <QWidget>

class RenderArea;
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
};

/**
  @class RenderArea
  @brief ������� ����������� �������.
  @details ���������, ���������� � ���������� ����� ����������� ����������
*/
class RenderArea : public QWidget
{
	Q_OBJECT

public:  
	RenderArea(QWidget *parent = 0);

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

protected:
  /// @brief ���������� ������� �����������  
	virtual void paintEvent(QPaintEvent * event);
private:
	QPainterPath m_Path; ///< ������ ����������� ����������� ����������.
};

#include <QtCore/QCoreApplication>
#include <QSet>
#include <QTextStream>
#include <QTime>

const int MAX_WORDS = 20;
const int MAX_CHARS = 2;
//*****************************************************************************
// ������ ������������� QSet � ����� �� ������ ������������

/// �����, ���������������� � ��������
class InsensitiveString : public QString
{
public:
	/// ������� ���������. ������������� const �������� �������������!
	/// ������������ ������ � ��� ������, ���� ���-�������� �������, 
	/// ������� ������������ ��������� ��������.
	bool operator== ( const InsensitiveString & other ) const
	{
		return this->toLower() == other.toLower();
	};
};
/// ���������� ���-������� ��� ���� InsensitiveString
uint qHash( const InsensitiveString & var )
{    // �������� � ������� �������� � � ����������� qHash(const QString&)
	return qHash( var.toLower());
};
void test_qset()
{
	// ���������� ����������� ����� ������ ��� ������ ������ � �������
	QTextStream out(stdout);
	out<<"********************"<<__FUNCTION__<<"********************"<<endl;
	// ��������� ���������
	QSet <InsensitiveString> st;
	InsensitiveString str;
	// ������� �������� ��������������� ��������
	for( int i=0; i<MAX_WORDS; i++ ){
		str.clear();
		for( int j=0; j<MAX_CHARS; j++ )
			str.append( QChar( (qrand()%('z'-'A')) + 'A' ) );
		st.insert( str );
	};
	// ��������� ����� ������ � ���������, ������ �� 
	for( int i=0; i<MAX_WORDS; i++ ){
		str.clear();
		for( int j=0; j<MAX_CHARS; j++ )
			str.append( QChar( (qrand()%('z'-'A')) + 'A' ) );

		// ���������, ���� �� ��� ����� �������� �� ���������
		// � ������� ���������
		if(st.find( str ) != st.end() ){		
			out<<"Val " << str << " exist" << endl;
		} else
			out<<"Val " << str << " not exist" << endl;
	};
	// ������� ��� �������� ���������. �������� ��������, ��� ��������
	// �� ����������� !!!
	QSetIterator<InsensitiveString> i(st);
	while (i.hasNext())
		out << i.next() << endl;
};
//*****************************************************************************
// ������ ������������� QSet � ����� �����
#include <qHash>
/// �����, ������������ ����� ���
class RawData
{
public:
	/// ����������� �� ��������� �������������� ��������� ������� ��������
	RawData(){ m_val = qrand()%10 - 5; };

	/// ������� ��������� ��������. ������������ const ����� ���������!
	int val() const { return m_val;};

	/// ������ ���������. ������������� const �������� �������������!
	/// ������������ ������ � ��� ������, ���� ���-�������� �������, 
	/// ������� ������������ ��������� ��������.
	bool operator== ( const RawData & other ) const
	{
		return this->m_val == other.m_val;
	};
protected:
	int m_val;
};

/// ���������� ����� ���-�������, ����������� �������� � ����� �����
uint qHash( const RawData & var )
{
	// ��������� �������� �������, ������������� ����������� ���-��������
    // ��� ������ ����
	return qHash( var.val() );
};
void test_qset2()
{
	// ���������� ����������� ����� ������ ��� ������ ������ � �������
	QTextStream out(stdout);
	out<<"********************"<<__FUNCTION__<<"********************"<<endl;
	
	// ���������� ��������� � ��������� ���
	QSet <RawData> st;	
	for( int i=0; i<MAX_WORDS; i++ ){
		RawData data;
		st.insert( data );
	};

    // ������� ����� �������� � ���������, ���� �� ����� ��
	for( int i=0; i<MAX_WORDS; i++ ){
		RawData data;
		if(st.find( data ) != st.end() ){
			out<<"Val " << data.val() << " exist" << endl;			
		} else
			out<<"Val " << data.val() << " not exist" << endl;
	};

	// ������� ��� �������� ���������.
	// �������� �� �����������!!!
	QSetIterator<RawData> i(st);
	while (i.hasNext())
		out << i.next().val() << endl;
};




//*****************************************************************************
// ������ ������������� QMap � ����� �� ������ ������������
#include <QMap>
/// �����, ���������������� � ��������
class InsensitiveString2 : public QString
{
public:
	// �������������� ������� ���������. ��������� ����� ������������ QMap,
	// ������� ���������� ������, ���������� �������������� operator<
	bool	operator< ( const InsensitiveString2 & other ) const
	{
		return this->toLower() < other.toLower();
	};
};
void test_qmap()
{
	// ���������� ����������� ����� ������ ��� ������ ������ � �������
	QTextStream out(stdout);
	out<<"********************"<<__FUNCTION__<<"********************"<<endl;
	
	// ��������� map, ������� ���� ���� InsensitiveString2 � ��������� ��������
	QMap <InsensitiveString2, int> st;
	InsensitiveString2 str;
    // ������� �������� ��������������� ����� � ����������� ����������
	for( int i=0; i<MAX_WORDS; i++ ){
		str.clear();
		for( int j=0; j<MAX_CHARS; j++ )
			str.append( QChar( (qrand()%('z'-'A')) + 'A' ) );
		st.insert( str, 0 );
	};
	// ��������� ����� ������ � ���������, ������ �� 
	for( int i=0; i<MAX_WORDS; i++ ){
		str.clear();
		for( int j=0; j<MAX_CHARS; j++ )
			str.append( QChar( (qrand()%('z'-'A')) + 'A' ) );

		// ���������, ���� �� ��� ����� �������� �� ���������
		// � ������� ���������
		if(st.find( str ) != st.end() ){
			out<<"Val " << str << " exist" << endl;
		} else
			out<<"Val " << str << " not exist" << endl;
	};

	// ������� ��� �������� map. 
	// ����� ��� �������� ��������� � ������� ���������� 
	// (�� �����������, ��������� �������)
	QMapIterator <InsensitiveString2, int> iter(st);
	while (iter.hasNext()){
		iter.next();
		out << iter.key() << endl;
	};
};
//*****************************************************************************
// ������ ������������� QMap � ����� �����

/// �����, ������������ ����� ���
class RawData2
{
public:
	/// ����������� �� ��������� �������������� ��������� ������� ��������
	RawData2(){ m_val = qrand()%10 - 5; };	
	/// ������� ��������� ��������. ������������ const ����� ���������!
	int val() const { return m_val;};

	/// ������ ���������. ������������� const �������� �������������!
	/// ��������� ���������� QMap, �� operator<
	bool	operator< ( const RawData2 & other ) const
	{
		return this->m_val < other.m_val;
	};
protected:
	int m_val;
};
void test_qmap2()
{
	// ���������� ����������� ����� ������ ��� ������ ������ � �������
	QTextStream out(stdout);
	out<<"********************"<<__FUNCTION__<<"********************"<<endl;
	
	// ��������� map, ������� ���� ���� InsensitiveString2, int
	// � ��������� ������ ����-��������� �������� (�� ������������)
	QMap <RawData2, int> st;	
	for( int i=0; i<MAX_WORDS; i++ ){
		RawData2 data;
		st.insert( data,0 );
	};

	// ������� ����� �������� � ���������, ���� �� ����� ��
	for( int i=0; i<MAX_WORDS; i++ ){
		RawData2 data;

		// ���������, ���� �� ��� ����� �������� �� ���������
		// � ������� ���������
		if(st.find( data ) != st.end() ){
			out<<"Val " << data.val() << " exist" << endl;			
		} else
			out<<"Val " << data.val() << " not exist" << endl;
	};

	// ������� ��� �������� map. 
	// ����� ��� �������� ��������� � ������� ���������� 
	QMapIterator <RawData2, int> iter(st);
	while (iter.hasNext()){
		iter.next();
		out << iter.key().val() << endl;
	};
};
//*****************************************************************************

int main(int argc, char *argv[])
{
	// �������������� ��������� ��������������� ����� ������� ��������
	QTime time;
	qsrand(time.secsTo(QTime::currentTime()));

	test_qset();
	test_qset2();
	test_qmap();
	test_qmap2();

	// ����, ���� ������������ ������ Enter
	QTextStream(stdin).readLine();
	return 0;
}

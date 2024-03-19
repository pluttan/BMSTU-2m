#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtCore/QObject>

class Widget : public QWidget {
public:
    Widget(QWidget *parent = nullptr) : QWidget(parent) {
        m_textEdit = new QTextEdit();
        m_textEdit2 = new QTextEdit();

        m_button = new QPushButton("Convert");

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(m_textEdit);
        layout->addWidget(m_button);
        layout->addWidget(m_textEdit2);

        setLayout(layout);

        connect(m_button, &QPushButton::clicked, this, &Widget::onButtonClicked);
    }

public slots:
    void onButtonClicked() {
        QString text = m_textEdit->toPlainText();
        QString textLower = "\nall lower: " + text.toLower();
        QString textUpper = "\nALL UPPER: " + text.toUpper();
        m_textEdit2->setPlainText("input: " + text+textLower+textUpper);
    }

private:
    QTextEdit *m_textEdit;
    QTextEdit *m_textEdit2;
    QPushButton *m_button;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Widget *window = new Widget();
    window->show();

    return app.exec();
}

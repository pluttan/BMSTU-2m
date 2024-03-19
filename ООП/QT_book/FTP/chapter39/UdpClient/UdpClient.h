// ======================================================================
//  UdpClient.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QTextEdit>

class QUdpSocket;

// ======================================================================
class UdpClient : public QTextEdit {
Q_OBJECT
private:
    QUdpSocket* m_pudp;

public:
    UdpClient(QWidget* pwgt = 0);

private slots:
    void slotProcessDatagrams();
};


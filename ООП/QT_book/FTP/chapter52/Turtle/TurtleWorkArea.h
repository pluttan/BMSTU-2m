// ======================================================================
//  TurtleWorkArea.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QWidget>
#include <QJSEngine>

class QTextEdit;
class Turtle;

// ======================================================================
class TurtleWorkArea : public QWidget {
Q_OBJECT
private:
    QTextEdit* m_ptxt;
    QJSEngine  m_scriptEngine;
    Turtle*    m_pTurtle;

public:
    TurtleWorkArea(QWidget* pwgt = 0);

private slots:
    void slotEvaluate (   );
    void slotApplyCode(int);
};


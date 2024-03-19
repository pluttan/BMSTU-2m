// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QApplication>
#include "MyApplication.h"

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication  app(argc, argv);  
    MyApplication myApplication;

    myApplication.show();

    return app.exec();
}

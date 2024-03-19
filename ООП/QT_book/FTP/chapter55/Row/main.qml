// ======================================================================
//  main.qml
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

import QtQuick 2.8

Item {
    width: 360
    height: 160

    Row {
        anchors.centerIn: parent
        spacing: 10
        Rectangle {
            width: 64; height: 64; color: "red"
        }
        Rectangle {
            width: 64; height: 64; color: "blue"
        }
        Rectangle {
            width: 64; height: 64; color: "green"
        }
    }
}

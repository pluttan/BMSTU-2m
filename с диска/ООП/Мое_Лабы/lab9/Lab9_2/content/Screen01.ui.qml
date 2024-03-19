/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.2
import QtQuick.Controls 6.2
import Lab9_2
import QtQuick.Layouts 1.0

Rectangle {
    id: rectangle
    width: 404
    height: 404
    color: "#424242"
    border.color: "#ffffff"


    ColumnLayout {
        x: 8
        y: 8
        width: 396
        height: 388
        RowLayout {
            TextEdit {
                id: textEdit
                color: "#fefefe"
                text: qsTr("Text Edit")
                font.pixelSize: 12
                Layout.preferredHeight: 289
                Layout.preferredWidth: 257
            }

            ColumnLayout {
                Dial {
                    id: dial
                    visible: true
                    layer.enabled: false
                    smooth: true
                    scale: 1
                }

                SpinBox {
                    id: spinBox
                    visible: true
                    layer.enabled: false
                    Layout.preferredHeight: 30
                    clip: false
                    Layout.preferredWidth: 100
                }
            }
        }

        RowLayout {

            Label {
                id: label
                color: "#ffffff"
                text: qsTr("Нажмите кнопку ->")
            }

            Button {
                id: button
                text: qsTr("Выйти")
                icon.color: "#000000"
                display: AbstractButton.TextBesideIcon
            }
        }
    }
    states: [
        State {
            name: "clicked"
            when: button.checked
        }
    ]
}

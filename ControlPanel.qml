import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

ScrollView {
    id: root
    signal addpoint(int indexLine, int x, int y)
    ColumnLayout {
        Text {
            id: lableAddPoint
            text: qsTr("Add point[x, y]")
            font.pointSize: 15
        }
        ComboBox {
            id: comboBoxSelectLine
            model: 1
            delegate: Button {
                width: parent.width
                text: "line " + index
            }
            displayText: "line " + currentIndex
        }
        SpinBox {
            id: _sbX
            value: 0
            from: -100
            to: 100
            validator: IntValidator {
                bottom: -100
                top: 100
            }
        }
        SpinBox {
            id: _sbY
            value: 0
            from: -100
            to: 100
            validator: IntValidator {
                bottom: -100
                top: 100
            }
        }
        Button {
            id: btnAddPoint
            text: "AddPoint"
            onClicked: {
                console.log(comboBoxSelectLine.currentIndex)
                root.addpoint(comboBoxSelectLine.currentIndex, _sbX.value, _sbY.value)
            }
        }
        CheckBox {
            text: "line" + 0
        }
        CheckBox {
            text: "line" + 1
        }
        CheckBox {
            text: "line" + 2
        }

        Repeater {
            anchors.fill: parent
            model: appEngine.models()
            delegate: CheckBox {
                text: "line" + index
            }
        }
    }

    FocusScope {
        id: focusScope
        x: 0
        y: 359
        width: 150
        height: 90

        Text {
            id: text1
            x: 64
            width: 150
            text: qsTr("Размер дисплея")
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            font.pixelSize: 16
            anchors.topMargin: 37
            anchors.horizontalCenter: parent.horizontalCenter
        }
        RadioButton {
            id: rdb600
            x: 0
            y: 50
            checked: true
            text: qsTr("600")
            onClicked: width = 600
        }
        RadioButton {
            id: rdb1200
            x: 80
            y: 50
            anchors.right: parent.right
            anchors.rightMargin: 0
            checked: false
            text: qsTr("1200")
        }
    }
}


/*##^##
Designer {
    D{i:0;height:450;width:150}D{i:16}
}
##^##*/

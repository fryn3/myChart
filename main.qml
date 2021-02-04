import QtQuick.Controls 2.5
import QtQuick 2.12

ApplicationWindow {

    width: 600
    height: width * 0.75
    visible: true

    maximumWidth: width
    maximumHeight: height
    minimumHeight: height
    minimumWidth: width

    MyChart {
        id: _view
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: panel.left
    }

    ControlPanel {

        id: panel
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        width: parent.width * 0.25
        onAddpoint: {
            _view.addPoint(indexLine, x, y)
        }
    }
}

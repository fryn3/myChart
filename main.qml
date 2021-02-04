import QtQuick.Controls 2.5
import QtQuick 2.12

ApplicationWindow {
    id: root
    width: 600
    height: width * 0.75
    visible: true

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
        onClickedRadio: {
            root.maximumWidth = widthParam
            root.minimumWidth = widthParam
            root.maximumHeight = widthParam * 0.75
            root.minimumHeight = widthParam * 0.75
            root.width = widthParam
            root.height = widthParam * 0.75
        }

    }
}

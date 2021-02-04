import QtCharts 2.0

ChartView {
    id: root
    theme: ChartView.ChartThemeBrownSand
    antialiasing: true

    function checkAxises(x, y) {
        if (_axisX.min > x) {
            _axisX.min = x
        } else if (_axisX.max < x) {
            _axisX.max = x
        }
        if (_axisY.min > y) {
            _axisY.min = y
        } else if (_axisY.max < y) {
            _axisY.max = y
        }
    }

    function addPoint(ser, x, y) {
        var s
        if ("line" + ser === _line0.name) {
            s = _line0
        } else {
            console.log("MyChart::root::addPoint bad ser", ser)
            return
        }
        _line0.append(x, y)
        checkAxises(x, y)
    }

    ValueAxis {
        id: _axisX
        min: -5
        max: 5
    }

    ValueAxis {
        id: _axisY
        min: -5
        max: 5
    }

    SplineSeries  {
        id: _line0
        name: "line0"
        axisX: _axisX
        axisY: _axisY
    }
}

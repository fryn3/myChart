#pragma once

#include <QObject>

#include "linesmodel.h"
#include "myxymodel.h"

class AppEngine : public QObject
{
    Q_OBJECT
public:
    AppEngine(QObject *parent = nullptr);
    virtual ~AppEngine() = default;

    LinesModel &model() { return _model; }

private:
    LinesModel _model;
//    QVector<MyXyModel*> _models;
};

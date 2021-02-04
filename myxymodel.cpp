#include "myxymodel.h"

#include <QDebug>

MyXyModel::MyXyModel(QObject *parent) : QAbstractTableModel(parent) { }

MyXyModel::MyXyModel(QString legenda, QObject *parent) : QAbstractTableModel(parent), _legenda(legenda) { }

int MyXyModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 2;
}

int MyXyModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return _data.size();
}

QVariant MyXyModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()
            || index.column() >= columnCount()
            || index.row() >= rowCount()) { return QVariant(); }
    Q_ASSERT(role == Qt::DisplayRole);
    switch (index.column()) {
    case 0:
        return _data.at(index.row()).x();
    case 1:
        return _data.at(index.row()).y();
    default:
        Q_ASSERT(false);
    }
}

bool MyXyModel::insertRows(int row, int count, const QModelIndex &parent) {
    if (row > rowCount() && count > 0) { return false; }
    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i) {
        _data.insert(row, QPointF());
    }
    endInsertRows();
    return true;
}

QHash<int, QByteArray> MyXyModel::roleNames() const {
    auto p = QAbstractTableModel::roleNames();
    qDebug() << p;
    return QHash<int, QByteArray> {{ Qt::DisplayRole, p[Qt::DisplayRole]}};
}

bool MyXyModel::addPoint(QPointF p, int index) {
    if (index == -1) {
        index = columnCount();
    }
    if (!insertRow(index)) { return false; }
    _data[index] = p;
    emit dataChanged(createIndex(index, 0),
                     createIndex(index, 1),
                     { Qt::DisplayRole });
    return true;
}

bool MyXyModel::addPoint(int x, int y, int index) {
    return addPoint(QPointF(x, y), index);
}

QString MyXyModel::legenda() const {
    return _legenda;
}

void MyXyModel::setLegenda(const QString &legenda) {
    if (_legenda == legenda) { return; }
    _legenda = legenda;
    emit legendaChanged();
}



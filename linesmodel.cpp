#include "linesmodel.h"
#include "myfuncs.h"

#include <QDebug>

const QString LinesModel::ITEM_NAME = "LinesModel";
const bool LinesModel::IS_QML_REG = My::qmlRegisterType<LinesModel>(LinesModel::ITEM_NAME);

const std::array<QString, LinesModel::LinesRoleEnd - LinesModel::LinesRoleBegin>
        LinesModel::LINES_ROLE_STR {
    "xyModel",
};

LinesModel::LinesModel(QObject *parent) : QAbstractListModel(parent) { }

void LinesModel::appendLine(QString name) {
    Q_UNUSED(name);
}

int LinesModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return _lines.size();
}

QVariant LinesModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.column() > 0 || index.row() > rowCount()) {
        return QVariant();
    }
    auto &lineModel = _lines.at(index.row());
    switch (role) {
    case Qt::DisplayRole:
        return lineModel->legenda();
    case XyModel:
        return QVariant::fromValue(lineModel);
    default:
        Q_ASSERT(false);
        return QVariant();
    }
}

QHash<int, QByteArray> LinesModel::roleNames() const {
    auto h = QAbstractListModel::roleNames();
    QHash<int, QByteArray> r = {{Qt::DisplayRole, h.value(Qt::DisplayRole)}};
    for (uint i = 0; i < LINES_ROLE_STR.size(); ++i) {
        r[LinesRoleBegin + i] = LINES_ROLE_STR.at(i).toUtf8();
    }
    qDebug() << __PRETTY_FUNCTION__ << r;
    return r;
}

bool LinesModel::insertRows(int row, int count, const QModelIndex &parent) {
    if (row > rowCount() && count > 0) { return false; }
    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i) {
        _lines.insert(row, new MyXyModel(QString::number(row + i), this));
    }
    endInsertRows();
    return true;
}

#pragma once

#include <QAbstractListModel>
#include "myxymodel.h"

class LinesModel : public QAbstractListModel {
    Q_OBJECT
public:
    static const QString ITEM_NAME;     // LinesModel
    static const bool IS_QML_REG;
    enum LinesRole {
        LinesRoleBegin = Qt::UserRole,
        XyModel = LinesRoleBegin,

        LinesRoleEnd
    };
    Q_ENUM(LinesRole)
    static const std::array<QString, LinesRoleEnd - LinesRoleBegin> LINES_ROLE_STR;
    LinesModel(QObject *parent = nullptr);
    virtual ~LinesModel() = default;
    void appendLine(QString name = "defaultName");

    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override;
    bool insertRows(int row, int count, const QModelIndex &parent) override;

private:
    QList<MyXyModel*> _lines;
};


#pragma once

#include <QAbstractTableModel>
#include <QPointF>

class MyXyModel : public QAbstractTableModel {
    Q_OBJECT
    Q_PROPERTY(QString legenda READ legenda WRITE setLegenda NOTIFY legendaChanged)
public:
    MyXyModel(QObject *parent = nullptr);
    MyXyModel(QString legenda, QObject *parent = nullptr);
    virtual ~MyXyModel() = default;

    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE bool addPoint(QPointF p, int index = -1);
    Q_INVOKABLE bool addPoint(int x, int y, int index = -1);

    QString legenda() const;
    void setLegenda(const QString &legenda);
signals:
    void legendaChanged();

private:
    QString _legenda;
    QList<QPointF> _data;
};

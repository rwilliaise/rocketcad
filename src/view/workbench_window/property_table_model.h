
#pragma once

#include <rocketcad.h>

#include <QAbstractTableModel>

ROCKETCAD_NAMESPACE_BEGIN(View)

class PropertyTableModel : public QAbstractTableModel {
Q_OBJECT
public: 
    int rowCount(const QModelIndex &index = QModelIndex()) const override;
    int columnCount(const QModelIndex &index = QModelIndex()) const override;
    bool setData(const QModelIndex &index, const QVariant &variant, int role = Qt::EditRole) override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
};

ROCKETCAD_NAMESPACE_END(View)

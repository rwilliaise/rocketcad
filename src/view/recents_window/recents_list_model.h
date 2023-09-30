
#pragma once

#include <rocketcad.h>

#include <QAbstractListModel>

ROCKETCAD_NAMESPACE_BEGIN(View)

class RecentsListModel : public QAbstractListModel {
public:
    RecentsListModel(QObject *parent = nullptr) : QAbstractListModel(parent) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

};

ROCKETCAD_NAMESPACE_END(View)

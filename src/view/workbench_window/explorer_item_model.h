
#pragma once

#include "data/document.h"
#include <rocketcad.h>

#include <QAbstractItemModel>

ROCKETCAD_NAMESPACE_BEGIN(View)
    
class ExplorerItemModel : public QAbstractItemModel {
Q_OBJECT
public:
    ExplorerItemModel(Data::SharedDocument document, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


private: 
    Data::SharedDocument document;

};

ROCKETCAD_NAMESPACE_END(View)


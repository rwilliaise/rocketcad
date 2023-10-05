
#pragma once

#include <rocketcad.h>
#include <data/document.h>

#include <QAbstractItemModel>
#include <strings.h>

ROCKETCAD_NAMESPACE_BEGIN(View)
    
class ExplorerItemModel : public QAbstractItemModel {
Q_OBJECT
public:
    ExplorerItemModel(Data::SharedDocument document, QObject *parent = nullptr) : document(document), QAbstractItemModel(parent) {}
    
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private: 
    Data::RocketObject *getObject(const QModelIndex &index) const;
    Data::SharedDocument document;

};

ROCKETCAD_NAMESPACE_END(View)


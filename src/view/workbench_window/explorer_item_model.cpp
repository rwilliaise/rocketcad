
#include "explorer_item_model.h"
#include "rocketcad.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

Data::RocketObject *ExplorerItemModel::getObject(const QModelIndex &index) const {
    if (!index.isValid())
        return document.get(); // FIXME: this... sucks
    else
        return static_cast<Data::RocketObject *>(index.internalPointer());
}

int ExplorerItemModel::rowCount(const QModelIndex &parent) const {
    Data::RocketObject *parent_object = getObject(parent);
    return parent_object->getChildCount();
}

int ExplorerItemModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

QVariant ExplorerItemModel::data(const QModelIndex &index, int role) const {

}

QVariant ExplorerItemModel::headerData(int section, Qt::Orientation orientation, int role) const {

}

QModelIndex ExplorerItemModel::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    Data::RocketObject *parent_object = getObject(parent);
    Data::RocketObject *child_object = parent_object->getChild(row).get();
    if (!child_object)
        return QModelIndex();
    return createIndex(row, column, child_object);
}

QModelIndex ExplorerItemModel::parent(const QModelIndex &index) const {

}

Qt::ItemFlags ExplorerItemModel::flags(const QModelIndex &index) const {

}

ROCKETCAD_NAMESPACE_END(View)


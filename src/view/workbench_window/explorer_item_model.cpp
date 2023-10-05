
#include "explorer_item_model.h"
#include "rocketcad.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

Data::RocketObject *ExplorerItemModel::getObject(const QModelIndex &index) const {
    if (!index.isValid())
        return document.get();
    else
        return static_cast<Data::RocketObject *>(index.internalPointer());
}

int ExplorerItemModel::rowCount(const QModelIndex &parent) const {
    if (parent.column() > 0) return 0;
    Data::RocketObject *parent_object = getObject(parent);
    return parent_object->getChildCount();
}

int ExplorerItemModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

QVariant ExplorerItemModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return QVariant();
    Data::RocketObject *object = getObject(index);
    return QString(object->getName());
}

QVariant ExplorerItemModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) 
        return QString("Explorer");
    return QVariant();
}

QModelIndex ExplorerItemModel::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    Data::RocketObject *parent_object = getObject(parent);
    Data::RocketObject *child_object = parent_object->getChild(row).get();
    if (child_object == nullptr) return QModelIndex();
    return createIndex(row, column, child_object);
}

QModelIndex ExplorerItemModel::parent(const QModelIndex &index) const {
    if (!index.isValid()) return QModelIndex();
    Data::RocketObject *child_object = static_cast<Data::RocketObject *>(index.internalPointer());
    std::shared_ptr<Data::RocketObject> parent_object = child_object->getParent();

    // if (parent_object == document) return QModelIndex();
    return createIndex(parent_object->row(), 0, parent_object.get());
}

Qt::ItemFlags ExplorerItemModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) return Qt::NoItemFlags;
    return QAbstractItemModel::flags(index);
}

ROCKETCAD_NAMESPACE_END(View)


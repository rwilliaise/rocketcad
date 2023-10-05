
#include "property_table_model.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

int PropertyTableModel::rowCount(const QModelIndex &index) const {

}

int PropertyTableModel::columnCount(const QModelIndex &index) const {

}

bool PropertyTableModel::setData(const QModelIndex &index, const QVariant &variant, int role) {

}

QVariant PropertyTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();


}

QVariant PropertyTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Property");
        case 1:
            return tr("Value");
        default:
            break;
        }
    }
    return QVariant();
}

Qt::ItemFlags PropertyTableModel::flags(const QModelIndex &index) const {

}

ROCKETCAD_NAMESPACE_END(View)

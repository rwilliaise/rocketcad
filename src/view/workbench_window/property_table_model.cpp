
#include "property_table_model.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

int PropertyTableModel::rowCount(const QModelIndex &index) const {

}

int PropertyTableModel::columnCount(const QModelIndex &index) const {

}

bool PropertyTableModel::setData(const QModelIndex &index, const QVariant &variant, int role) {

}

QModelIndex PropertyTableModel::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent)) return QModelIndex();
}

QVariant PropertyTableModel::data(const QModelIndex &index, int role) const {

}

Qt::ItemFlags PropertyTableModel::flags(const QModelIndex &index) const {

}

ROCKETCAD_NAMESPACE_END(View)

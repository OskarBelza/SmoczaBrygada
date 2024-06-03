#include "shop.h"

Shop::Shop(QObject *parent) : QObject(parent) {}

void Shop::addItem(const Item &item) {
    items.append(item);
}

QVector<Item> Shop::getItems() const {
    return items;
}

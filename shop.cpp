#include "shop.h"

Shop::Shop(QObject *parent) : QObject(parent) {}

void Shop::addTool(const Tools &tool) {
    tools.append(tool);
}

QVector<Tools>& Shop::getTools() {
    return tools;
}

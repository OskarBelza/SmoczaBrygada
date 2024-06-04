#include "shop.h"

Shop::Shop(QObject *parent) : QObject(parent) {}

void Shop::addTool(const Tools &tool) {
    tools.append(tool);
}

QVector<Tools>& Shop::getTools() {
    return tools;
}

void Shop::removeTool(int index) {
    if (index >= 0 && index < tools.size()) {
        tools.removeAt(index);
    }
}

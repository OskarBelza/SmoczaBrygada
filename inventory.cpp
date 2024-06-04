#include "inventory.h"

Inventory::Inventory(QObject *parent) : QObject(parent) {}

void Inventory::addTool(const Tools& tool) {
    tools.append(tool);
    emit inventoryChanged();
}

Tools* Inventory::getTool(const QString& toolName) {
    for (auto& tool : tools) {
        if (tool.getName() == toolName) {
            return &tool;
        }
    }
    return nullptr;
}

QVector<Tools>& Inventory::getTools() {
    return tools;
}

QDataStream& operator<<(QDataStream& out, const Inventory& inventory) {
    out << inventory.tools;
    return out;
}

QDataStream& operator>>(QDataStream& in, Inventory& inventory) {
    in >> inventory.tools;
    return in;
}

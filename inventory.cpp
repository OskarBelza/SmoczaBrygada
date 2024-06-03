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
    return tools;  // Return a reference to the tools vector
}

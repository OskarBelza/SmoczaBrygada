#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QVector>
#include "tool.h"

class Inventory : public QObject {
    Q_OBJECT
public:
    explicit Inventory(QObject *parent = nullptr);

    void addTool(const Tools& tool);
    Tools* getTool(const QString& toolName);
    QVector<Tools>& getTools();  // Return a reference to the vector of tools

signals:
    void inventoryChanged();

private:
    QVector<Tools> tools;  // Use a normal QVector, not a reference
};

#endif // INVENTORY_H

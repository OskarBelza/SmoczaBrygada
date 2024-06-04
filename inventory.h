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
    QVector<Tools>& getTools();

signals:
    void inventoryChanged();

private:
    QVector<Tools> tools;
};

#endif // INVENTORY_H

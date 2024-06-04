#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QVector>
#include <QDataStream>
#include "tool.h"

class Inventory : public QObject {
    Q_OBJECT
public:
    Inventory(QObject *parent = nullptr);

    void addTool(const Tools& tool);
    Tools* getTool(const QString& toolName);
    QVector<Tools>& getTools();

    friend QDataStream& operator<<(QDataStream& out, const Inventory& inventory);
    friend QDataStream& operator>>(QDataStream& in, Inventory& inventory);

signals:
    void inventoryChanged();

private:
    QVector<Tools> tools;
};

#endif // INVENTORY_H

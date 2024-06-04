#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include <QVector>
#include "tool.h"

class Shop : public QObject {
    Q_OBJECT
public:
    explicit Shop(QObject *parent = nullptr);
    void addTool(const Tools &tool);
    QVector<Tools>& getTools();
    void removeTool(int index);


private:
    QVector<Tools> tools;
};

#endif // SHOP_H

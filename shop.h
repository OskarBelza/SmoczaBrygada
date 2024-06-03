#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include <QString>
#include <QVector>

class Item {
public:
    Item(const QString &name, const QString &description, double price)
        : name(name), description(description), price(price) {}

    QString getName() const { return name; }
    QString getDescription() const { return description; }
    double getPrice() const { return price; }

private:
    QString name;
    QString description;
    double price;
};

class Shop : public QObject {
    Q_OBJECT
public:
    explicit Shop(QObject *parent = nullptr);

    void addItem(const Item &item);
    QVector<Item> getItems() const;

private:
    QVector<Item> items;
};

#endif // SHOP_H

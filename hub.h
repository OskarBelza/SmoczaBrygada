#ifndef HUB_H
#define HUB_H

#include <QObject>
#include "hubwidget.h"
#include "firefighter.h"
#include "archive.h"
#include "shop.h"

class Hub : public QObject {
    Q_OBJECT
public:
    explicit Hub(HubWidget *hubWidget, Firefighter *firefighter, QObject *parent = nullptr);

signals:
    void startNextMission();
    void showCaptain();
    void showShopkeeper();
    void showArchivist();
    void showHub();

private slots:
    void onButtonClicked(const QString &buttonName);
    void onBookButtonClicked(int index);
    void onShopItemButtonClicked(int index);

private:
    void checkArchivistAccess();
    void createBookButtons();
    void createShopItemButtons();

    HubWidget *hubWidget;
    Firefighter *firefighter;
    Archive *archive;
    Shop *shop;
};

#endif // HUB_H

#ifndef HUB_H
#define HUB_H

#include <QObject>
#include "hubwidget.h"
#include "firefighter.h"

class Hub : public QObject {
    Q_OBJECT
public:
    explicit Hub(HubWidget *hubWidget, Firefighter *firefighter, QObject *parent = nullptr);

signals:
    void startNextMission();
    void showHub();
    void showShopkeeper();
    void showArchivist();
    void showArchives();

private slots:
    void onCaptainButtonClicked();
    void onShopkeeperButtonClicked();
    void onArchivistButtonClicked();
    void onNextMissionConfirmed();
    void onReturnToHub();
    void checkArchivistAccess();

private:
    HubWidget *hubWidget;
    Firefighter *firefighter;
};

#endif // HUB_H

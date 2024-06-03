#ifndef FIGHT_H
#define FIGHT_H

#include <QObject>
#include "firefighter.h"
#include "dragon.h"
#include "tool.h"

class Fight : public QObject {
    Q_OBJECT
public:
    explicit Fight(Firefighter* firefighter, Dragon* dragon, QObject *parent = nullptr);

    void start();

signals:
    void updateFightStatus(const QString& status);
    void fightEnded(bool won);
    void configureButton(int index, const QString& name, bool enabled, std::function<void()> onClick);

private:
    void handleTool(Tools* tool);
    void checkBattleOutcome();
    void connectButtonsForBattle();

    Firefighter* firefighter;
    Dragon* dragon;
};

#endif // FIGHT_H

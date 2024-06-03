#include "fight.h"

Fight::Fight(Firefighter* firefighter, Dragon* dragon, QObject *parent)
    : QObject(parent), firefighter(firefighter), dragon(dragon) {}

void Fight::start() {
    if (!firefighter || !dragon) {
        emit updateFightStatus("Error: Firefighter or Dragon is a nullptr!");
        return;
    }
    emit updateFightStatus("Rozpoczyna się walka! Wybierz broń:");
    connectButtonsForBattle();
}

void Fight::handleTool(Tools* tool) {
    if (!tool) {
        emit updateFightStatus("Wybrane narzędzie nie istnieje!");
        connectButtonsForBattle();
        return;
    }

    if (tool->use()) {
        dragon->takeDamage(tool->getFirePower());
        emit firefighter->getInventory()->inventoryChanged();  // Emit signal after using the tool
        checkBattleOutcome();
    } else {
        emit updateFightStatus(QString("Nie masz już %1!").arg(tool->getName()));
        connectButtonsForBattle();  // Reconnect buttons to allow another action
    }
}

void Fight::checkBattleOutcome() {
    if (firefighter->getHealth() <= 0) {
        emit updateFightStatus("Game Over! Zostałeś pokonany przez smoka.");
        emit fightEnded(false);
    } else if (dragon->getHealth() <= 0) {
        emit updateFightStatus("Pokonałeś smoka!");
        firefighter->addExperience(100);
        emit fightEnded(true);
    } else {
        QString status = QString("Smok nadal żyje! Zdrowie smoka: %1. Wybierz kolejną akcję:").arg(dragon->getHealth());
        firefighter->takeDamage(dragon->getFirePower());
        emit updateFightStatus(status);
        connectButtonsForBattle();
    }
}

void Fight::connectButtonsForBattle() {
    if (!firefighter || !firefighter->getInventory()) {
        emit updateFightStatus("Error: Firefighter or their inventory is a nullptr!");
        return;
    }

    auto& tools = firefighter->getInventory()->getTools();
    int buttonIndex = 0;

    for (int i = 0; i < tools.size(); ++i) {
        if (tools[i].isUsable()) {
            emit configureButton(buttonIndex, tools[i].getName(), true, [this, &tools, i] {
                if (i < 0 || i >= tools.size()) {
                    emit updateFightStatus("Error: Invalid tool index!");
                    return;
                }
                handleTool(&tools[i]);
            });
            buttonIndex++;
        }
    }

    // Deactivate remaining buttons if any
    for (; buttonIndex < 3; buttonIndex++) {
        emit configureButton(buttonIndex, "", false, nullptr);
    }
}

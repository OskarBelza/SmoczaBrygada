#ifndef HUBWIDGET_H
#define HUBWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include <QGridLayout>
#include <QMessageBox>
#include <QMap>
#include <QString>
#include "commonwidget.h"

class HubWidget : public QWidget {
    Q_OBJECT
public:
    explicit HubWidget(QWidget *parent = nullptr);

    void showCompletionMessage(const QString &message);
    void showConfirmationMessage(const QString &message);
    void showInsufficientLevelMessage(const QString &message);
    void showArchivistOptions();
    void showConfirmationButtons();
    void hideConfirmationButtons();
    void setButtonVisibility(const QString &buttonName, bool visible);
    void addBookButton(const QString &title, int index);
    void clearBookButtons();
    void addShopItemButton(const QString &name, int index);
    void clearShopItemButtons();
    void showMessageBox(const QString &title, const QString &content);

    void setHeroHealth(int health) { commonWidget->setHeroHealth(health); }
    void setHeroInventory(const QStringList &inventory) { commonWidget->setHeroInventory(inventory); }
    void setHeroGold(int gold) { commonWidget->setHeroGold(gold); }
    void setHeroExperience(int experience) { commonWidget->setHeroExperience(experience); }

signals:
    void buttonClicked(const QString &buttonName);
    void bookButtonClicked(int index);
    void shopItemButtonClicked(int index);

private:
    QLabel *messageLabel;
    QMap<QString, QPushButton*> buttons;
    QVector<QPushButton*> bookButtons;
    QVector<QPushButton*> shopItemButtons;
    QVBoxLayout *mainLayout;
    QGridLayout *bookLayout;
    QGridLayout *shopItemLayout;
    QSpacerItem *topSpacer;
    QSpacerItem *bottomSpacer;
    CommonWidget *commonWidget;

    void createButton(const QString &name, const QString &text);
};

#endif // HUBWIDGET_H

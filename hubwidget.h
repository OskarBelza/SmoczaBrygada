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
#include <QMouseEvent>
#include "commonwidget.h"

class ShopItemButton : public QPushButton {
    Q_OBJECT
public:
    explicit ShopItemButton(const QString &text, int index, QWidget *parent = nullptr)
        : QPushButton(text, parent), index(index) {}

signals:
    void rightClicked(int index);

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::RightButton) {
            emit rightClicked(index);
        } else {
            QPushButton::mousePressEvent(event);
        }
    }

private:
    int index;
};

class HubWidget : public QWidget {
    Q_OBJECT
public:
    explicit HubWidget(QWidget *parent = nullptr);
    ~HubWidget();

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
    void resetState();

    void setHeroHealth(int health) { commonWidget->setHeroHealth(health); }
    void setHeroInventory(const QStringList &inventory) { commonWidget->setHeroInventory(inventory); }

signals:
    void buttonClicked(const QString &buttonName);
    void bookButtonClicked(int index);
    void shopItemButtonClicked(int index);
    void shopItemRightClicked(int index);

private:
    QLabel *messageLabel;
    QMap<QString, QPushButton*> buttons;
    QVector<ShopItemButton*> bookButtons;
    QVector<ShopItemButton*> shopItemButtons;
    QVBoxLayout *mainLayout;
    QGridLayout *bookLayout;
    QGridLayout *shopItemLayout;
    QSpacerItem *topSpacer;
    QSpacerItem *bottomSpacer;
    CommonWidget *commonWidget;

    void createButton(const QString &name, const QString &text);
};

#endif // HUBWIDGET_H

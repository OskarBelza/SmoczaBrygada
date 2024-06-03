#ifndef HUBWIDGET_H
#define HUBWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

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
    void showReturnButton();
    void hideReturnButton();
    void hideMainButtons(); // Nowa metoda
    void showMainButtons(); // Nowa metoda
    void hideArchivesButton(); // Nowa metoda

signals:
    void captainButtonClicked();
    void shopkeeperButtonClicked();
    void archivistButtonClicked();
    void nextMissionConfirmed();
    void returnToHub();
    void showArchives();

private:
    QLabel *messageLabel;
    QPushButton *captainButton;
    QPushButton *shopkeeperButton;
    QPushButton *archivistButton;
    QPushButton *nextMissionButton;
    QPushButton *returnButton;
    QPushButton *showArchivesButton;
};

#endif // HUBWIDGET_H

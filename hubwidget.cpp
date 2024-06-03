#include "hubwidget.h"
#include <QVBoxLayout>
#include <QSpacerItem>

HubWidget::HubWidget(QWidget *parent) : QWidget(parent) {
    messageLabel = new QLabel(this);
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setFixedSize(500, 150);
    messageLabel->setWordWrap(true);
    messageLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

    mainLayout = new QVBoxLayout(this);
    topSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    mainLayout->addItem(topSpacer);
    mainLayout->addWidget(messageLabel, 0, Qt::AlignCenter);

    setLayout(mainLayout);

    bookLayout = new QGridLayout();
    bookLayout->setAlignment(Qt::AlignTop);
    mainLayout->insertLayout(1, bookLayout);

    shopItemLayout = new QGridLayout();
    shopItemLayout->setAlignment(Qt::AlignTop);
    mainLayout->insertLayout(1, shopItemLayout);

    messageLabel->hide();

    createButton("captainButton", "Kapitan Straży");
    createButton("shopkeeperButton", "Sklepikarz");
    createButton("archivistButton", "Archiwista");
    createButton("nextMissionButton", "Rozpocznij kolejną misję");
    createButton("returnButton", "Wróć");
    createButton("showArchivesButton", "Pokaż archiwum");

    buttons["nextMissionButton"]->hide();
    buttons["returnButton"]->hide();
    buttons["showArchivesButton"]->hide();
}

void HubWidget::createButton(const QString &name, const QString &text) {
    QPushButton *button = new QPushButton(text, this);
    button->setFixedSize(180, 50);
    buttons[name] = button;
    mainLayout->addWidget(button, 0, Qt::AlignCenter);
    connect(button, &QPushButton::clicked, [this, name]() {
        emit buttonClicked(name);
    });
}

void HubWidget::showCompletionMessage(const QString &message) {
    messageLabel->setText(message);
    messageLabel->show();
}

void HubWidget::showConfirmationMessage(const QString &message) {
    messageLabel->setText(message);
    messageLabel->show();
}

void HubWidget::showInsufficientLevelMessage(const QString &message) {
    messageLabel->setText(message);
    messageLabel->show();
    setButtonVisibility("returnButton", true);
    setButtonVisibility("showArchivesButton", false);
    setButtonVisibility("nextMissionButton", false);
}

void HubWidget::showArchivistOptions() {
    messageLabel->setText("Witam w archiwum");
    messageLabel->show();
    setButtonVisibility("returnButton", true);
    setButtonVisibility("showArchivesButton", true);
    setButtonVisibility("nextMissionButton", false);
}

void HubWidget::showConfirmationButtons() {
    setButtonVisibility("nextMissionButton", true);
    setButtonVisibility("returnButton", true);
    setButtonVisibility("captainButton", false);
    setButtonVisibility("shopkeeperButton", false);
    setButtonVisibility("archivistButton", false);
}

void HubWidget::hideConfirmationButtons() {
    setButtonVisibility("nextMissionButton", false);
    setButtonVisibility("returnButton", false);
    setButtonVisibility("captainButton", true);
    setButtonVisibility("shopkeeperButton", true);
    setButtonVisibility("archivistButton", true);
}

void HubWidget::setButtonVisibility(const QString &buttonName, bool visible) {
    if (buttons.contains(buttonName)) {
        buttons[buttonName]->setVisible(visible);
    }
}

void HubWidget::addBookButton(const QString &title, int index) {
    QPushButton *button = new QPushButton(title, this);
    messageLabel->setText("Wybierz książkę");
    button->setFixedSize(180, 50);

    int row = index / 3;
    int col = index % 3;

    bookLayout->addWidget(button, row, col, Qt::AlignTop | Qt::AlignCenter);
    bookLayout->setSpacing(10);
    bookButtons.append(button);
    connect(button, &QPushButton::clicked, [this, index]() {
        emit bookButtonClicked(index);
    });
}

void HubWidget::clearBookButtons() {
    for (auto button : bookButtons) {
        bookLayout->removeWidget(button);
        delete button;
    }
    bookButtons.clear();
}

void HubWidget::addShopItemButton(const QString &name, int index) {
    QPushButton *button = new QPushButton(name, this);
    messageLabel->setText("Wybierz przedmiot");
    button->setFixedSize(180, 50);

    int row = index / 3;
    int col = index % 3;

    shopItemLayout->addWidget(button, row, col, Qt::AlignTop | Qt::AlignCenter);
    shopItemLayout->setSpacing(10);
    shopItemButtons.append(button);
    connect(button, &QPushButton::clicked, [this, index]() {
        emit shopItemButtonClicked(index);
    });
}

void HubWidget::clearShopItemButtons() {
    for (auto button : shopItemButtons) {
        shopItemLayout->removeWidget(button);
        delete button;
    }
    shopItemButtons.clear();
}

void HubWidget::showMessageBox(const QString &title, const QString &content) {
    QMessageBox::information(this, title, content);
}

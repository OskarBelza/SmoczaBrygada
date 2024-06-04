#include "hubwidget.h"
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QMouseEvent>
#include <QDebug>

HubWidget::HubWidget(QWidget *parent) : QWidget(parent) {
    qDebug() << "Initializing HubWidget";

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

    commonWidget = new CommonWidget(this);
    mainLayout->insertWidget(0, commonWidget);
}

HubWidget::~HubWidget() {
    qDebug() << "Destroying HubWidget";
    clearBookButtons();
    clearShopItemButtons();
}

void HubWidget::resetState() {
    qDebug() << "Resetting HubWidget state";
    messageLabel->hide();
    setButtonVisibility("captainButton", true);
    setButtonVisibility("shopkeeperButton", true);
    setButtonVisibility("archivistButton", true);
    setButtonVisibility("nextMissionButton", false);
    setButtonVisibility("returnButton", false);
    setButtonVisibility("showArchivesButton", false);
    clearBookButtons();
    clearShopItemButtons();
}

void HubWidget::createButton(const QString &name, const QString &text) {
    qDebug() << "Creating button:" << name;
    QPushButton *button = new QPushButton(text, this);
    button->setFixedSize(180, 50);
    buttons[name] = button;
    mainLayout->addWidget(button, 0, Qt::AlignCenter);
    connect(button, &QPushButton::clicked, [this, name]() {
        emit buttonClicked(name);
    });
}

void HubWidget::showCompletionMessage(const QString &message) {
    qDebug() << "Showing completion message:" << message;
    messageLabel->setText(message);
    messageLabel->show();
}

void HubWidget::showConfirmationMessage(const QString &message) {
    qDebug() << "Showing confirmation message:" << message;
    messageLabel->setText(message);
    messageLabel->show();
}

void HubWidget::showInsufficientLevelMessage(const QString &message) {
    qDebug() << "Showing insufficient level message:" << message;
    messageLabel->setText(message);
    messageLabel->show();
    setButtonVisibility("returnButton", true);
    setButtonVisibility("showArchivesButton", false);
    setButtonVisibility("nextMissionButton", false);
}

void HubWidget::showArchivistOptions() {
    qDebug() << "Showing archivist options";
    messageLabel->setText("Witam w archiwum");
    messageLabel->show();
    setButtonVisibility("returnButton", true);
    setButtonVisibility("showArchivesButton", true);
    setButtonVisibility("nextMissionButton", false);
}

void HubWidget::showConfirmationButtons() {
    qDebug() << "Showing confirmation buttons";
    setButtonVisibility("nextMissionButton", true);
    setButtonVisibility("returnButton", true);
    setButtonVisibility("captainButton", false);
    setButtonVisibility("shopkeeperButton", false);
    setButtonVisibility("archivistButton", false);
}

void HubWidget::hideConfirmationButtons() {
    qDebug() << "Hiding confirmation buttons";
    setButtonVisibility("nextMissionButton", false);
    setButtonVisibility("returnButton", false);
    setButtonVisibility("captainButton", true);
    setButtonVisibility("shopkeeperButton", true);
    setButtonVisibility("archivistButton", true);
}

void HubWidget::setButtonVisibility(const QString &buttonName, bool visible) {
    qDebug() << "Setting button visibility:" << buttonName << "to" << visible;
    if (buttons.contains(buttonName)) {
        buttons[buttonName]->setVisible(visible);
    }
}

void HubWidget::addBookButton(const QString &title, int index) {
    qDebug() << "Adding book button:" << title << "at index:" << index;
    ShopItemButton *button = new ShopItemButton(title, index, this);
    messageLabel->setText("Wybierz książkę");
    button->setFixedSize(180, 50);

    int row = index / 3;
    int col = index % 3;

    bookLayout->addWidget(button, row, col, Qt::AlignTop | Qt::AlignCenter);
    bookLayout->setSpacing(10);
    bookButtons.append(button);
    connect(button, &ShopItemButton::clicked, [this, index]() {
        emit bookButtonClicked(index);
    });
}

void HubWidget::clearBookButtons() {
    qDebug() << "Clearing book buttons";
    for (auto button : bookButtons) {
        bookLayout->removeWidget(button);
        delete button;
    }
    bookButtons.clear();
}

void HubWidget::addShopItemButton(const QString &name, int index) {
    qDebug() << "Adding shop item button:" << name << "at index:" << index;
    ShopItemButton *button = new ShopItemButton(name, index, this);
    messageLabel->setText("Wybierz przedmiot");
    button->setFixedSize(180, 50);

    int row = index / 3;
    int col = index % 3;

    shopItemLayout->addWidget(button, row, col, Qt::AlignTop | Qt::AlignCenter);
    shopItemLayout->setSpacing(10);
    shopItemButtons.append(button);

    connect(button, &ShopItemButton::clicked, [this, index]() {
        emit shopItemButtonClicked(index);
    });

    connect(button, &ShopItemButton::rightClicked, [this, index]() {
        emit shopItemRightClicked(index);
    });
}

void HubWidget::clearShopItemButtons() {
    qDebug() << "Clearing shop item buttons";
    for (auto button : shopItemButtons) {
        shopItemLayout->removeWidget(button);
        delete button;
    }
    shopItemButtons.clear();
}

void HubWidget::showMessageBox(const QString &title, const QString &content) {
    qDebug() << "Showing message box:" << title << content;
    QMessageBox::information(this, title, content);
}

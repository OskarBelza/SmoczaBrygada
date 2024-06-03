#include "missionwidget.h"

MissionWidget::MissionWidget(QWidget *parent) : QWidget(parent) {
    missionDescriptionLabel = new QLabel(this);
    heroHealthLabel = new QLabel(this);
    heroInventoryButton = new QPushButton("Show Inventory", this);
    buttonLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout(this);

    // Ustawienia QLabel
    missionDescriptionLabel->setFixedSize(550, 200);
    missionDescriptionLabel->setAlignment(Qt::AlignCenter);
    missionDescriptionLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
    missionDescriptionLabel->setWordWrap(true); // Włączamy zawijanie tekstu

    heroHealthLabel->setFixedSize(450, 50);
    heroHealthLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    heroHealthLabel->setStyleSheet("font-size: 16px; color: red; font-weight: bold;");

    heroInventoryButton->setFixedSize(100, 40);

    connect(heroInventoryButton, &QPushButton::clicked, this, &MissionWidget::showInventory);

    for (int i = 0; i < 3; ++i) {
        buttons[i] = new QPushButton(this);
        buttons[i]->setFixedSize(180, 50);
        buttons[i]->hide();
        buttonLayout->addWidget(buttons[i]);
        connect(buttons[i], &QPushButton::clicked, this, [this, i]() { emit buttonClicked(i); });
    }

    setupLayout();
}

void MissionWidget::setMissionDescription(const QString &description) {
    missionDescriptionLabel->setText(description);
}

void MissionWidget::setHeroHealth(int health) {
    heroHealthLabel->setText("Health: " + QString::number(health));
}

void MissionWidget::setHeroInventory(const QStringList &inventory) {
    this->inventory = inventory;
}

void MissionWidget::configureButton(int buttonIndex, const QString &text, bool visible, const std::function<void()> &callback) {
    if (buttonIndex < 0 || buttonIndex >= 3) return;

    buttons[buttonIndex]->setText(text);
    buttons[buttonIndex]->setVisible(visible);

    disconnect(buttons[buttonIndex], &QPushButton::clicked, nullptr, nullptr);
    connect(buttons[buttonIndex], &QPushButton::clicked, this, [callback]() { callback(); });
}

QVBoxLayout* MissionWidget::getMainLayout() {
    return mainLayout; // Dodajemy metodę zwracającą główny layout
}

void MissionWidget::setupLayout() {
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(heroHealthLabel);
    topLayout->addWidget(heroInventoryButton);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(missionDescriptionLabel, 0, Qt::AlignCenter);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

void MissionWidget::showInventory() {
    QMessageBox::information(this, "Inventory", "Items: " + inventory.join(", "));
}

#include "commonwidget.h"

CommonWidget::CommonWidget(QWidget *parent) : QWidget(parent) {
    heroHealthLabel = new QLabel(this);
    heroGoldLabel = new QLabel(this);
    heroExperienceLabel = new QLabel(this);
    heroInventoryButton = new QPushButton("Show Inventory", this);

    heroHealthLabel->setFixedSize(120, 20);
    heroHealthLabel->setAlignment(Qt::AlignTop);
    heroHealthLabel->setStyleSheet("font-size: 16px; color: red; font-weight: bold;");

    heroGoldLabel->setFixedSize(120, 20);
    heroGoldLabel->setAlignment(Qt::AlignTop);
    heroGoldLabel->setStyleSheet("font-size: 16px; color: gold; font-weight: bold;");

    heroExperienceLabel->setFixedSize(120, 20);
    heroExperienceLabel->setAlignment(Qt::AlignTop);
    heroExperienceLabel->setStyleSheet("font-size: 16px; color: blue; font-weight: bold;");

    heroInventoryButton->setFixedSize(100, 30);

    connect(heroInventoryButton, &QPushButton::clicked, this, &CommonWidget::showInventory);

    // Tworzymy layout dla labeli, aby były rozmieszczone poziomo
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(heroHealthLabel);
    topLayout->addWidget(heroGoldLabel);
    topLayout->addWidget(heroExperienceLabel);
    topLayout->addWidget(heroInventoryButton);

    setLayout(topLayout);
}

void CommonWidget::setHeroHealth(int health) {
    heroHealthLabel->setText("Health: " + QString::number(health));
}

void CommonWidget::setHeroInventory(const QStringList &inventory) {
    this->inventory = inventory;
}

void CommonWidget::setHeroGold(int gold) {
    this->gold = gold;
    heroGoldLabel->setText("Gold: " + QString::number(gold));
}

void CommonWidget::setHeroExperience(int experience) {
    this->experience = experience;
    heroExperienceLabel->setText("Experience: " + QString::number(experience));
}

void CommonWidget::showInventory() {
    QMessageBox::information(this, "Inventory", "Items: " + inventory.join(", "));
}

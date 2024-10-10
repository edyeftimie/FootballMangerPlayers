//
// Created by eftim on 23.07.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PlayerDetailsWidget.h" resolved

#include <QDir>
#include <QFileDialog>
#include <utility>
#include <QMessageBox>
#include "PlayerDetailsWidget.h"
#include "ui_PlayerDetailsWidget.h"


PlayerDetailsWidget::PlayerDetailsWidget(std::shared_ptr<PlayerTableModel> tableModel, std::shared_ptr<Player> player) : tableModel(tableModel), player(player),
        QWidget(nullptr), ui(new Ui::PlayerDetailsWidget) {
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(player->getName()));

    ui->nameLineEdit->setText(QString::fromStdString(player->getName()));
    ui->overallRatingLineEdit->setText(QString::number(player->getOverallRating()));
    ui->ageLineEdit->setText(QString::number(player->getAge()));
    ui->nationalityLineEdit->setText(QString::fromStdString(player->getNationality()));
    ui->teamLineEdit->setText(QString::fromStdString(player->getTeam()->getName()));
    ui->positionLineEdit->setText(QString::fromStdString(player->getPosition()));
    ui->footLineEdit->setText(QString::fromStdString(player->getFoot()));

    std::cout << player->getName() << std::endl;
    QHash<QLineEdit*, std::pair<std::function<int()> , std::function<bool(int)>>> lineEdits = {
            {ui->overallAwarenessLineEdit, { [player]() { return player->getOverallAwareness();}, [player, tableModel](int value) { player->setOverallAwareness(value); return tableModel->updatePlayer(*player);}}},
            {ui->ballControlLineEdit, { [player] { return player->getBallControl(); }, [player, tableModel](int value) { player->setBallControl(value); return tableModel->updatePlayer(*player); }}},
            {ui->dribblingLineEdit, { [player] { return player->getDribbling(); }, [player, tableModel](int value) { player->setDribbling(value); return tableModel->updatePlayer(*player); }}},
            {ui->tightPossessionLineEdit, { [player] { return player->getTightPossession(); }, [player, tableModel](int value) { player->setTightPossession(value); return tableModel->updatePlayer(*player); }}},
            {ui->lowPassLineEdit, { [player] { return player->getLowPass(); }, [player, tableModel](int value) { player->setLowPass(value); return tableModel->updatePlayer(*player); }}},
            {ui->loftedPassLineEdit, { [player] { return player->getLoftedPass(); }, [player, tableModel](int value) { player->setLoftedPass(value); return tableModel->updatePlayer(*player); }}},
            {ui->finishingLineEdit, { [player] { return player->getFinishing(); }, [player, tableModel](int value) { player->setFinishing(value); return tableModel->updatePlayer(*player); }}},
            {ui->headingLineEdit, { [player] { return player->getHeading(); }, [player, tableModel](int value) { player->setHeading(value); return tableModel->updatePlayer(*player); }}},
            {ui->placeKickingLineEdit, { [player] { return player->getPlaceKicking(); }, [player, tableModel](int value) { player->setPlaceKicking(value); return tableModel->updatePlayer(*player); }}},
            {ui->curlLineEdit, { [player] { return player->getCurl(); }, [player, tableModel](int value) { player->setCurl(value); return tableModel->updatePlayer(*player); }}},
            {ui->speedLineEdit, { [player] { return player->getSpeed(); }, [player, tableModel](int value) { player->setSpeed(value); return tableModel->updatePlayer(*player); }}},
            {ui->accelerationLineEdit, { [player] { return player->getAcceleration(); }, [player, tableModel](int value) { player->setAcceleration(value); return tableModel->updatePlayer(*player); }}},
            {ui->balanceLineEdit, { [player] { return player->getBalance(); }, [player, tableModel](int value) { player->setBalance(value); return tableModel->updatePlayer(*player); }}},
            {ui->staminaLineEdit, { [player] { return player->getStamina(); }, [player, tableModel](int value) { player->setStamina(value); return tableModel->updatePlayer(*player); }}},
            {ui->defensiveAwarenessLineEdit, { [player] { return player->getDefensiveAwareness(); }, [player, tableModel](int value) { player->setDefensiveAwareness(value); return tableModel->updatePlayer(*player); }}},
            {ui->ballWinningLineEdit, { [player] { return player->getBallWinning(); }, [player, tableModel](int value) { player->setBallWinning(value); return tableModel->updatePlayer(*player); }}},
            {ui->aggressionLineEdit, { [player] { return player->getAggression(); }, [player, tableModel](int value) { player->setAggression(value); return tableModel->updatePlayer(*player); }}},
            {ui->physicalContactLineEdit, { [player] { return player->getPhysicalContact(); }, [player, tableModel](int value) { player->setPhysicalContact(value); return tableModel->updatePlayer(*player); }}},
            {ui->weekFootLineEdit, { [player] { return player->getWeekFoot(); }, [player, tableModel](int value) { player->setWeekFoot(value); return tableModel->updatePlayer(*player); }}},
            {ui->weekAccuracyLineEdit, { [player] { return player->getWeekAccuracy(); }, [player, tableModel](int value) { player->setWeekAccuracy(value); return tableModel->updatePlayer(*player); }}},
            {ui->formLineEdit, { [player] { return player->getForm(); }, [player, tableModel](int value) { player->setForm(value); return tableModel->updatePlayer(*player); }}},
            {ui->injuryResistanceLineEdit, { [player] { return player->getInjuryResistance(); }, [player, tableModel](int value) { player->setInjuryResistance(value); return tableModel->updatePlayer(*player); }}},
            {ui->kickingPowerLineEdit, { [player] { return player->getKickingPower(); }, [player, tableModel](int value) { player->setKickingPower(value); return tableModel->updatePlayer(*player); }}},
            {ui->jumpLineEdit, { [player] { return player->getJump(); }, [player, tableModel](int value) { player->setJump(value); return tableModel->updatePlayer(*player); }}},
            {ui->gkAwarenessLineEdit, { [player] { return player->getGkAwareness(); }, [player, tableModel](int value) { player->setGkAwareness(value); return tableModel->updatePlayer(*player); }}},
            {ui->gkCatchingLineEdit, { [player] { return player->getGkCatching(); }, [player, tableModel](int value) { player->setGkCatching(value); return tableModel->updatePlayer(*player); }}},
            {ui->gkClearingLineEdit, { [player] { return player->getGkClearing(); }, [player, tableModel](int value) { player->setGkClearing(value); return tableModel->updatePlayer(*player); }}},
            {ui->gkReflexesLineEdit, { [player] { return player->getGkReflexes(); }, [player, tableModel](int value) { player->setGkReflexes(value); return tableModel->updatePlayer(*player); }}},
            {ui->gkReachLineEdit, { [player] { return player->getGkReach(); }, [player, tableModel](int value) { player->setGkReach(value); return tableModel->updatePlayer(*player); }}}
    };

    for (auto it = lineEdits.begin(); it != lineEdits.end(); ++it) {
        it.key()->setText(QString::number(it.value().first()));
    }

    this->photoPath = "D:/University/FootballMangerPlayers/Photos/" + QString::fromStdString(player->getPhotograph());
    QPixmap photo(this->photoPath);
    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->scene()->addPixmap(photo);
    for (auto it = lineEdits.begin(); it != lineEdits.end(); ++it) {

        QLineEdit* line = it.key();
        std::function<bool(int)> setter = it.value().second;
        std::function<int()> getter = it.value().first;

        connect (line, &QLineEdit::editingFinished, this, [line, getter, setter, this] {
            updatePlayerAttribute(line, getter, setter);
        });
    }
}

void PlayerDetailsWidget::updatePlayerAttribute(QLineEdit *lineEdit, const std::function<int()>& getter , const std::function<bool(int)>& setter) {
    QString text = lineEdit->text();
    int oldValue = getter();
    int value = text.toInt();
    if (value != oldValue) {
        if (setter(value)) {
            QMessageBox::information(this, "Success", "Player updated!");
        } else {
            QMessageBox::warning(this, "Error", "Invalid value!");
            lineEdit->setText(QString::number(oldValue));
            setter(oldValue);
        }
    }
}

PlayerDetailsWidget::~PlayerDetailsWidget() {
    delete ui;
}

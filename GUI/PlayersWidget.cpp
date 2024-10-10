//
// Created by eftim on 23.07.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PlayersWidget.h" resolved

#include <QMessageBox>
#include "PlayersWidget.h"
#include "ui_PlayersWidget.h"

#include "PlayerDetailsWidget.h"
#include <QAbstractItemView>
#include <QSortFilterProxyModel>


PlayersWidget::PlayersWidget(const std::shared_ptr<PlayerTableModel>& playerTableModel, const std::shared_ptr<TeamTableModel>& teamTableModel) : playerTableModel(playerTableModel), teamTableModel(teamTableModel),
        QWidget(nullptr), ui(new Ui::PlayersWidget) {
    ui->setupUi(this);

    ui->playersTableView->setModel(playerTableModel.get());
    ui->playersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    proxyModel = std::make_shared<QSortFilterProxyModel>();
    proxyModel->setSourceModel(teamTableModel.get());

    ui->teamsTableView->setModel(proxyModel.get());
    ui->teamsTableView->setColumnHidden(2, true);
    ui->teamsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->setWindowTitle("Players management");

    QObject::connect(ui->playersTableView, &QTableView::clicked, this, &PlayersWidget::rowClicked);
    QObject::connect(ui->teamsTableView, &QTableView::clicked, this, &PlayersWidget::rowClickedTeam);
    QObject::connect(ui->addPlayerButton, &QPushButton::clicked, this, &PlayersWidget::addPlayer);
    QObject::connect(ui->searchTeamPushButton, &QPushButton::clicked, this, &PlayersWidget::searchTeamsFromCountryButtonClicked);
}

PlayersWidget::~PlayersWidget() {
    delete ui;
}

void PlayersWidget::rowClicked(const QModelIndex &index) {
    auto player = this->playerTableModel->getPlayers()[index.row()];
    auto playerDetailsWidget = new PlayerDetailsWidget(this->playerTableModel, player);
    playerDetailsWidget->show();
}

const std::string NATIONALITY = "Armenia Ireland NorthernIreland Scotland England Wales Iceland Norway Sweden Finland Denmark Netherland Belgium Germany France Switzerland CzechRepublic Austria Slovakia Slovenia Croatia Hungary Poland Lithuania Latvia Estonia Belarus Ukraine Moldova Romania Bulgaria Serbia Montenegro BosniaandHerzegovina NorthMacedonia Albania Greece Cyprus Turkey Italy Malta Spain Portugal Russia Georgia Azerbaijan Israel China SaudiArabia Qatar Brazil Argentina Mexico USA Australia";
const std::string FOOT = "left right both";
const std::string POSITION = "GK CB LB RB CDM CM LM RM LW RW CAM CF ST";

void PlayersWidget::addPlayer() {
    std::string name = ui->nameLineEdit->text().toStdString();
    if (name.empty()) {
        QMessageBox::critical(this, "Error", "Name cannot be empty!");
        return;
    }
    for (auto &player : this->playerTableModel->getPlayers()) {
        if (player->getName() == name) {
            QMessageBox::critical(this, "Error", "Player already exists!");
            return;
        }
    }

    std::string teamName = ui->teamLineEdit->text().toStdString();
    if (teamName.empty()) {
        QMessageBox::critical(this, "Error", "Team cannot be empty!");
        return;
    }
    bool teamExists = false;
    for (auto &team : this->playerTableModel->getTeams()) {
        if (team->getName() == teamName) {
            teamExists = true;
            break;
        }
    }
    if (!teamExists) {
        QMessageBox::critical(this, "Error", "Team does not exist!");
        return;
    }

    std::string age = ui->ageLineEdit->text().toStdString();
    if (age.empty()) {
        QMessageBox::critical(this, "Error", "Age cannot be empty!");
        return;
    } else if (std::stoi(age) < 16 || std::stoi(age) > 40) {
        QMessageBox::critical(this, "Error", "Age must be between 16 and 40!");
        return;
    }

    std::string nationality = ui->nationalityLineEdit->text().toStdString();
    if (nationality.empty()) {
        QMessageBox::critical(this, "Error", "Nationality cannot be empty!");
        return;
    }
    else if (NATIONALITY.find(nationality) == std::string::npos) {
        std::cout << "Nationality check" << std::endl;
        QMessageBox::critical(this, "Error", "Nationality must be a valid country!");
        std::cout << "Nationality checked" << std::endl;
        return;
    }

    std::string position = ui->positionLineEdit->text().toStdString();
    if (position.empty()) {
        QMessageBox::critical(this, "Error", "Position cannot be empty!");
        return;
    }
    else if (POSITION.find(position) == std::string::npos) {
        std::cout << "Position check" << std::endl;
        QMessageBox::critical(this, "Error", "Position must be a valid position!");
        std::cout << "Position checked" << std::endl;
        return;
    }

    std::string foot = ui->footLineEdit->text().toStdString();
    if (foot.empty()) {
        QMessageBox::critical(this, "Error", "Foot cannot be empty!");
        return;
    }
    else if (FOOT.find(foot) == std::string::npos) {
        std::cout << "Foot check" << std::endl;
        QMessageBox::critical(this, "Error", "Foot must be a valid foot!");
        std::cout << "Foot checked" << std::endl;
        return;
    }

    std::string overallRating = ui->overallRatingLineEdit->text().toStdString();
    if (overallRating.empty()) {
        QMessageBox::critical(this, "Error", "Overall Rating cannot be empty!");
        return;
    } else if (std::stoi(overallRating) < 40 || std::stoi(overallRating) >= 100) {
        QMessageBox::critical(this, "Error", "Overall Rating must be between 40 and 100!");
        return;
    }

    std::string photograph = ui->photographLineEdit->text().toStdString();
    if (photograph.empty()) {
        QMessageBox::critical(this, "Error", "Photograph cannot be empty!");
        return;
    }

    Team* team = this->playerTableModel->getTeamByName(teamName);
    this->playerTableModel->addPlayer(std::stoi(overallRating), name, nationality, team, position, std::stoi(age), foot, photograph);

    ui->nameLineEdit->clear();
    ui->teamLineEdit->clear();
    ui->ageLineEdit->clear();
    ui->nationalityLineEdit->clear();
    ui->positionLineEdit->clear();
    ui->footLineEdit->clear();
    ui->overallRatingLineEdit->clear();
    ui->photographLineEdit->clear();
}

void PlayersWidget::searchTeamsFromCountryButtonClicked() {
    std::string country = ui->searchTeamLineEdit->text().toStdString();
    if (country.empty()) {
        proxyModel->setFilterRegularExpression(QRegularExpression(""));
        ui->teamsTableView->setModel(proxyModel.get());
        return;
    }

    proxyModel->setFilterKeyColumn(2);
    proxyModel->setFilterRegularExpression(QRegularExpression(country.c_str(), QRegularExpression::CaseInsensitiveOption));
    if (proxyModel->rowCount() == 0) {
        QMessageBox::critical(this, "Error", "No teams found!");
        proxyModel->setFilterRegularExpression(QRegularExpression(""));
    } else {
        ui->teamsTableView->setModel(proxyModel.get());
    }
}

void PlayersWidget::rowClickedTeam(const QModelIndex &index) {
    auto item = this->proxyModel->index(index.row(), 0);
    for (auto &team : this->playerTableModel->getTeams()) {
        if (team->getName() == item.data().toString().toStdString()) {
            ui->teamLineEdit->setText(QString::fromStdString(team->getName()));
            break;
        }
    }
}
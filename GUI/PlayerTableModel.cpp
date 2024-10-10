//
// Created by eftim on 22.07.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TableModel.h" resolved

#include <QMessageBox>
#include "PlayerTableModel.h"


PlayerTableModel::PlayerTableModel(std::shared_ptr<Service> _service) : service(std::move(_service)) {
}

PlayerTableModel::~PlayerTableModel() {
}

int PlayerTableModel::rowCount(const QModelIndex &parent) const {
    return this->service->getPlayers().size();
}

int PlayerTableModel::columnCount(const QModelIndex &parent) const {
    return 7;
}

QVariant PlayerTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        std::vector<std::shared_ptr<Player>> players = this->service->getPlayers();
        if (index.column() == 0) {
            return QString::fromStdString(players[index.row()]->getName());
        }
        if (index.column() == 1) {
            return QString::fromStdString(players[index.row()]->getNationality());
        }
        if (index.column() == 2) {
            return QString::fromStdString(players[index.row()]->getTeam()->getName());
        }
        if (index.column() == 3) {
            return QString::fromStdString(players[index.row()]->getPosition());
        }
        if (index.column() == 4) {
            return players[index.row()]->getOverallRating();
        }
        if (index.column() == 5) {
            return players[index.row()]->getAge();
        }
        if (index.column() == 6) {
            return QString::fromStdString(players[index.row()]->getFoot());
        }
    }
    return QVariant();
}

QVariant PlayerTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            if (section == 0) {
                return "Name";
            }
            if (section == 1) {
                return "Nationality";
            }
            if (section == 2) {
                return "Team";
            }
            if (section == 3) {
                return "Position";
            }
            if (section == 4) {
                return "Overall Rating";
            }
            if (section == 5) {
                return "Age";
            }
            if (section == 6) {
                return "Foot";
            }
        }
    }
    return QVariant();
}

void PlayerTableModel::addPlayer(int overallRating, std::string name, std::string nationality, Team* team, std::string position, int age, std::string foot, std::string photograph) {
    if (this->service->addPlayer(overallRating, std::move(name), std::move(nationality), team, std::move(position), age, std::move(foot), std::move(photograph))) {
        beginInsertRows(QModelIndex(), this->service->getPlayers().size(), this->service->getPlayers().size());
        endInsertRows();
    } else {
        QMessageBox::critical(nullptr, "Error", "Player already exists!");
    }
    emit layoutChanged();
}

std::vector<std::shared_ptr<Player>> PlayerTableModel::getPlayers() {
    return this->service->getPlayers();
}

std::vector<std::shared_ptr<Team>> PlayerTableModel::getTeams() {
    return this->service->getTeams();
}

Player* PlayerTableModel::getPlayer(int row) {
    return this->service->getPlayers()[row].get();
}

bool PlayerTableModel::updatePlayer(Player player) {
    if (this->service->updatePlayer(std::move(player))) {
        beginInsertRows(QModelIndex(), this->service->getPlayers().size(), this->service->getPlayers().size());
        endInsertRows();
        return true;
//        emit layoutChanged();
    } else {
        QMessageBox::critical(nullptr, "Error", "Invalid value!");
        return false;
    }
}

Team* PlayerTableModel::getTeamByName(std::string name) {
    return this->service->getTeamByName(name);
}

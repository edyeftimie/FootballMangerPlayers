//
// Created by eftim on 19.09.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TeamsTableModel.h" resolved

#include "TeamTableModel.h"

TeamTableModel::TeamTableModel(std::shared_ptr<Service> _service) : service(std::move(_service)) {
}

TeamTableModel::~TeamTableModel() {
}

int TeamTableModel::rowCount(const QModelIndex &parent) const {
    return this->service->getTeams().size();
}

int TeamTableModel::columnCount(const QModelIndex &parent) const {
    return 3;
}

QVariant TeamTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        std::vector<std::shared_ptr<Team>> teams = this->service->getTeams();
        if (index.column() == 0) {
            return QString::fromStdString(teams[index.row()]->getName());
        }
        if (index.column() == 1) {
            return QString::fromStdString(teams[index.row()]->getLeague());
        }
        if (index.column() == 2) {
            return QString::fromStdString(teams[index.row()]->getCountry());
        }
    }
    return {};
}

QVariant TeamTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            if (section == 0) {
                return "Name";
            }
            if (section == 1) {
                return "League";
            }
            if (section == 2) {
                return "Country";
            }
        }
    }
    return QVariant();
}

std::vector<std::shared_ptr<Team>> TeamTableModel::getTeams() {
    return this->service->getTeams();
}

Team* TeamTableModel::getTeam(int row) {
    return this->service->getTeams()[row].get();
}
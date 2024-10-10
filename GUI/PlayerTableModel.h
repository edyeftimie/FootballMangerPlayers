//
// Created by eftim on 22.07.2024.
//

#ifndef FOOTBALLMANGERPLAYERS_PLAYERTABLEMODEL_H
#define FOOTBALLMANGERPLAYERS_PLAYERTABLEMODEL_H

#include <QAbstractTableModel>

#include "../Service/Service.h"
#include "../Domain/Player.h"

class PlayerTableModel : public QAbstractTableModel {

public:
    explicit PlayerTableModel(std::shared_ptr<Service> _service);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void addPlayer(int, std::string, std::string, Team* team, std::string, int, std::string, std::string);
    bool updatePlayer(Player player);
    std::vector<std::shared_ptr<Player>> getPlayers();
    std::vector<std::shared_ptr<Team>> getTeams();
    Team* getTeamByName(std::string name);
    Player* getPlayer(int row);

    ~PlayerTableModel() override;

public slots:
    void rowClicked(const QModelIndex &index);

private:
    std::shared_ptr<Service> service;

};


#endif //FOOTBALLMANGERPLAYERS_PLAYERTABLEMODEL_H

//
// Created by eftim on 19.09.2024.
//

#ifndef FOOTBALLMANGERPLAYERS_TEAMTABLEMODEL_H
#define FOOTBALLMANGERPLAYERS_TEAMTABLEMODEL_H

#include <QAbstractTableModel>

#include "../Service/Service.h"
#include "../Domain/Team.h"

class TeamTableModel : public QAbstractTableModel {

public:
    explicit TeamTableModel(std::shared_ptr<Service> _service);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    std::vector<std::shared_ptr<Team>> getTeams();
    Team* getTeam(int row);
    ~TeamTableModel() override;

public slots:
    void rowClicked(const QModelIndex &index);
private:
    std::shared_ptr<Service> service;
};


#endif //FOOTBALLMANGERPLAYERS_TEAMTABLEMODEL_H

//
// Created by eftim on 23.07.2024.
//

#ifndef FOOTBALLMANGERPLAYERS_PLAYERSWIDGET_H
#define FOOTBALLMANGERPLAYERS_PLAYERSWIDGET_H

#include <QWidget>
#include <QSortFilterProxyModel>

#include "PlayerTableModel.h"
#include "TeamTableModel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class PlayersWidget; }
QT_END_NAMESPACE

class PlayersWidget : public QWidget {
Q_OBJECT

public:
    explicit PlayersWidget(const std::shared_ptr<PlayerTableModel>& playerTableModel, const std::shared_ptr<TeamTableModel>& teamTableModel);

    ~PlayersWidget() override;

private:
    Ui::PlayersWidget *ui;
    std::shared_ptr<PlayerTableModel> playerTableModel;
    std::shared_ptr<TeamTableModel> teamTableModel;
    std::shared_ptr<QSortFilterProxyModel> proxyModel;

    void rowClicked(const QModelIndex &index);
    void addPlayer();

    void searchTeamsFromCountryButtonClicked();
    void rowClickedTeam(const QModelIndex &index);
};


#endif //FOOTBALLMANGERPLAYERS_PLAYERSWIDGET_H

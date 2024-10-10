//
// Created by eftim on 23.07.2024.
//

#ifndef FOOTBALLMANGERPLAYERS_PLAYERDETAILSWIDGET_H
#define FOOTBALLMANGERPLAYERS_PLAYERDETAILSWIDGET_H

#include <QWidget>
#include <QLineEdit>

#include "PlayerTableModel.h"
#include "../Domain/Player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PlayerDetailsWidget; }
QT_END_NAMESPACE

class PlayerDetailsWidget : public QWidget {
Q_OBJECT

public:
    explicit PlayerDetailsWidget(std::shared_ptr<PlayerTableModel> tableModel, std::shared_ptr<Player> player);

    ~PlayerDetailsWidget() override;
//public slots:

private:
    Ui::PlayerDetailsWidget *ui;
    std::shared_ptr<PlayerTableModel> tableModel;
    std::shared_ptr<Player> player;
    QString photoPath;

//    void updatePlayerAttribute(QLineEdit *lineEdit, const std::function<bool(int)>& setter);
    void updatePlayerAttribute(QLineEdit *lineEdit, const std::function<int()>& getter , const std::function<bool(int)>& setter);

};


#endif //FOOTBALLMANGERPLAYERS_PLAYERDETAILSWIDGET_H

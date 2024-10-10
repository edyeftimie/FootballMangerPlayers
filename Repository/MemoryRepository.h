//
// Created by eftim on 21.07.2024.
//

#ifndef FOOTBALLMANGERPLAYERS_MEMORYREPOSITORY_H
#define FOOTBALLMANGERPLAYERS_MEMORYREPOSITORY_H

#include <memory>
#include <vector>

#include "../Domain/Team.h"
#include "../Domain/Player.h"

class MemoryRepository {
    private:
        std::vector<std::shared_ptr<Player>> players;
        std::vector<std::shared_ptr<Team>> teams;
    public:
        MemoryRepository();
        ~MemoryRepository();

        virtual bool addPlayer(std::shared_ptr<Player> player);
        virtual bool addTeam(std::shared_ptr<Team> team);

        virtual bool updatePlayer(Player player);

        virtual std::vector<std::shared_ptr<Player>> getPlayers();
        virtual std::vector<std::shared_ptr<Team>> getTeams();
};


#endif //FOOTBALLMANGERPLAYERS_MEMORYREPOSITORY_H

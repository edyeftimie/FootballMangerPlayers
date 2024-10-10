//
// Created by eftim on 22.07.2024.
//

#ifndef FOOTBALLMANGERPLAYERS_SERVICE_H
#define FOOTBALLMANGERPLAYERS_SERVICE_H

#include "../Repository/MemoryRepository.h"

class Service {
    private:
        std::shared_ptr<MemoryRepository> repository;
    public:
        Service(std::shared_ptr<MemoryRepository> _repository);
        ~Service();

        bool addPlayer(int, std::string, std::string, Team* team, std::string, int, std::string, std::string);
        bool addTeam(std::string name, std::string country, std::string league);
        bool updatePlayer(Player player);

        std::vector<std::shared_ptr<Player>> getPlayers();
        std::vector<std::shared_ptr<Team>> getTeams();

        std::vector<std::shared_ptr<Player>> getTopPlayersSimilarStats(Player* player);
        Player* getPlayerByName(std::string name);
        Team* getTeamByName(std::string name);

        std::vector<std::shared_ptr<Player>> getPlayersByTeam(std::string team);
};


#endif //FOOTBALLMANGERPLAYERS_SERVICE_H

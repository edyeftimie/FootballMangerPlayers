//
// Created by eftim on 21.07.2024.
//

#ifndef FOOTBALLMANGERPLAYERS_FILEREPOSITORY_H
#define FOOTBALLMANGERPLAYERS_FILEREPOSITORY_H

#include "MemoryRepository.h"

class FileRepository : public MemoryRepository {
    private:
        std::string playersFile;
        std::string teamsFile;
        void loadFromFile();
        void saveToFile();
    public:
        FileRepository(std::string _playersFile, std::string _teamsFile);
        ~FileRepository();

        bool addPlayer(std::shared_ptr<Player> player) override;
        bool addTeam(std::shared_ptr<Team> team) override;

        bool updatePlayer(Player player) override;

        std::vector<std::shared_ptr<Player>> getPlayers() override;
        std::vector<std::shared_ptr<Team>> getTeams() override;

};


#endif //FOOTBALLMANGERPLAYERS_FILEREPOSITORY_H

//
// Created by eftim on 20.07.2024.
//

#ifndef FOOTBALLMANGERPLAYERS_TEAM_H
#define FOOTBALLMANGERPLAYERS_TEAM_H
#include <iostream>
#include <cstring>

class Team {
private:
    std::string name; //the name of the team club
    std::string country; //the country where the team plays
    std::string league; //the league in which the team is registered
public:
    Team(std::string _name, std::string _country, std::string _league);
    ~Team();

    std::string getName();
    std::string getCountry();
    std::string getLeague();
};

#endif //FOOTBALLMANGERPLAYERS_TEAM_H
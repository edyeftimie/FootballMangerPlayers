//
// Created by eftim on 20.07.2024.
//

#include "Team.h"

#include <utility>

Team::Team(std::string _name, std::string _country, std::string _league) :
    name(std::move(_name)), country(std::move(_country)), league(std::move(_league)) {}

Team::~Team() = default;

std::string Team::getName() {
    return this->name;
}

std::string Team::getCountry() {
    return this->country;
}

std::string Team::getLeague() {
    return this->league;
}
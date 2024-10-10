//
// Created by eftim on 22.07.2024.
//

#include "Service.h"

#include <utility>

Service::Service(std::shared_ptr<MemoryRepository> _repository) : repository(std::move(_repository)) {}

Service::~Service() = default;

bool Service::addPlayer(int overallRating, std::string name, std::string nationality, Team* team, std::string position, int age, std::string foot, std::string photograph) {
    return repository->addPlayer(std::make_shared<Player>(overallRating, std::move(name), std::move(nationality), team, std::move(position), age, std::move(foot), std::move(photograph)));
}

bool Service::addTeam(std::string name, std::string country, std::string league) {
    return repository->addTeam(std::make_shared<Team>(std::move(name), std::move(country), std::move(league)));
}

bool Service::updatePlayer(Player player) {
    return repository->updatePlayer(std::move(player));
}

std::vector<std::shared_ptr<Player>> Service::getPlayers() {
    return repository->getPlayers();
}

std::vector<std::shared_ptr<Team>> Service::getTeams() {
    return repository->getTeams();
}

std::vector<std::shared_ptr<Player>> Service::getTopPlayersSimilarStats(Player* player) {
    std::vector<std::shared_ptr<Player>> players = repository->getPlayers();
    std::vector<std::shared_ptr<Player>> topPlayers;
    for (auto &p : players) {
        if ((p->getOverallRating() <= player->getOverallRating()+2 || p->getOverallRating() > player->getOverallRating()-2 ) && p->getPosition() == player->getPosition() ) {
            topPlayers.push_back(p);
        }
    }
    return topPlayers;
}

Player* Service::getPlayerByName(std::string name) {
    std::vector<std::shared_ptr<Player>> players = repository->getPlayers();
    for (auto &p : players) {
        if (p->getName() == name) {
            return p.get();
        }
    }
    return nullptr;
}

Team* Service::getTeamByName(std::string name) {
    std::vector<std::shared_ptr<Team>> teams = repository->getTeams();
    for (auto &t : teams) {
        if (t->getName() == name) {
            return t.get();
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Player>> Service::getPlayersByTeam(std::string team) {
    std::vector<std::shared_ptr<Player>> players = repository->getPlayers();
    std::vector<std::shared_ptr<Player>> teamPlayers;
    for (auto &p : players) {
        if (p->getTeam()->getName() == team) {
            teamPlayers.push_back(p);
        }
    }
    return teamPlayers;
}
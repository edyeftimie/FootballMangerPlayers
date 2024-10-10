//
// Created by eftim on 21.07.2024.
//

#include "MemoryRepository.h"

MemoryRepository::MemoryRepository() = default;

MemoryRepository::~MemoryRepository() {
    players.clear();
    teams.clear();
}

bool MemoryRepository::addPlayer(std::shared_ptr<Player> player) {
    for (auto &p : players) {
        if (p->getName() == player->getName()) {
            return false;
        }
    }
    players.push_back(player);
    return true;
}

bool MemoryRepository::addTeam(std::shared_ptr<Team> team) {
    for (auto &t : teams) {
        if (t->getName() == team->getName()) {
            return false;
        }
    }
    teams.push_back(team);
    return true;
}

bool MemoryRepository::updatePlayer(Player player) {
    if (players.empty()) {
        return false;
    }
    if (player.getOverallAwareness() < 40 || player.getOverallAwareness() > 99 ||
        player.getBallControl() < 40 || player.getBallControl() > 99 ||
        player.getDribbling() < 40 || player.getDribbling() > 99 ||
        player.getTightPossession() < 40 || player.getTightPossession() > 99 ||
        player.getLowPass() < 40 || player.getLowPass() > 99 ||
        player.getLoftedPass() < 40 || player.getLoftedPass() > 99 ||
        player.getFinishing() < 40 || player.getFinishing() > 99 ||
        player.getHeading() < 40 || player.getHeading() > 99 ||
        player.getPlaceKicking() < 40 || player.getPlaceKicking() > 99 ||
        player.getCurl() < 40 || player.getCurl() > 99 ||
        player.getSpeed() < 40 || player.getSpeed() > 99 ||
        player.getAcceleration() < 40 || player.getAcceleration() > 99 ||
        player.getKickingPower() < 40 || player.getKickingPower() > 99 ||
        player.getJump() < 40 || player.getJump() > 99 ||
        player.getPhysicalContact() < 40 || player.getPhysicalContact() > 99 ||
        player.getBalance() < 40 || player.getBalance() > 99 ||
        player.getStamina() < 40 || player.getStamina() > 99 ||
        player.getDefensiveAwareness() < 40 || player.getDefensiveAwareness() > 99 ||
        player.getBallWinning() < 40 || player.getBallWinning() > 99 ||
        player.getAggression() < 40 || player.getAggression() > 99 ||
        player.getGkAwareness() < 40 || player.getGkAwareness() > 99 ||
        player.getGkCatching() < 40 || player.getGkCatching() > 99 ||
        player.getGkClearing() < 40 || player.getGkClearing() > 99 ||
        player.getGkReflexes() < 40 || player.getGkReflexes() > 99 ||
        player.getGkReach() < 40 || player.getGkReach() > 99 ||
        player.getWeekFoot() < 1 || player.getWeekFoot() > 4 ||
        player.getWeekAccuracy() < 1 || player.getWeekAccuracy() > 4 ||
        player.getForm() < 1 || player.getForm() > 8 ||
        player.getInjuryResistance() < 1 || player.getInjuryResistance() > 3) {
        return false;
    }
    for (auto &p : players) {
        if (p->getName() == player.getName()) {
            p->setOverallAwareness(player.getOverallAwareness());
            p->setBallControl(player.getBallControl());
            p->setDribbling(player.getDribbling());
            p->setTightPossession(player.getTightPossession());
            p->setLowPass(player.getLowPass());
            p->setLoftedPass(player.getLoftedPass());
            p->setFinishing(player.getFinishing());
            p->setHeading(player.getHeading());
            p->setPlaceKicking(player.getPlaceKicking());
            p->setCurl(player.getCurl());
            p->setSpeed(player.getSpeed());
            p->setAcceleration(player.getAcceleration());
            p->setKickingPower(player.getKickingPower());
            p->setJump(player.getJump());
            p->setPhysicalContact(player.getPhysicalContact());
            p->setBalance(player.getBalance());
            p->setStamina(player.getStamina());
            p->setDefensiveAwareness(player.getDefensiveAwareness());
            p->setBallWinning(player.getBallWinning());
            p->setAggression(player.getAggression());
            p->setGkAwareness(player.getGkAwareness());
            p->setGkCatching(player.getGkCatching());
            p->setGkClearing(player.getGkClearing());
            p->setGkReflexes(player.getGkReflexes());
            p->setGkReach(player.getGkReach());
            p->setWeekFoot(player.getWeekFoot());
            p->setWeekAccuracy(player.getWeekAccuracy());
            p->setForm(player.getForm());
            p->setInjuryResistance(player.getInjuryResistance());
            return true;
        }
    }
    return false;
}

std::vector<std::shared_ptr<Player>> MemoryRepository::getPlayers() {
    return players;
}

std::vector<std::shared_ptr<Team>> MemoryRepository::getTeams() {
    return teams;
}

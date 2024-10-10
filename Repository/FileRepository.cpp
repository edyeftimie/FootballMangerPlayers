//
// Created by eftim on 21.07.2024.
//

#include "FileRepository.h"

#include <fstream>
#include <utility>

FileRepository::FileRepository(std::string _playersFile, std::string _teamsFile) :
    playersFile(std::move(_playersFile)), teamsFile(std::move(_teamsFile)) {
    loadFromFile();
}

FileRepository::~FileRepository() {
    saveToFile();
}

bool FileRepository::addPlayer(std::shared_ptr<Player> player) {
    if (MemoryRepository::addPlayer(player)) {
        saveToFile();
        return true;
    }
    return false;
}

bool FileRepository::addTeam(std::shared_ptr<Team> team) {
    if (MemoryRepository::addTeam(team)) {
        saveToFile();
        return true;
    }
    return false;
}

bool FileRepository::updatePlayer(Player player) {
    if (MemoryRepository::updatePlayer(player)) {
        saveToFile();
        return true;
    }
    return false;
}

std::vector<std::shared_ptr<Player>> FileRepository::getPlayers() {
    return MemoryRepository::getPlayers();
}

std::vector<std::shared_ptr<Team>> FileRepository::getTeams() {
    return MemoryRepository::getTeams();
}

void FileRepository::loadFromFile() {
    std::ifstream playersIn(playersFile);
    std::ifstream teamsIn(teamsFile);

    if (!playersIn.is_open() || !teamsIn.is_open()) {
        std::cout << "Could not open files for reading" << std::endl;
        return;
    }

    std::string teamName, country, league;
    while (teamsIn >> teamName >> country >> league) {
        auto team = std::make_shared<Team>(teamName, country, league);
        MemoryRepository::addTeam(team);
        std::cout << "Loaded team: " << teamName << std::endl;
    }

    teamsIn.close();

    std::string overallRating, name, nationality, team, position, age, foot, photograph, overallAwareness, ballControl,
            dribling, tightPossession, lowPass, loftedPass, finishing, heading, placeKicking, curl, speed, acceleration,
            kickingPower, jump, physicalContact, balance, stamina, defensiveAwareness, ballWinning, aggression,
            gkAwareness, gkCatching, gkClearing, gkReflexes, gkReach, weekFoot, weekAccuracy, form, injuryResistance;
    while (playersIn >> overallRating >> name >> nationality >> team >> position >> age >> foot >> photograph >>
           overallAwareness >> ballControl >> dribling >> tightPossession >> lowPass >> loftedPass >> finishing >>
           heading >> placeKicking >> curl >> speed >> acceleration >> kickingPower >> jump >> physicalContact >>
           balance >> stamina >> defensiveAwareness >> ballWinning >> aggression >> gkAwareness >> gkCatching >>
           gkClearing >> gkReflexes >> gkReach >> weekFoot >> weekAccuracy >> form >> injuryResistance) {
        Team* teamPtr = nullptr;
        for (auto &t : MemoryRepository::getTeams()) {
            if (t->getName() == team) {
                teamPtr = t.get();
                break;
            }
        }
        auto player = std::make_shared<Player>(std::stoi(overallRating), name, nationality, teamPtr, position, std::stoi(age),
                                                foot, photograph, std::stoi(overallAwareness), std::stoi(ballControl),
                                                std::stoi(dribling), std::stoi(tightPossession), std::stoi(lowPass),
                                                std::stoi(loftedPass), std::stoi(finishing), std::stoi(heading),
                                                std::stoi(placeKicking), std::stoi(curl), std::stoi(speed),
                                                std::stoi(acceleration), std::stoi(kickingPower), std::stoi(jump),
                                                std::stoi(physicalContact), std::stoi(balance), std::stoi(stamina),
                                                std::stoi(defensiveAwareness), std::stoi(ballWinning), std::stoi(aggression),
                                                std::stoi(gkAwareness), std::stoi(gkCatching), std::stoi(gkClearing),
                                                std::stoi(gkReflexes), std::stoi(gkReach), std::stoi(weekFoot),
                                                std::stoi(weekAccuracy), std::stoi(form), std::stoi(injuryResistance));
        MemoryRepository::addPlayer(player);
        std::cout << "Loaded player: " << name << std::endl;
    }

    playersIn.close();
}

void FileRepository::saveToFile() {
    std::ofstream playersOut(playersFile);
    std::ofstream teamsOut(teamsFile);

    for (auto &p : MemoryRepository::getPlayers()) {
        playersOut << p->getOverallRating() << " " << p->getName() << " " << p->getNationality() << " " <<
                   p->getTeam()->getName() << " " << p->getPosition() << " " << p->getAge() << " " << p->getFoot() << " " <<
                   p->getPhotograph() << " " << p->getOverallAwareness() << " " << p->getBallControl() << " " <<
                   p->getDribbling() << " " << p->getTightPossession() << " " << p->getLowPass() << " " <<
                   p->getLoftedPass() << " " << p->getFinishing() << " " << p->getHeading() << " " <<
                   p->getPlaceKicking() << " " << p->getCurl() << " " << p->getSpeed() << " " << p->getAcceleration() << " " <<
                   p->getKickingPower() << " " << p->getJump() << " " << p->getPhysicalContact() << " " <<
                   p->getBalance() << " " << p->getStamina() << " " << p->getDefensiveAwareness() << " " <<
                   p->getBallWinning() << " " << p->getAggression() << " " << p->getGkAwareness() << " " <<
                   p->getGkCatching() << " " << p->getGkClearing() << " " << p->getGkReflexes() << " " <<
                   p->getGkReach() << " " << p->getWeekFoot() << " " << p->getWeekAccuracy() << " " <<
                   p->getForm() << " " << p->getInjuryResistance() << "\n";
    }

    for (auto &t : MemoryRepository::getTeams()) {
        teamsOut << t->getName() << " " << t->getCountry() << " " << t->getLeague() << "\n";
    }

    playersOut.close();
    teamsOut.close();
}
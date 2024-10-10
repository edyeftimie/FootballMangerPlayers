//
// Created by eftim on 20.07.2024.
//

#ifndef FOOTBALLMANGERPLAYERS_PLAYER_H
#define FOOTBALLMANGERPLAYERS_PLAYER_H

#include <iostream>
#include <cstring>

#include "Team.h"

class Player {
    private:
        int overallRating;
        std::string name;
        std::string nationality;
        Team* team;
        std::string position;
        int age;
        std::string foot;
        std::string photograph;

        int overallAwareness; int ballControl; int dribbling;
        int tightPossession; int lowPass; int loftedPass;
        int finishing; int heading; int placeKicking; int curl;
        int speed; int acceleration;
        int kickingPower; int jump; int physicalContact; int balance; int stamina;
        int defensiveAwareness; int ballWinning; int aggression;
        int gkAwareness; int gkCatching; int gkClearing; int gkReflexes; int gkReach;
        int weekFoot; int weekAccuracy; int form; int injuryResistance;

    public:
        Player(int, std::string, std::string, Team* team, std::string, int, std::string, std::string);
        Player(int, std::string, std::string, Team* team, std::string, int, std::string, std::string,
            int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

        //getters and setters
        int getOverallRating() const;

        void setOverallRating(int _overallRating);

        const std::string &getName() const;

        void setName(const std::string &_name);

        const std::string &getNationality() const;

        void setNationality(const std::string &_nationality);

        Team* getTeam();

        void setTeam(Team* _team);

        const std::string &getPosition() const;

        void setPosition(const std::string &_position);

        int getAge() const;

        void setAge(int _age);

        const std::string &getFoot() const;

        void setFoot(const std::string &_foot);

        const std::string &getPhotograph() const;

        void setPhotograph(const std::string &_photograph);

        int getOverallAwareness() const;

        void setOverallAwareness(int _overallAwareness);

        int getBallControl() const;

        void setBallControl(int _ballControl);

        int getDribbling() const;

        void setDribbling(int _dribbling);

        int getTightPossession() const;

        void setTightPossession(int _tightPossession);

        int getLowPass() const;

        void setLowPass(int _lowPass);

        int getLoftedPass() const;

        void setLoftedPass(int _loftedPass);

        int getFinishing() const;

        void setFinishing(int _finishing);

        int getHeading() const;

        void setHeading(int _heading);

        int getPlaceKicking() const;

        void setPlaceKicking(int _placeKicking);

        int getCurl() const;

        void setCurl(int _curl);

        int getSpeed() const;

        void setSpeed(int _speed);

        int getAcceleration() const;

        void setAcceleration(int _acceleration);

        int getKickingPower() const;

        void setKickingPower(int _kickingPower);

        int getJump() const;

        void setJump(int _jump);

        int getPhysicalContact() const;

        void setPhysicalContact(int _physicalContact);

        int getBalance() const;

        void setBalance(int _balance);

        int getStamina() const;

        void setStamina(int _stamina);

        int getDefensiveAwareness() const;

        void setDefensiveAwareness(int _defensiveAwareness);

        int getBallWinning() const;

        void setBallWinning(int _ballWinning);

        int getAggression() const;

        void setAggression(int _aggression);

        int getGkAwareness() const;

        void setGkAwareness(int _gkAwareness);

        int getGkCatching() const;

        void setGkCatching(int _gkCatching);

        int getGkClearing() const;

        void setGkClearing(int _gkClearing);

        int getGkReflexes() const;

        void setGkReflexes(int _gkReflexes);

        int getGkReach() const;

        void setGkReach(int _gkReach);

        int getWeekFoot() const;

        void setWeekFoot(int weekFoot);

        int getWeekAccuracy() const;

        void setWeekAccuracy(int weekAccuracy);

        int getForm() const;

        void setForm(int form);

        int getInjuryResistance() const;

        void setInjuryResistance(int injuryResistance);
};

#endif //FOOTBALLMANGERPLAYERS_PLAYER_H

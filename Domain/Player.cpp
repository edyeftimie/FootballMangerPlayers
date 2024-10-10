//
// Created by eftim on 20.07.2024.
//

#include "Player.h"

#include <utility>

Player::Player(int _overallRating, std::string _name, std::string _nationality,
               Team* _team, std::string _position, int _age, std::string _foot,
               std::string _photograph) : overallRating(_overallRating), name(std::move(_name)),
               nationality(std::move(_nationality)), team(_team), position(std::move(_position)), age(_age),
               foot(std::move(_foot)), photograph(std::move(_photograph)) {
    this->overallAwareness = 40; this->ballControl = 40; this->dribbling = 40; this->tightPossession = 40;
    this->lowPass = 40; this->loftedPass = 40; this->finishing = 40; this->heading = 40;
    this->placeKicking = 40; this->curl = 40; this->speed = 40; this->acceleration = 40; this->kickingPower = 40;
    this->jump = 40; this->physicalContact = 40; this->balance = 40; this->stamina = 40;
    this->defensiveAwareness = 40; this->ballWinning = 40; this->aggression = 40; this->gkAwareness = 40;
    this->gkCatching = 40; this->gkClearing = 40; this->gkReflexes = 40; this->gkReach = 40;
    this->weekFoot = 1; this->weekFoot = 1; this->weekAccuracy = 1; this->form = 1;
    this->injuryResistance = 1;
}

Player::Player(int overallRating, std::string name, std::string nationality, Team *team,
               std::string position, int age, std::string foot, std::string photograph,
               int overallAwareness, int ballControl, int dribbling, int tightPossession, int lowPass, int loftedPass,
               int finishing, int heading, int placeKicking, int curl, int speed, int acceleration, int kickingPower,
               int jump, int physicalContact, int balance, int stamina, int defensiveAwareness, int ballWinning,
               int aggression, int gkAwareness, int gkCatching, int gkClearing, int gkReflexes, int gkReach,
               int weekFoot, int weekAccuracy, int form, int injuryResistance) : overallRating(overallRating),
                 name(std::move(name)), nationality(std::move(nationality)), team(team), position(std::move(position)),
                 age(age), foot(std::move(foot)), photograph(std::move(photograph)), overallAwareness(overallAwareness),
                 ballControl(ballControl), dribbling(dribbling), tightPossession(tightPossession), lowPass(lowPass),
                 loftedPass(loftedPass), finishing(finishing), heading(heading), placeKicking(placeKicking), curl(curl),
                 speed(speed), acceleration(acceleration), kickingPower(kickingPower), jump(jump),
                 physicalContact(physicalContact), balance(balance), stamina(stamina),
                 defensiveAwareness(defensiveAwareness), ballWinning(ballWinning), aggression(aggression),
                 gkAwareness(gkAwareness), gkCatching(gkCatching), gkClearing(gkClearing), gkReflexes(gkReflexes),
                 gkReach(gkReach), weekFoot(weekFoot), weekAccuracy(weekAccuracy), form(form), injuryResistance(injuryResistance) {}

int Player::getOverallRating() const {
    return overallRating;
}

void Player::setOverallRating(int _overallRating) {
    Player::overallRating = _overallRating;
}

const std::string &Player::getName() const {
    return name;
}

void Player::setName(const std::string &_name) {
    Player::name = _name;
}

const std::string &Player::getNationality() const {
    return nationality;
}

void Player::setNationality(const std::string &_nationality) {
    Player::nationality = _nationality;
}

Team* Player::getTeam() {
    return team;
}

void Player::setTeam(Team* _team) {
    Player::team = _team;
}

const std::string &Player::getPosition() const {
    return position;
}

void Player::setPosition(const std::string &_position) {
    Player::position = _position;
}

int Player::getAge() const {
    return age;
}

void Player::setAge(int _age) {
    Player::age = _age;
}

const std::string &Player::getFoot() const {
    return foot;
}

void Player::setFoot(const std::string &_foot) {
    Player::foot = _foot;
}

const std::string &Player::getPhotograph() const {
    return photograph;
}

void Player::setPhotograph(const std::string &_photograph) {
    Player::photograph = _photograph;
}

int Player::getOverallAwareness() const {
    return overallAwareness;
}

void Player::setOverallAwareness(int _overallAwareness) {
    Player::overallAwareness = _overallAwareness;
}

int Player::getBallControl() const {
    return ballControl;
}

void Player::setBallControl(int _ballControl) {
    Player::ballControl = _ballControl;
}

int Player::getDribbling() const {
    return dribbling;
}

void Player::setDribbling(int _dribbling) {
    Player::dribbling = _dribbling;
}

int Player::getTightPossession() const {
    return tightPossession;
}

void Player::setTightPossession(int _tightPossession) {
    Player::tightPossession = _tightPossession;
}

int Player::getLowPass() const {
    return lowPass;
}

void Player::setLowPass(int _lowPass) {
    Player::lowPass = _lowPass;
}

int Player::getLoftedPass() const {
    return loftedPass;
}

void Player::setLoftedPass(int _loftedPass) {
    Player::loftedPass = _loftedPass;
}

int Player::getFinishing() const {
    return finishing;
}

void Player::setFinishing(int _finishing) {
    Player::finishing = _finishing;
}

int Player::getHeading() const {
    return heading;
}

void Player::setHeading(int _heading) {
    Player::heading = _heading;
}

int Player::getPlaceKicking() const {
    return placeKicking;
}

void Player::setPlaceKicking(int _placeKicking) {
    Player::placeKicking = _placeKicking;
}

int Player::getCurl() const {
    return curl;
}

void Player::setCurl(int _curl) {
    Player::curl = _curl;
}

int Player::getSpeed() const {
    return speed;
}

void Player::setSpeed(int _speed) {
    Player::speed = _speed;
}

int Player::getAcceleration() const {
    return acceleration;
}

void Player::setAcceleration(int _acceleration) {
    Player::acceleration = _acceleration;
}

int Player::getKickingPower() const {
    return kickingPower;
}

void Player::setKickingPower(int _kickingPower) {
    Player::kickingPower = _kickingPower;
}

int Player::getJump() const {
    return jump;
}

void Player::setJump(int _jump) {
    Player::jump = _jump;
}

int Player::getPhysicalContact() const {
    return physicalContact;
}

void Player::setPhysicalContact(int _physicalContact) {
    Player::physicalContact = _physicalContact;
}

int Player::getBalance() const {
    return balance;
}

void Player::setBalance(int _balance) {
    Player::balance = _balance;
}

int Player::getStamina() const {
    return stamina;
}

void Player::setStamina(int _stamina) {
    Player::stamina = _stamina;
}

int Player::getDefensiveAwareness() const {
    return defensiveAwareness;
}

void Player::setDefensiveAwareness(int _defensiveAwareness) {
    Player::defensiveAwareness = _defensiveAwareness;
}

int Player::getBallWinning() const {
    return ballWinning;
}

void Player::setBallWinning(int _ballWinning) {
    Player::ballWinning = _ballWinning;
}

int Player::getAggression() const {
    return aggression;
}

void Player::setAggression(int _aggression) {
    Player::aggression = _aggression;
}

int Player::getGkAwareness() const {
    return gkAwareness;
}

void Player::setGkAwareness(int _gkAwareness) {
    Player::gkAwareness = _gkAwareness;
}

int Player::getGkCatching() const {
    return gkCatching;
}

void Player::setGkCatching(int _gkCatching) {
    Player::gkCatching = _gkCatching;
}

int Player::getGkClearing() const {
    return gkClearing;
}

void Player::setGkClearing(int _gkClearing) {
    Player::gkClearing = _gkClearing;
}

int Player::getGkReflexes() const {
    return gkReflexes;
}

void Player::setGkReflexes(int _gkReflexes) {
    Player::gkReflexes = _gkReflexes;
}

int Player::getGkReach() const {
    return gkReach;
}

void Player::setGkReach(int _gkReach) {
    Player::gkReach = _gkReach;
}

int Player::getWeekFoot() const {
    return weekFoot;
}

void Player::setWeekFoot(int _weekFoot) {
    Player::weekFoot = _weekFoot;
}

int Player::getWeekAccuracy() const {
    return weekAccuracy;
}

void Player::setWeekAccuracy(int _weekAccuracy) {
    Player::weekAccuracy = _weekAccuracy;
}

int Player::getForm() const {
    return form;
}

void Player::setForm(int _form) {
    Player::form = _form;
}

int Player::getInjuryResistance() const {
    return injuryResistance;
}

void Player::setInjuryResistance(int _injuryResistance) {
    Player::injuryResistance = _injuryResistance;
}


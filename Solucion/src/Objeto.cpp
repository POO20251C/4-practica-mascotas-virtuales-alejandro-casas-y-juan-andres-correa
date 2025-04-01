#include "Objeto.h"

#include "string"

Objeto::Objeto(std::string name, std::string desc, int energy, int health) {
    this -> name = name;
    this -> desc = desc;
    this -> energy = energy;
    this -> health = health;
}

std::string Objeto::getName() const {
    return name;
}

std::string Objeto::getDesc() const {
    return desc;
}

int Objeto::getEnergy() const {
    return energy;
}

int Objeto::getHealth() const {
    return health;
}

std::string Objeto::usar_objeto() const {
    return desc;
}
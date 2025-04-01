#include "Habilidad.h"

#include <string>

Habilidad::Habilidad(std::string name, std::string desc, int energy) {
    this -> name = name;
    this -> energy = energy;
    this -> desc = desc;
}

std::string Habilidad::getName() const {
    return name;
}

int Habilidad::getEnergy() const {
    return energy;
}

std::string Habilidad::getDesc() const {
    return desc;
}

std::string Habilidad::usarHabilidad() const {
    return desc + " (Requiere " + std::to_string(energy) + " de energía)";
}
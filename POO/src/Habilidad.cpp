#include "Habilidad.h"

#include <string>

Habilidad::Habilidad(std::string name) {
    int requiredEnergy;

    this -> name = name;

    if (name == "Bailar") {
        requiredEnergy = 20;
    } else if (name == "Objeto") {
        requiredEnergy = 40;

    } else if (name == "") {
        requiredEnergy = 4;
    } else {
        name = "";
    }

    this -> requiredEnergy = requiredEnergy;
}

std::string Habilidad::getName() const {
    return name;
}

int Habilidad::getRequiredEnergy() const {
    return requiredEnergy;
}
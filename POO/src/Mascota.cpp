#include "Mascota.h"
#include "Habilidad.h"

#include <string>
#include <vector>
#include <map>

Mascota::Mascota(std::string name, int age) {
    this -> name = name;
    this -> age = age;
    this -> health = 100;
    this -> emotion = 100;
    this -> xp = 1;

    this -> historyCounter = 0;
}

std::string Mascota::getName() {
    return name;
}

int Mascota::getAge() {
    return age;
}

int Mascota::getHealth() {
    return health;
}

int Mascota::getEnergy() {
    return energy;
}

int Mascota::getEmotion() {
    return emotion;
}

const std::map<std::string, Habilidad>& Mascota::getSkills() const {
    return skills;
}

std::string Mascota::learn(std::string hability) {
    std::string result;

    if (skills.find(hability) == skills.end()) {
        skills.insert(std::make_pair(hability, Habilidad(hability)));
        //skills[hability] = Habilidad(hability);

        result = "Se agrego la habilidad";
    } else {
        result = "Habilidad ya aprendida";
    }

    return result;
}

std::string Mascota::gethealthStatus() {
    std::string result;

    if (health >= 80) {
        result =  name + " esta sana :)";
    } else if (health >= 60) {
        result = name + " esta regular :|";
    } else if (health >= 30) {
        result = name + " esta enferma D:";
    } else {
        result = name + " esta muy enferma x_x";
    }

    return result;
}
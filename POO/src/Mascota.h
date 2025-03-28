#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>
#include <map>

#include "Habilidad.h"

class Mascota {
public:
    Mascota(std::string name, int age);

    // getters
    std::string getName();
    int getAge();
    int getHealth();
    int getEnergy();
    int getEmotion();
    int getExp();
    const std::map<std::string, Habilidad>& getSkills() const;

    // Funciones
    std::string showHistory();
    std::string increaseExp(int amount);
    std::string learn(std::string hability);

    std::string gethealthStatus();
private:
    std::string name;
    int age;
    int health;
    int energy;
    int emotion;
    int xp;
    int id;

    //
    std::map<std::string, Habilidad> skills;
    std::map<int, std::string> history;
    int historyCounter;

};

#endif
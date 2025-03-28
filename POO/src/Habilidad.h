#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>

class Habilidad {
public:
    Habilidad() = default;
    Habilidad(std::string name);

    // Getters
    std::string getName() const;
    int getRequiredEnergy() const;

    std::string fire();
private:
    std::string name;
    int requiredEnergy;
};

#endif
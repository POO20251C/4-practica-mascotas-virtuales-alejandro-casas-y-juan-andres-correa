#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>

class Habilidad {
private:
    std::string name;
    int energy;
    std::string desc;

public:
    Habilidad() = default;
    Habilidad(std::string name, std::string desc, int energy);

    std::string getName() const;
    int getEnergy() const;
    std::string getDesc() const;

    std::string usarHabilidad() const;
};

#endif
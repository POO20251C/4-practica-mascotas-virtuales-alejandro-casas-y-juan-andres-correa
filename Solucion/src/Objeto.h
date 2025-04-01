#ifndef OBJETO_H
#define OBJETO_H

#include <string>

class Objeto {
private:
    std::string name;
    std::string desc;

    int energy;
    int health;

public:
    Objeto() = default;

    Objeto(std::string name, std::string desc,int energy, int health);

    std::string getName() const;
    std::string getDesc() const;

    int getEnergy() const;
    int getHealth() const;

    std::string usar_objeto() const;
};

#endif
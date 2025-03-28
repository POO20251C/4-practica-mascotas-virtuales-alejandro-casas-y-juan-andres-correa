#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Mascota.h"
#include <map>
#include <vector>

class Usuario {
public:
    Usuario() = default;
    Usuario(std::string name);

    // Getters
    std::string getName();

    std::vector<Mascota> getPets();
    Mascota getPet(int pos);
private:
    std::string name;
    std::vector<Mascota> pets;
};

#endif
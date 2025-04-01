#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>

#include "Mascota.h"

class Usuario {
private:
    std::string name;
    std::map<std::string, Mascota> pets;

public:
    Usuario() = default;
    Usuario(std::string name);
    
    std::string getName() const;

    std::map<std::string, Mascota>& getPets();
    std::string adoptar_mascota(const Mascota& pet);

    bool petExist(std::string) const;
};

#endif
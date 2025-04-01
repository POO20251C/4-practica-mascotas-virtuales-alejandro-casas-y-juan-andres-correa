#include "Usuario.h"
#include "Mascota.h"

#include <map>
#include <string>

Usuario::Usuario(std::string name) {
    this -> name = name;
}

std::string Usuario::adoptar_mascota(const Mascota& pet) {
    if (pets.find(pet.getName()) == pets.end()) {
        pets[pet.getName()] = pet;
        return name + " ha adoptado a " + pet.getName() + ".";
    }
    return name + " ya tiene una mascota llamada " + pet.getName() + ".";
}

std::string Usuario::getName() const {
    return name;
}

std::map<std::string, Mascota>& Usuario::getPets() {
    return pets;
}

bool Usuario::petExist(std::string n) const {
    if (pets.find(n) != pets.end()) {
        return true;
    }

    return false;
}
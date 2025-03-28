#include "Usuario.h"
#include "Mascota.h"

#include "string"
#include "vector"

Usuario::Usuario(std::string name) {
    this -> name = name;
}

std::vector<Mascota> Usuario::getPets(){
    return pets;
}
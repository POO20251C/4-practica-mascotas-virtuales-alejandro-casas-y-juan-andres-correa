#include <string>
#include <vector>

#include "Mascota.h"
#include "Habilidad.h"
#include "Objeto.h"
#include "Cuidado.h"

Mascota::Mascota(std::string name) {
    this -> name = name;
    this -> energy = 100;
    this -> health = 100;
    this -> age = 1;
}

std::string Mascota::getName() const {
    return name;
}

int Mascota::getAge() const {
    return age;
}

int Mascota::getEnergy() const {
    return energy;
}

int Mascota::getHealth() const {
    return health;
}

std::string Mascota::addHability(Habilidad h) {
    for(const Habilidad& hab : habilidades) {
        if (hab.getName() == h.getName()) {
            return name + " ya conoce esta habilidad.";
        }
    }

    habilidades.push_back(h);

    return name + " a aprendido una nueva habilidad";
}

std::vector<Habilidad> Mascota::getHabilidades() const {
    return habilidades;
}

std::string Mascota::usarHabilidad(const std::string n) {
    for (const auto& habilidad : habilidades) {
        if (habilidad.getName() == n) {
            if (energy >= habilidad.getEnergy()) {
                energy -= habilidad.getEnergy();
                return habilidad.usarHabilidad();
            } else {
                return name + " no tiene suficiente energía para usar " + n + ".";
            }
        }
    }
    return name + " no conoce la habilidad " + n + ".";
}

std::string Mascota::usarObjeto(const Objeto& obj) {
    energy += obj.getEnergy();
    health += obj.getHealth();

    if (energy > 100) {
        energy = 100;
    }

    if (health > 100) {
        health = 100;
    }

    if (energy < 0) {
        energy = 0;
    }

    if (health < 0) {
        health = 0;
    }

    registrarCuidado("objeto", name + " uso " + obj.getName());
    registrarCuidado("salud", "Salud cambio a " + std::to_string(health));
    registrarCuidado("energía", "Energía cambio a " + std::to_string(energy));

    return name + " ha usado " + obj.getName() + ": " + obj.usar_objeto();
}

void Mascota::registrarCuidado(const std::string& tipo, const std::string& descripcion) {
    cuidados.push_back(Cuidado(tipo, descripcion));
}

std::vector<Cuidado> Mascota::getCuidados() const {
    return cuidados;
}

std::string Mascota::getHealthState() const {
    std::string result;

    if (health == 100) {
        result = "Sano";
    } else if (health >= 70) {
        result = "Regular";
    } else if (health >= 30) {
        result = "Enfermo";
    } else {
        result = "Muy enfemro";
    }

    return result;
}

std::string Mascota::getEmotionState() const {
    std::string result;

    if (energy == 100) {
        result = "Feliz";
    } else if (energy >= 70) {
        result = "Normal";
    } else if (energy >= 50) {
        result = "Agotado";
    } else if (energy >= 20) {
        result = "Super cansado";
    } else if (energy >= 1) {
        result = "Sin animos";
    }

    return result;
}
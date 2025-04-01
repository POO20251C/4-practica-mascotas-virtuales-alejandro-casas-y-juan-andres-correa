#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>
#include <vector>

#include "Habilidad.h"
#include "Objeto.h"
#include "Cuidado.h"

class Mascota {
private:
    std::string name;
    int energy;
    int health;
    int age;

    std::vector<Habilidad> habilidades;
    std::vector<Cuidado> cuidados;

public:
    Mascota() = default;
    Mascota(std::string name);
    std::string addHability(Habilidad h);
    std::vector<Habilidad> getHabilidades() const;

    std::string getName() const;
    int getEnergy() const;
    int getHealth() const;
    int getAge() const;

    std::string usarHabilidad(const std::string n);
    std::string usarObjeto(const Objeto& obj);

    void registrarCuidado(const std::string& tipo, const std::string& descripcion);
    std::vector<Cuidado> getCuidados() const;

    std::string getHealthState() const;
    std::string getEmotionState() const;
};

#endif
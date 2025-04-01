#include "PixelPets.h"
#include "Habilidad.h"
#include "Usuario.h"
#include "Objeto.h"

#include <vector>

PixelPets::PixelPets() {
    this -> habilidades = {
        Habilidad("esconderse", "Tu mascota se ha escondido.", 15),
        Habilidad("correr", "Tu mascota esta corriendo.", 25),
        Habilidad("saltar", "Tu mascota esta saltando.", 20),
        Habilidad("pedir comida", "Tu mascota esta pidiendo comida.", 0),
        Habilidad("buscar objeto", "Tu mascota esta buscando un objeto.", 10),
        Habilidad("bailar", "Tu mascota esta bailando.", 30)
    };

    agregarObjeto("Croqueta", Objeto("Croqueta", "Tu mascota ha comido una croqueta.", 30, 15));
    agregarObjeto("Pocion", Objeto("Pocion Mágica", "Restaura la salud de tu mascota.", 50, 10));
    agregarObjeto("Juguete", Objeto("Pelota", "Tu mascota juega y se siente mas feliz.", 10, 25));
    agregarObjeto("Galleta", Objeto("Galleta de Carne", "Deliciosa y nutritiva para tu mascota.", 20, 20));
    agregarObjeto("Medicina", Objeto("Antidoto", "Cura enfermedades leves de tu mascota.", 40, 5));
    agregarObjeto("Bebida", Objeto("Leche", "Un poco de leche para tu mascota.", 15, 30));
    agregarObjeto("Manzana", Objeto("Manzana", "Saludable y refrescante.", 25, 10));
    agregarObjeto("Porro", Objeto("Porro", "Esto no es saludable para tu mascota.", 0, -30));
}

void PixelPets::agregarObjeto(const std::string& name, const Objeto& obj) {
    objetos[name] = obj;
}

std::vector<Habilidad> PixelPets::getHabilidades() const {
    return habilidades;
}

std::map<std::string, Objeto> PixelPets::getObjetos() const {
    return objetos;
}

std::map<std::string, Usuario> PixelPets::getUsuarios() const {
    return usuarios;
}

std::string PixelPets::agregarUsuario(const std::string& n) {
    if (usuarios.find(n) == usuarios.end()) {
        usuarios[n] = Usuario(n);
        return "Usuario " + n + " agregado correctamente.";
    } else {
        return "El usuario " + n + " ya existe.";
    }
}

bool PixelPets::userExist(const std::string& n) {
    if (usuarios.find(n) != usuarios.end()) {
        return true;
    }

    return false;
}

Usuario& PixelPets::getUsuario(const std::string& n) {
    return usuarios[n];
}
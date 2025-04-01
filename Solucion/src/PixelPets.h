#ifndef PIXELPETS_H
#define PIXELPETS_H

#include "Habilidad.h"
#include "Usuario.h"
#include "Objeto.h"

#include "map"
#include "vector"


class PixelPets {
private:
    std::vector<Habilidad> habilidades;
    std::map<std::string, Usuario> usuarios;
    std::map<std::string, Objeto> objetos;

    void agregarObjeto(const std::string& name, const Objeto& obj);

public:
    PixelPets();

    // getters
    std::vector<Habilidad> getHabilidades() const;
    std::map<std::string, Objeto> getObjetos() const;

    std::map<std::string, Usuario> getUsuarios() const;

    std::string agregarUsuario(const std::string& name);

    Usuario& getUsuario(const std::string& name);
    bool userExist(const std::string& n);
};

#endif
#include "Cuidado.h"
#include <string>

Cuidado::Cuidado(std::string tipo, std::string descripcion) {
    this->tipo = tipo;
    this->descripcion = descripcion;
}

std::string Cuidado::getTipo() const {
    return tipo;
}

std::string Cuidado::getDescripcion() const {
    return descripcion;
}
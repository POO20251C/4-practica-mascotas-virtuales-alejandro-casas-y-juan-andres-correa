#ifndef CUIDADO_H
#define CUIDADO_H

#include <string>

class Cuidado {
private:
    std::string tipo;
    std::string descripcion;

public:
    Cuidado() = default;
    Cuidado(std::string tipo, std::string descripcion);

    std::string getTipo() const;
    std::string getDescripcion() const;
};

#endif
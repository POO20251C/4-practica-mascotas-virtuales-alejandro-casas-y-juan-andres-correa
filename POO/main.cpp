#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "src/Mascota.h"

using namespace std;

int main() {
    // Contenedor con las mascotas
    vector<Mascota> mascotas;

    // Creación registro de las mascotas
    Mascota test("Alejo", 14);
    cout << test.learn("Bailar") << endl;

    cout << test.learn("Bailar") << endl;

    const auto& habilidades = test.getSkills();

    for (const auto& [nombre, habilidad] : habilidades) {
        cout << "Habilidad: " << habilidad.getName() << ", Energía requerida: " << habilidad.getRequiredEnergy() << endl;
    }

    cout << test.gethealthStatus();

    return 0;
}
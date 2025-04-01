#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "src/Mascota.h"
#include "src/Habilidad.h"
#include "src/PixelPets.h"
#include "src/Usuario.h"

using namespace std;

void showPets(Usuario& user) {
    map<string, Mascota> pets = user.getPets();

    if (pets.empty()) {
        cout << user.getName() << " no tienes mascotas aun.";
    } else {
        for (const auto& [name, p] : pets) {
            cout << "\n==================\n";
            cout << "Nombre: " << p.getName() << endl;
            cout << "Age: " << p.getAge() << endl;
            cout << "Salud:  " << p.getHealth() << endl;
            cout << "Energia: " << p.getEnergy() << endl;
            cout << "Estado emocional: " << p.getEmotionState() << endl;
            cout << "Estado de salud: " << p.getHealthState();

            cout << "Habilidades\n";

            vector<Habilidad> habilidades = p.getHabilidades();

            if (habilidades.empty() == true) {
                cout << p.getName() << " no tiene ninguna habilidad\n";
            } else {
                for (size_t i = 0; i < habilidades.size(); i++) {
                    cout << to_string(i) << ": " << habilidades[i].getName() << endl;
                }
            }

            cout << "Cuidados\n";

            std::vector<Cuidado> cuidados = p.getCuidados();
            if (cuidados.empty()) {
                cout << p.getName() << " no tiene cuidados registrados.\n";
            } else {
                for (const auto& cuidado : cuidados) {
                    cout << "Tipo: " << cuidado.getTipo() << endl;
                    cout << "Descripción: " << cuidado.getDescripcion();
                }
            }
            
            cout << "==================\n";
        }
    }
}

void showHabilidades(const vector<Habilidad> habilidades) {

    for (size_t i = 0; i < habilidades.size(); i++) {
        Habilidad habilidad = habilidades[i];
        cout << "\n==================\n";
        cout << "Nombre: " << habilidad.getName() << endl;
        cout << "Id: " << i << endl;
        cout << "Energia: " << to_string(habilidad.getEnergy());
        cout << "\n==================\n";
    }
}

void showObjetos(const map<string, Objeto> objetos) {
    for (const auto& [name, obj] : objetos) {
        cout << "\n==================\n";
        cout << "Nombre: " << obj.getName() << endl;
        cout << "Llave: " << name << endl;
        cout << "Descripcion: " << obj.getDesc() << endl;
        cout << "Energia: " << to_string(obj.getEnergy()) << endl;
        cout << "Salud: " << to_string(obj.getHealth());
        cout << "\n==================\n";
    }
}

void showUsers(const map<string, Usuario> usuarios) {
    if (usuarios.empty()) {
        cout << "No hay usuarios registrados.\n";
        return;
    }

    for (const auto& [name, user] : usuarios) {
        cout << "\n==================\n";
        cout << "Nombre: " << user.getName();
        cout << "\n==================\n";
    }

}

int main() {
    PixelPets game;

    int option;

    while (true) {
        cout << "\n1) Consultar un usuario\n2) Agregar un usuario\n3) Mostrar usuarios registrados\n4) Finalizar\nSeleccione una opcion: ";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            string user_name;
            cout << "Ingrese su nombre de usuario: ";
            getline(cin, user_name);

            if (game.userExist(user_name)) {
                Usuario& user = game.getUsuario(user_name);
                int user_option;

                while (true) {
                    cout << "\nBienvenido, " << user.getName() << "\n";
                        cout << "1) Usar una habilidad\n2) Adoptar una mascota\n3) Mostrar mascotas\n";
                        cout << "4) Enseñar una habilidad\n5) Usar un objeto\n6) Salir\nSeleccione una opción: ";

                        cin >> user_option;
                        cin.ignore();

                        if (user_option == 1) {
                            string pet_name;
                            cout << "Que mascota quieres que use una habilidad? ";
                            getline(cin, pet_name);
                        
                            if (user.petExist(pet_name)) {
                                Mascota& pet = user.getPets()[pet_name];
                                vector<Habilidad> habilidades = pet.getHabilidades();
                        
                                if (habilidades.empty()) {
                                    cout << pet_name << " no tiene ninguna habilidad.\n";
                                } else {
                                    cout << "Habilidades de " << pet_name << ":\n";
                                    for (size_t i = 0; i < habilidades.size(); i++) {
                                        cout << i << ": " << habilidades[i].getName() << " (Energia requerida: " 
                                             << habilidades[i].getEnergy() << ")\n";
                                    }
                        
                                    int habilidad_id;
                                    cout << "Selecciona una habilidad (escribe el numero): ";
                                    cin >> habilidad_id;
                                    cin.ignore();
                        
                                    if (habilidad_id >= 0 and habilidad_id < static_cast<int>(habilidades.size())) {
                                        string habilidad_name = habilidades[habilidad_id].getName();
                                        cout << pet.usarHabilidad(habilidad_name) << endl;
                                    } else {
                                        cout << "Numero de habilidad invalido.\n";
                                    }
                                }
                            } else {
                                cout << "La mascota " << pet_name << " no existe.\n";
                            }

                        } else if (user_option == 2) {
                            string pet_name;
                            cout << "Que nombre quieres darle a tu nueva mascota?: ";
                            getline(cin, pet_name);

                            Mascota pet = Mascota(pet_name);

                            cout << user.adoptar_mascota(pet);

                        } else if (user_option == 3) {
                            showPets(user);



                        } else if (user_option == 4) {
                            string pet_name;
                        
                            cout << "Que mascota quieres que aprenda una habilidad? ";
                            getline(cin, pet_name);
                        
                            if (user.petExist(pet_name)) {
                                const vector<Habilidad> habilidades = game.getHabilidades();
                                int id;
                        
                                showHabilidades(habilidades);
                        
                                cout << "Que habilidad desea aprender (escriba un id)? ";
                                cin >> id;
                                cin.ignore();
                                
                                bool encontrado = false;
                                Habilidad h;
                        
                                for (size_t i = 0; i < habilidades.size(); i++) {
                                    if (id == i) {
                                        encontrado = true;
                                        h = habilidades[i];
                                        break;
                                    }
                                }
                        
                                if (encontrado == true) {
                                    Mascota& pet = user.getPets()[pet_name];
                                    cout << pet.addHability(h) << endl;
                                } else {
                                    cout << "Habilidad no encontrada." << endl;
                                }
                            } else {
                                cout << "Mascota no encontrada." << endl;
                            }
                        } else if (user_option == 5) {
                            string pet_name;
                            cout << "A que mascota quieres darle un objeto? ";
                            getline(cin, pet_name);

                            if (user.petExist(pet_name)) {
                                map<string, Objeto> objetos = game.getObjetos();
                                showObjetos(objetos);

                                string objeto_name;
                                cout << "Que objeto deseas usar? (Escribe la llave): ";
                                getline(cin, objeto_name);

                                if (objetos.find(objeto_name) != objetos.end()) {
                                    Mascota& pet = user.getPets()[pet_name];
                                    Objeto& objeto = objetos[objeto_name];
                                    cout << pet.usarObjeto(objeto) << endl;
                                } else {
                                    cout << "Objeto '" << objeto_name << "' no encontrado.\n";
                                }
                            } else {
                                cout << "Mascota no encontrada." << endl;
                            }
                        } else if (user_option == 6) {
                            break;
                        }
                }
            } else {
                cout << "El usuario " << user_name << " no existe.\n";
            }         

        } else if (option == 2) {
            string user_name;

            cout << "Ingrese un nombre de usuario: ";
            getline(cin, user_name);
            cout << game.agregarUsuario(user_name);
        } else if (option == 3) {
            showUsers(game.getUsuarios());
        } else if (option == 4) {
            cout << "Gracias por jugar :)" << endl;

            return 0;
        }
    }

}
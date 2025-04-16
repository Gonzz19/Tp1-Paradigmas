

#include "garrote.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

Garrote::Garrote(string nombre,TipoArma tipoArma, int danio, int durabilidad, int nivel)
    : Arma_combate(nombre, tipoArma, danio, durabilidad, nivel) {}

Garrote::~Garrote() 
{
    cout << "Destruyendo Garrote" << endl;
}

void Garrote::garrotazo(shared_ptr<Personaje> usuario, shared_ptr<Personaje> enemigo) 
{
    cout << usuario->get_nombre() << " lanza el garrote a " << enemigo->get_nombre() << endl;
    cout << "El garrote hace " << danio_(usuario) << " de daño." << endl;
    enemigo->recibir_ataque(danio_(usuario), CLASE::FISICO);
    cout << enemigo->get_nombre() << " ha recibido el ataque." << endl;
    this->durabilidad = 0;
}
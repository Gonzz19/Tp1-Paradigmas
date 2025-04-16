

#include "espada.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;


Espada::Espada(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel)
    : Arma_combate(nombre, tipoArma, danio, durabilidad, nivel) {}

Espada::~Espada()
{
    cout << "Destructor de Espada" << endl;
}

void Espada::destructor_de_mundos(shared_ptr<Personaje> usuario)
{
    cout << "Destructor de mundos activado por " << usuario->get_nombre() << endl;
    this->durabilidad  = 0;
    this->danio = 250;
}
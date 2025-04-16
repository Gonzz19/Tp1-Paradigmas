

#include "hacha_doble.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

Hacha_doble::Hacha_doble(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel)
    : Arma_combate(nombre, tipoArma, danio, durabilidad, nivel) {}

Hacha_doble::~Hacha_doble() 
{
    cout << "Destructor Hacha_doble" << endl;
}

void Hacha_doble::pulir(shared_ptr<Personaje> usuario) 
{
    usuario->set_defensa_ad(usuario->getDefensa_ad() + 40);
    usuario->set_defensa_ap(usuario->getDefensa_ap() + 40);
    cout << usuario->get_nombre() << " ha pulido su hacha doble, aumentando su defensa." << endl;
}
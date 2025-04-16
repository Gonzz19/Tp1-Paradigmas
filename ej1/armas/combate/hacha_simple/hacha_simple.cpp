#include "hacha_simple.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

Hacha_simple::Hacha_simple(string nombre,TipoArma tipoArma, int danio, int durabilidad, int nivel)
    : Arma_combate(nombre, tipoArma, danio, durabilidad, nivel) {}

Hacha_simple::~Hacha_simple() 
{
    cout << "Destructor Hacha_simple" << endl;
}

void Hacha_simple::leniador(shared_ptr<Personaje> usuario) 
{
    cout << usuario->get_nombre() << " ha talado un arbol con el hacha simple." << endl;
    arboles_talados++;
    cout << "Total de arboles talados: " << arboles_talados << endl;
}

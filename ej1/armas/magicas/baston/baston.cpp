#include "baston.hpp"

Baston::Baston(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico)
    : Arma_magica(nombre, tipoArma, danio, durabilidad, nivel, poder_magico) {}

Baston::~Baston() 
{
    cout << "Destructor de Baston" << endl;
}

int Baston::baston_final() 
{
    this->poder_magico = 400;
    this->durabilidad = 0;
    cout << "El baston finaliza el ataque con un poder mágico de: " << this->poder_magico << endl;
    return this->poder_magico;
}
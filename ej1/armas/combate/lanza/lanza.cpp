

#include "lanza.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

Lanza::Lanza(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel)
    : Arma_combate(nombre, tipoArma, danio, durabilidad, nivel) {this->metros_max = 0;}

Lanza::~Lanza() 
{
    cout << "Destruyendo Lanza: " << endl;
}

void Lanza::lanzar() 
{
    
    srand(time(0)); 
    int distancia = rand() % 100 + 1;
    if (distancia > this->metros_max) {
        this->metros_max = distancia;
        cout << "La lanza ha sido lanzada a una nueva distancia máxima de " << this->metros_max << " metros." << endl;
    }
    else {
        cout << "La lanza ha sido lanzada a una distancia de " << distancia << " metros." << endl;
        cout << "La distancia máxima sigue siendo " << this->metros_max << " metros." << endl;
    }   
}
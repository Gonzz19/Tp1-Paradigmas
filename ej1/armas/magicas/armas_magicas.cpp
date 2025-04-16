#include "armas_magicas.hpp"
#include "../../personajes/personajes.hpp"
#include <iostream>
#include <string>
#include <memory>


using namespace std;

Arma_magica::Arma_magica(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico)
{
    this->nombre = nombre;
    this->danio = danio;
    this->tipoArma = tipoArma;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
    this->poder_magico = poder_magico;
    this->tipoDanio = MAGICO;
}

int Arma_magica::danio_(shared_ptr<Personaje> usuario)
{
    PERSONAJES tipo = usuario->getTipo_personaje();
    if (tipo == PERSONAJES::CONJURADOR || tipo == PERSONAJES::HECHICERO || tipo == PERSONAJES::BRUJO || tipo == PERSONAJES::NICROMANTE)
    {
        return this->danio + this->poder_magico;
    }
    else
    {
        return this->danio;
    }
}

CLASE Arma_magica::claseArma()
{
    return this->tipoDanio;
}

TipoArma Arma_magica::getArma()
{
    return this->tipoArma;
}

string Arma_magica::get_nombre()
{
    return this->nombre;
}

void Arma_magica::set_nombre(string nombre)
{
    this->nombre = nombre;
}
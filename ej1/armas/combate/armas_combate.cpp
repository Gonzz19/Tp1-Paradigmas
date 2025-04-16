#include "armas_combate.hpp"
#include "../../personajes/personajes.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

Arma_combate::Arma_combate(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel)
{
    this->nombre = nombre;
    this->danio = danio;
    this->tipoArma = tipoArma;
    this->durabilidad = durabilidad;
    this->nivel = nivel;
    this->tipoDanio = FISICO;
}

int Arma_combate::danio_(shared_ptr<Personaje> usuario)
{
    PERSONAJES tipo = usuario->getTipo_personaje();
    if (tipo == PERSONAJES::BARBARO || tipo == PERSONAJES::CABALLERO || tipo == PERSONAJES::GLADIADOR || tipo == PERSONAJES::MERCENARIO || tipo == PERSONAJES::PALADIN)
    {
        return this->danio * 2;
    }
    else
    {
        return this->danio;
    }
}

CLASE Arma_combate::claseArma()
{
    return this->tipoDanio;
}

TipoArma Arma_combate::getArma()
{
    return this->tipoArma;
}

string Arma_combate::get_nombre()
{
    return this->nombre;
}

void Arma_combate::set_nombre(string nombre)
{
    this->nombre = nombre;
}
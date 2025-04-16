#include "guerreros.hpp"
#include "../../armas/armas.hpp"
#include <iostream>

Guerrero::Guerrero(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto, PERSONAJES tipo_personaje)
{
    this->nombre = nombre;
    this->vida = vida;
    this->ataque = ataque;
    this->defensa_ad = defensa_ad;
    this->defensa_ap = defensa_ap;
    this->nivel = nivel;
    this->velocidad = velocidad;
    this->bajo_efecto = bajo_efecto;
    this->estamina = 100; 
    this->estamina_max = 100; 
    this->tipo_personaje = tipo_personaje; 
    this->armas = pair<unique_ptr<Arma>, unique_ptr<Arma>>(nullptr, nullptr);
}


Guerrero::~Guerrero() {}

void Guerrero::set_estamina(int e)
{
    estamina = e;
}

int Guerrero::get_estamina()
{
    return estamina;
}

int Guerrero::get_ataque(unique_ptr<Arma> arma)
{
    return (this->ataque + arma->danio_(shared_from_this()));
}

int Guerrero::get_vida()
{
    return this->vida;
}

string Guerrero::get_nombre()
{
    return this->nombre;
}

int Guerrero::getDefensa_ad()
{
    return this->defensa_ad;
}

int Guerrero::getDefensa_ap()
{
    return this->defensa_ap;
}

int Guerrero::getNivel()
{
    return this->nivel;
}

int Guerrero::getVelocidad()
{
    return this->velocidad;
}

void Guerrero::recibir_ataque(int ataque, CLASE tipo)
{
    int danio;
    if (tipo == CLASE::FISICO)
    {
        danio = ataque - this->defensa_ad;
        if (danio < 0)
        {
            danio = 0;
        }
    }
    else
    {
        danio = ataque - this->defensa_ap;
        if (danio < 0)
        {
            danio = 0;
        }
    }
    this->vida -= danio;
}

PERSONAJES Guerrero::getTipo_personaje()
{
    return this->tipo_personaje;
}

void Guerrero::set_nombre(string nombre)
{
    this->nombre = nombre;
}

void Guerrero::set_vida(int vida)
{
    this->vida = vida;
}

void Guerrero::set_ataque(int ataque)
{
    this->ataque = ataque;
}

void Guerrero::set_defensa_ad(int defensa_ad)
{
    this->defensa_ad = defensa_ad;
}

void Guerrero::set_defensa_ap(int defensa_ap)
{
    this->defensa_ap = defensa_ap;
}

void Guerrero::set_nivel(int nivel)
{
    this->nivel = nivel;
}

void Guerrero::set_velocidad(int velocidad)
{
    this->velocidad = velocidad;
}

void Guerrero::set_bajo_efecto(bool bajo_efecto)
{
    this->bajo_efecto = bajo_efecto;
}

void Guerrero::set_tipo_personaje(PERSONAJES tipo_personaje)
{
    this->tipo_personaje = tipo_personaje;
}

int Guerrero::get_vida_max()
{
    return this->vida_max;
}

void Guerrero::set_armas(unique_ptr<Arma> arma1, unique_ptr<Arma> arma2)
{
    this->armas = pair<unique_ptr<Arma>, unique_ptr<Arma>>(move(arma1), move(arma2));
}

pair<unique_ptr<Arma>, unique_ptr<Arma>>& Guerrero::get_armas()
{
    return this->armas;
}
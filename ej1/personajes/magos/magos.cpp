#include "magos.hpp"
#include "../../armas/armas.hpp"
#include <vector>
#include <iostream>


Magos::Magos(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int velocidad, bool bajo_efecto, int mana, int mana_max, int nivel, PERSONAJES tipo_personaje) 
{
    this->nombre = nombre;
    this->vida = vida;
    this->ataque = ataque;
    this->defensa_ad = defensa_ad;
    this->defensa_ap = defensa_ap;
    this->velocidad = velocidad;
    this->bajo_efecto = bajo_efecto;
    this->mana = mana;
    this->mana_max = mana_max;
    this->nivel = nivel;
    this->tipo_personaje = tipo_personaje;
    this->armas = pair<unique_ptr<Arma>, unique_ptr<Arma>>(nullptr, nullptr);
}

void Magos::set_mana(int m)
{
    this->mana = m;
}

int Magos::get_mana()
{
    return this->mana;
}

int Magos::get_ataque(unique_ptr<Arma> arma) 
{

    return (this->ataque + arma->danio_(shared_from_this()));
}

int Magos::get_vida() 
{
    return this->vida;
}

string Magos::get_nombre() 
{
    return this->nombre;
}

int Magos::getDefensa_ad() 
{
    return this->defensa_ad;
}

int Magos::getDefensa_ap() 
{
    return this->defensa_ap;
}

int Magos::getNivel() 
{
    return this->nivel;
}

int Magos::getVelocidad() 
{
    return this->velocidad;
}

void Magos::recibir_ataque(int ataque, CLASE tipo)
{
    int danio;
    if (tipo == CLASE::MAGICO)
    {
        danio = ataque - this->defensa_ap;
        if (danio < 0)
        {
            danio = 0;
        }
        this->vida -= danio;
    }
    else
    {
        danio = ataque - this->defensa_ad;
        if (danio < 0)
        {
            danio = 0;
        }
        this->vida -= danio;
    }
}

PERSONAJES Magos::getTipo_personaje() 
{
    return this->tipo_personaje;
}

void Magos::set_nombre(string nombre) 
{
    this->nombre = nombre;
}

void Magos::set_vida(int vida) 
{
    this->vida = vida;
}

void Magos::set_ataque(int ataque) 
{
    this->ataque = ataque;
}

void Magos::set_defensa_ad(int defensa_ad) 
{
    this->defensa_ad = defensa_ad;
}

void Magos::set_defensa_ap(int defensa_ap) 
{
    this->defensa_ap = defensa_ap;
}

void Magos::set_nivel(int nivel) 
{
    this->nivel = nivel;
}

void Magos::set_velocidad(int velocidad) 
{
    this->velocidad = velocidad;
}

void Magos::set_bajo_efecto(bool bajo_efecto) 
{
    this->bajo_efecto = bajo_efecto;
}

void Magos::set_tipo_personaje(PERSONAJES tipo_personaje) 
{
    this->tipo_personaje = tipo_personaje;
}

int Magos::get_vida_max() 
{
    return this->vida_max;
}

void Magos::set_armas(unique_ptr<Arma> arma1, unique_ptr<Arma> arma2) 
{
    this->armas = pair<unique_ptr<Arma>, unique_ptr<Arma>>(move(arma1), move(arma2));
}

pair<unique_ptr<Arma>, unique_ptr<Arma>>& Magos::get_armas() 
{
    return this->armas;
}
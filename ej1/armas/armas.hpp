#ifndef ARMAS_HPP
#define ARMAS_HPP

#include "../personajes/personajes.hpp"

enum class TipoArma {MANOS, HACHA_SIMPLE, HACHA_DOBLE, ESPADA, LANZA, GARROTE, BASTON, LIBRO_HECHIZOS, POCION, AMULETO};

class Arma
{
    public:
        virtual CLASE claseArma() = 0;
        virtual int danio_(shared_ptr<Personaje> usuario) = 0; 
        virtual TipoArma getArma() = 0;    
        virtual string get_nombre() = 0;
        virtual void set_nombre(string nombre) = 0;
};

#endif
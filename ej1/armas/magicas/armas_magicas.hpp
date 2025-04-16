#ifndef ARMAS_MAGICAS_HPP
#define ARMAS_MAGICAS_HPP

#include <iostream>
#include <string>
#include <memory>
#include "../armas.hpp"
#include "../../personajes/personajes.hpp"

using namespace std;

class Arma_magica : public Arma 
{
    protected:
        string nombre;  
        int danio;
        TipoArma tipoArma;
        CLASE tipoDanio;
        int durabilidad;
        int nivel;
        int poder_magico;
    
    public:
        Arma_magica(string nombre,TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico);
        ~Arma_magica() = default;

        int danio_(shared_ptr<Personaje> usuario) override;
        CLASE claseArma() override;
        TipoArma getArma() override;
        string get_nombre() override;
        void set_nombre(string nombre) override;
};

#endif
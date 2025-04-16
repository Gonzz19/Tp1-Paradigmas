#ifndef ARMAS_COMBATE_HPP
#define ARMAS_COMBATE_HPP

#include <iostream>
#include <string>
#include <memory>

#include "../armas.hpp"

using namespace std;

class Personaje;

class Arma_combate : public Arma
{
    protected:
        string nombre;
        int danio;
        TipoArma tipoArma;
        CLASE tipoDanio;
        int durabilidad;
        int nivel;

public:
    Arma_combate(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel);
    ~Arma_combate() = default;

    int danio_(shared_ptr<Personaje> usuario) override;
    CLASE claseArma() override;
    TipoArma getArma() override;
    string get_nombre() override;
    void set_nombre(string nombre) override;
};

#endif
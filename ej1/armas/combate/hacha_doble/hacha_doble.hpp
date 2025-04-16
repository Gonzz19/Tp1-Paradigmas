

#ifndef HACHADOBLE_HPP
#define HACHADOBLE_HPP

#include "../armas_combate.hpp"

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Hacha_doble : public Arma_combate
{
public:
    Hacha_doble(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel);
    ~Hacha_doble();

    void pulir(shared_ptr<Personaje> usuario);
};

#endif
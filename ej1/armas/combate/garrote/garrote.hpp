

#ifndef GARROTE_HPP
#define GARROTE_HPP

#include <iostream>
#include <string>
#include <memory>
#include "../armas_combate.hpp"

using namespace std;

class Garrote : public Arma_combate
{
public:
    Garrote(string nombre,TipoArma tipoArma, int danio, int durabilidad, int nivel);
    ~Garrote();

    void garrotazo(shared_ptr<Personaje> usuario, shared_ptr<Personaje> enemigo);
};

#endif
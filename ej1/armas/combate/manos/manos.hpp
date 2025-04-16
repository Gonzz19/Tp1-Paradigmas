

#ifndef MANOS_HPP
#define MANOS_HPP

#include "../armas_combate.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Manos : public Arma_combate
{
    public:
        Manos(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel);
        ~Manos();

        void manotazo_doble(shared_ptr<Personaje> usuario, shared_ptr<Personaje> enemigo);
        void malabares(shared_ptr<Personaje> usuario);
};

#endif
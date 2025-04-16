

#ifndef ESPADA_HPP
#define ESPADA_HPP

#include "../armas_combate.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Espada : public Arma_combate 
{
    public:
        Espada(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel);
        ~Espada();

        void destructor_de_mundos(shared_ptr<Personaje> usuario);
};

#endif
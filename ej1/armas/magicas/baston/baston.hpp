

#ifndef BASTON_HPP
#define BASTON_HPP

#include <iostream>
#include <string>
#include <memory>
#include "../armas_magicas.hpp"

using namespace std;

class Baston : public Arma_magica
{
    public:
        Baston(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico);
        ~Baston();

        int baston_final();
};

#endif
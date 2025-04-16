

#ifndef LANZA_HPP
#define LANZA_HPP

#include <iostream>
#include <string>
#include <memory>

#include "../armas_combate.hpp"

using namespace std;

class Lanza : public Arma_combate
{   
    private:
        int metros_max;

    public:
        Lanza(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel);
        ~Lanza();

        void lanzar();
};

#endif


#ifndef HACHA_SIMPLE_HPP
#define HACHA_SIMPLE_HPP

#include <iostream>
#include <string>
#include <memory>
#include "../armas_combate.hpp"


using namespace std;

class Hacha_simple : public Arma_combate
{
    private:
        int arboles_talados = 0;

    public:
        Hacha_simple(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel);
        ~Hacha_simple();

        void leniador(shared_ptr<Personaje> usuario);
};

#endif
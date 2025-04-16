

#ifndef AMULETO_HPP
#define AMULETO_HPP

#include "../armas_magicas.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Amuleto : public Arma_magica 
{
    private:
        float peso = 0.5;

    public:
        Amuleto(string nombre,TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico);
        ~Amuleto();

        void usar_proteccion(shared_ptr<Personaje> usuario);
};

#endif
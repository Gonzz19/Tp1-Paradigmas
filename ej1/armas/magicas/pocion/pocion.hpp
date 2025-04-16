

#ifndef POCION_HPP
#define POCION_HPP

#include <iostream>
#include <string>
#include "../armas_magicas.hpp"


using namespace std;

class Pocion : public Arma_magica
{   
    private:
        int unidades;

    public:
        Pocion(string nombre,TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico);
        ~Pocion();

        void lanzar(shared_ptr<Personaje> usuario, shared_ptr<Personaje> enemigo);

};

#endif
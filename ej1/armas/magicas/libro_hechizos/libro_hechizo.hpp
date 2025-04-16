

#ifndef LIBRO_HECHIZO_HPP
#define LIBRO_HECHIZO_HPP

#include <iostream>
#include <string>
#include <memory>

#include "../armas_magicas.hpp"

using namespace std;

class Libro_hechizo : public Arma_magica 
{
    public:
        Libro_hechizo(string nombre,TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico);
        ~Libro_hechizo();

        void ultimo_hechizo();

};

#endif
#include "libro_hechizo.hpp"
#include "../armas_magicas.hpp"

Libro_hechizo::Libro_hechizo(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico) : Arma_magica(nombre, tipoArma, danio, durabilidad, nivel, poder_magico) {}

Libro_hechizo::~Libro_hechizo() 
{
    cout << "Destruyendo libro hechizo: " << endl;
}

void Libro_hechizo::ultimo_hechizo() 
{
    this->durabilidad = 0;
    this->danio = 300;
    this->poder_magico = 150;
    cout << "El libro esta sobrecargado" << endl;
}
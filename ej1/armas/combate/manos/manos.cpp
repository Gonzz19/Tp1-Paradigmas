

#include "manos.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

Manos::Manos(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel)
    : Arma_combate(nombre, tipoArma, danio, durabilidad, nivel) {}

Manos::~Manos() 
{
    cout << "Destructor de Manos (tecnicamente no se pueden destruir, son parte del personaje)" << endl;
}

void Manos::manotazo_doble(shared_ptr<Personaje> usuario, shared_ptr<Personaje> enemigo)
{
    cout << "Manotazo doble!" << endl;
    int danio = danio_(usuario);
    enemigo->recibir_ataque(danio*2, CLASE::FISICO);
}

void Manos::malabares(shared_ptr<Personaje> usuario)
{
    // Easter egg: el malabarista hace malabares con la pelota
    cout << usuario->get_nombre() << " hace malabares con la pelota!" << endl;
}

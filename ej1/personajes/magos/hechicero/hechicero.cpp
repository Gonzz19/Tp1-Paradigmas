#include "hechicero.hpp"
#include "../../../armas/armas.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Hechicero::Hechicero(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto)
    : Magos(nombre, vida, ataque, defensa_ad, defensa_ap, velocidad, bajo_efecto, 200, 200, nivel, PERSONAJES::HECHICERO)
{
    this->edad = 0;
    this->chance_de_morir = 0;
}

Hechicero::~Hechicero()
{
    cout << "El hechicero ha muerto" << endl;
}

void Hechicero::ataque_basico(shared_ptr<Personaje> enemigo)
{
    cout << "El hechicero lanza un ataque basico a " << enemigo->get_nombre() << endl;
    enemigo->recibir_ataque(this->ataque, CLASE::FISICO);
}

void Hechicero::bola_de_fuego(shared_ptr<Personaje> enemigo)
{
    if (this->mana < 50)
    {
        cout << "No tienes suficiente mana para lanzar la bola de fuego" << endl;
        return;
    }
    this->mana -= 50;
    cout << "El hechicero lanza una bola de fuego a " << enemigo->get_nombre() << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first))+ this->edad, CLASE::MAGICO);
}

void Hechicero::congelar(shared_ptr<Personaje> enemigo)
{
    if (this->mana < 40)
    {
        cout << "No tienes suficiente mana para lanzar la bola de fuego" << endl;
        return;
    }
    this->mana -= 40;
    cout << "El hechicero congela a " << enemigo->get_nombre() << endl;
    enemigo->set_bajo_efecto(true);
}

void Hechicero::envejecer()
{
    if (this->edad >= 100)
    {
        cout << "El hechicero ya no puede envejecer mas" << endl;
        return;
    }
        this->edad += 15;
        this->chance_de_morir += 5; 
        cout << "El hechicero ha envejecido, ahora tiene " << this->edad << " años y su probabilidad de morir ha aumentado" << endl;

        int probabilidad = rand() % 100; 
        if (probabilidad < this->chance_de_morir)
        {
            cout << "El hechicero ha muerto debido a su avanzada edad." << endl;
            this->vida = 0;
        }
}

void Hechicero::tormenta_de_fuego(shared_ptr<Personaje> enemigo)
{
    if (this->mana < 100)
    {
        cout << "No tienes suficiente mana para lanzar la bola de fuego" << endl;
        return;
    }
    this->mana -= 100;
    cout << "El hechicero lanza una tormenta de fuego a " << enemigo->get_nombre() << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first)) + this->edad + 200, CLASE::MAGICO);
}

void Hechicero::get_info()
{
    cout << "Habiliadades del hechicero " << this->nombre << ":" << endl;
    cout << "1. Ataque basico" << endl;
    cout << "2. Bola de fuego" << endl;
    cout << "3. Congelar" << endl;
    cout << "4. Recuperar mana" << endl;
    cout << "5. Envejecer" << endl;
    cout << "6. Tormenta de fuego" << endl;
}
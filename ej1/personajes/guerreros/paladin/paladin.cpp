

#include "paladin.hpp"
#include "../guerreros.hpp"
#include "../../../armas/armas.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

Paladin::Paladin(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto) : Guerrero(nombre, vida, ataque, defensa_ad, defensa_ap, nivel, velocidad, bajo_efecto, PERSONAJES::PALADIN)
{
    this->magia = 0;
}

Paladin::~Paladin()
{
    cout << "Destructor Paladin" << endl;
}

void Paladin::get_info()
{
    cout << "Habilidades del Paladin" << endl;
    cout << "1. Ataque Basico" << endl;
    cout << "2. Escudo Impenetrable" << endl;
    cout << "3. Encantamiento" << endl;
    cout << "4. Espada Divina" << endl;
    cout << "5. Enormizar" << endl;
}

void Paladin::ataque_basico(shared_ptr<Personaje> enemigo)
{
    cout << "El paladin ataca con su espada" << endl;
    enemigo->recibir_ataque(this->ataque, CLASE::FISICO);
}

void Paladin::escudo_impenetrable()
{
    cout << "El paladin usa escudo impenetrable" << endl;
    this->defensa_ap += 70;
    this->defensa_ad += 70;
    cout << "Defensa aumentada" << endl;
}

void Paladin::encantamiento()
{
    cout << "El paladin lanza un encantamiento" << endl;
    this->magia += 50;
    cout << "Magia aumentada" << endl;
}

void Paladin::espada_divina(shared_ptr<Personaje> enemigo)
{
    if (this->magia < 50)
    {
        cout << "No tienes suficiente magia para lanzar espada divina" << endl;
        return;
    }
    cout << "El paladin lanza espada divina" << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first)) * this->magia, CLASE::MAGICO);
    this->magia = 0;
}

void Paladin::enormizar()
{
    cout << "El paladin se enormiza" << endl;
    this->vida += 500;
    this->ataque += 150;
    this->defensa_ad += 750;
    this->defensa_ap += 250;
    this->velocidad -= 20;
    this->bajo_efecto = true;
    cout << "Fortaleza aumentada" << endl;
}
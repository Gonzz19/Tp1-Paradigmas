

#include "gladiador.hpp"
#include "../guerreros.hpp"
#include "../../../armas/armas.hpp"
#include <iostream>
#include <string>
#include <memory>


using namespace std;


Gladiador::Gladiador(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto) : Guerrero(nombre, vida, ataque, defensa_ad, defensa_ap, nivel, velocidad, bajo_efecto, PERSONAJES::GLADIADOR) {}

Gladiador::~Gladiador() 
{
    cout << "Destructor Gladiador " << endl;
}

void Gladiador::get_info() 
{
    cout << "Habilidades del Gladiador: " << endl;
    cout << "1. Ataque Basico" << endl;
    cout << "2. Hermanos de Sangre" << endl;
    cout << "3. Heroico" << endl;
    cout << "4. Duelo" << endl;
    cout << "5. Rey de la Arena" << endl;
}

void Gladiador::ataque_basico(shared_ptr<Personaje> enemigo) 
{
    cout << "El gladiador " << this->nombre << " ataca a " << enemigo->get_nombre() << " con un ataque basico." << endl;
    enemigo->recibir_ataque(this->ataque, CLASE::FISICO);
}

void Gladiador::hermanos_de_sangre(shared_ptr<Personaje> enemigo) 
{
    cout << "El gladiador " << this->nombre << " usa Hermanos de Sangre." << endl;
    enemigo->set_defensa_ad(0);
    enemigo->set_defensa_ap(0);
    this->ataque += 10;
    cout << enemigo->get_nombre() << " no tiene defensa." << endl;
    cout << this->nombre << " tiene +10 de ataque." << endl;
}

void Gladiador::heroico() 
{
    cout << "El gladiador " << this->nombre << " usa Heroico." << endl;
    this->ataque += 30;
    this->defensa_ad += 40;
    cout << this->nombre << " tiene +30 de ataque." << endl;
}

void Gladiador::duelo(shared_ptr<Personaje> enemigo) 
{
    cout << "El gladiador " << this->nombre << " usa Duelo." << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first)), CLASE::FISICO);
    cout << this->nombre << " ataca a " << enemigo->get_nombre() << " con un arma." << endl;
}

void Gladiador::rey_de_la_arena(shared_ptr<Personaje> enemigo) 
{
    cout << "El gladiador " << this->nombre << " usa Rey de la Arena." << endl;
    this->ataque += (50 + 10*this->kills);
    if (this->vida < (this->vida_max - 50)) {
        this->vida += 50;
        cout << this->nombre << " tiene +50 de vida." << endl;
    }
    this->defensa_ad += 50;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first)), CLASE::FISICO);
    cout << this->nombre << " tiene +50 de ataque." << endl;
    cout << this->nombre << " tiene +50 de defensa." << endl;
    cout << this->nombre << " ataca a " << enemigo->get_nombre() << " con un arma." << endl;
}


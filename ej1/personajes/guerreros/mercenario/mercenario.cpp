

#include "mercenario.hpp"
#include "../guerreros.hpp"
#include "../../../armas/armas.hpp"
#include <iostream>
#include <string>


using namespace std;


Mercenario::Mercenario(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto) : Guerrero(nombre, vida, ataque, defensa_ad, defensa_ap, nivel, velocidad, bajo_efecto, PERSONAJES::MERCENARIO) {}

Mercenario::~Mercenario() 
{
    cout << "El mercenario ha sido destruido." << endl;
}

void Mercenario::get_info()
{
    cout << "Habilidades del mercenario:" << endl;
    cout << "1. Ataque Basico" << endl;
    cout << "2. Punta de Canion" << endl;
    cout << "3. Avaricia" << endl;
    cout << "4. Disparo de Oro" << endl;
    cout << "5. Lluvia Dorada" << endl;
}

void Mercenario::ataque_basico(shared_ptr<Personaje> enemigo)
{
    cout << "El mercenario " << this->get_nombre() << " ataca a " << enemigo->get_nombre() << " con un ataque basico." << endl;
    enemigo->recibir_ataque(this->ataque, CLASE::FISICO);
}

void Mercenario::punta_de_canion(shared_ptr<Personaje> enemigo)
{
    cout << "El mercenario " << this->get_nombre() << " ataca a " << enemigo->get_nombre() << " con Punta de Canion." << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first)), CLASE::FISICO);
}

void Mercenario::avaricia(shared_ptr<Personaje> enemigo)
{
    cout << "El mercenario " << this->get_nombre() << " recolecta oro" << endl;
    this->oro += 10;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first))*0.5, CLASE::FISICO);
    cout << "El enemigo " << enemigo->get_nombre() << " ha recibido " << this->get_ataque(move(this->armas.first))*0.5 << " de daño." << endl;
}

void Mercenario::disparo_de_oro(shared_ptr<Personaje> enemigo)
{
    cout << "El mercenario " << this->get_nombre() << " ataca a " << enemigo->get_nombre() << " con Disparo de Oro." << endl;
    enemigo->recibir_ataque(this->oro + this->get_ataque(move(this->armas.first)), CLASE::MAGICO);
    cout << "El enemigo " << enemigo->get_nombre() << " ha recibido " << this->oro << " de daño." << endl;
}

void Mercenario::lluvia_dorada(shared_ptr<Personaje> enemigo)
{
    cout << "El mercenario " << this->get_nombre() << " ataca a " << enemigo->get_nombre() << " con Lluvia Dorada." << endl;
    enemigo->recibir_ataque(this->oro*this->get_ataque(move(this->armas.first)), CLASE::MAGICO);
    this->oro = 0;
    cout << "El enemigo " << enemigo->get_nombre() << " ha recibido " << this->oro << " de daño." << endl;
}
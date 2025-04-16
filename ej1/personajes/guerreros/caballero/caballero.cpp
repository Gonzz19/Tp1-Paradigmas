
#include "../guerreros.hpp"
#include "caballero.hpp"
#include "../../../armas/armas.hpp"
#include <iostream>
#include <memory>
#include <string>

Caballero::Caballero(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto) : Guerrero(nombre, vida, ataque, defensa_ad, defensa_ap, nivel, velocidad, bajo_efecto, PERSONAJES::CABALLERO) {}

Caballero::~Caballero()
{
    cout << "Destructor del caballero" << endl;
}

void Caballero::get_info()
{
    cout << "Habilidades del caballero" << endl;
    cout << "1. Ataque basico" << endl;
    cout << "2. Escudo de hierro" << endl;
    cout << "3. Carga de caballo" << endl;
    cout << "4. Golpe de escudo" << endl;
    cout << "5. Catastrofe" << endl;
}

void Caballero::ataque_basico(shared_ptr<Personaje> enemigo)
{
    cout << "El caballero " << this->nombre << " ataca a " << enemigo->get_nombre() << " con un ataque basico" << endl;
    enemigo->recibir_ataque(this->ataque, CLASE::FISICO);
}

void Caballero::escudo_de_hierro(shared_ptr<Personaje> aliado)
{
    cout << "El caballero " << this->nombre << " usa escudo de hierro en " << aliado->get_nombre() << endl;
    aliado->set_defensa_ad(aliado->getDefensa_ad() + 50);
    cout << "La defensa de " << aliado->get_nombre() << " aumenta en 50" << endl;
    cout << "La defensa de " << aliado->get_nombre() << " es ahora " << aliado->getDefensa_ad() << endl;
}

void Caballero::carga_de_caballo(shared_ptr<Personaje> enemigo)
{
    cout << "El caballero " << this->nombre << " carga a " << enemigo->get_nombre() << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first))*2, CLASE::FISICO);
}

void Caballero::golpe_de_escudo(shared_ptr<Personaje> enemigo)
{
    cout << "El caballero " << this->nombre << " golpea a " << enemigo->get_nombre() << " con su escudo" << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first)), CLASE::FISICO);
}

void Caballero::catastrofe(shared_ptr<Personaje> enemigo)
{
    cout << "El caballero " << this->nombre << " lanza una catastrofe sobre " << enemigo->get_nombre() << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first))*3, CLASE::MAGICO);
}


#include "barbaro.hpp"
#include "../../../armas/armas.hpp"
#include <iostream>
#include <string>
#include <memory>


using namespace std;


Barbaro::Barbaro(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto) : Guerrero(nombre, vida, ataque, defensa_ad, defensa_ap, nivel, velocidad, bajo_efecto, PERSONAJES::BARBARO) {}

Barbaro::~Barbaro()
{
    cout << "El barbaro ha sido destruido." << endl; 
}

void Barbaro::get_info()
{
    cout << "Habilidad de Barbaro " << this->nombre << ":" <<endl;
    cout << "1. Ataque Basico" << endl; 
    cout << "2. Furia Barbaro" << endl;
    cout << "3. Ultimo Aliento" << endl;
    cout << "4. Espada de Dos Manos" << endl;
    cout << "5. Embestida Final" << endl;
}

void Barbaro::ataque_basico(shared_ptr<Personaje> enemigo)
{
    cout << "El barbaro " << this->nombre << " ataca a " << enemigo->get_nombre() << " con un ataque basico." << endl;
    enemigo->recibir_ataque(this->ataque, CLASE::FISICO);
}

void Barbaro::furia_bárbara()
{
    cout << "El barbaro " << this->nombre << " lanza Furia Barbaro." << endl;
    this->bajo_efecto = true;
    if (this->bajo_efecto)
    {
        this->ataque += 30;
        cout << "El ataque del barbaro " << this->nombre << " aumenta a " << this->ataque << "." << endl;
    }
}

void Barbaro::ultimo_aliento()
{
    if (this->vidas_max > 0)
    {
        cout << "El barbaro " << this->nombre << " lanza Ultimo Aliento." << endl;
        this->vidas_max--;
        this->vida += 50;
        cout << "El barbaro " << this->nombre << " recupera 50 de vida. Vida actual: " << this->vida << "." << endl;
    }
    else
    {
        cout << "El barbaro " << this->nombre << " no puede usar Ultimo Aliento." << endl;
    }
}

void Barbaro::espada_de_dos_manos(shared_ptr<Personaje> enemigo)
{
    cout << "El barbaro " << this->nombre << " lanza Espada de Dos Manos." << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first))*2, CLASE::FISICO);
}

void Barbaro::embestida_final(shared_ptr<Personaje> enemigo)
{
    cout << "El barbaro " << this->nombre << " lanza Embestida Final." << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first))*4, CLASE::FISICO);
}
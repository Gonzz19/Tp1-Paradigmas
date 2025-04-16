#include "brujo.hpp"
#include "../../../armas/armas.hpp"
#include <iostream>

using namespace std;

Brujo::Brujo(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto)
    : Magos(nombre, vida, ataque, defensa_ad, defensa_ap, velocidad, bajo_efecto, 250, 250, nivel, PERSONAJES::BRUJO)
{
    this->nombre_demonio = "Demonio de la noche";
    this->vida_demonio = 2500;
    this->ataque_demonio = 300;
    this->defensa_demonio = 200;
    this->velocidad_demonio = 400;
    this->tiempo_posecion = 3;
}

Brujo::~Brujo()
{
    cout << "El brujo ha sido destruido." << endl;
}

void Brujo::ataque_basico(shared_ptr<Personaje> enemigo)
{
   
    cout << "El brujo " << this->nombre << " ataca a " << enemigo->get_nombre() << " con su ataque basico." << endl;
    enemigo->recibir_ataque(this->ataque, CLASE::FISICO);
    cout << "El brujo " << this->nombre << " le hace " << this->ataque << " de daño a " << enemigo->get_nombre() << "." << endl;
    cout << enemigo->get_nombre() << " le queda " << enemigo->get_vida() << " de vida." << endl;
}

void Brujo::maldicion(shared_ptr<Personaje> enemigo, MALDICIONES maldicion)
{
   
    cout << "El brujo " << this->nombre << " lanza una maldicion a " << enemigo->get_nombre() << "." << endl;
    switch (maldicion)
    {
        case CONFUCION:
            cout << "Confusion!" << endl;
            break;
        case PARALISIS:
            cout << "Paralisis!" << endl;
            break;
        case SUENIO:
            cout << "Suenio!" << endl;
            break;
        case MIEDO:
            cout << "Miedo!" << endl;
            break;
    }
    cout << enemigo->get_nombre() << " queda afectado por la maldicion." << endl;
}

void Brujo::escudo_sombrio(shared_ptr<Personaje> aliado)
{
    if (this->mana < 20)
    {
        cout << "El brujo " << this->nombre << " no tiene suficiente mana para lanzar el escudo sombrio." << endl;
        return;
    }
    this->mana -= 20;
    cout << "El brujo " << this->nombre << " lanza un escudo sombrio a " << aliado->get_nombre() << "." << endl;
    aliado->set_defensa_ap(aliado->getDefensa_ap() + 40);
    cout << aliado->get_nombre() << " ahora tiene " << aliado->getDefensa_ap() << " de defensa." << endl;
}

void Brujo::ataque_oscuro(shared_ptr<Personaje> enemigo)
{
    if (this->mana < 30)
    {
        cout << "El brujo " << this->nombre << " no tiene suficiente mana para lanzar el ataque oscuro." << endl;
        return;
    }
    this->mana -= 30;
    cout << "El brujo " << this->nombre << " lanza un ataque oscuro a " << enemigo->get_nombre() << "." << endl;  enemigo->recibir_ataque(this->get_ataque(move(this->armas.first)), CLASE::MAGICO);
    cout << "El brujo " << this->nombre << " le hace " << this->get_ataque(move(this->armas.first)) << " de daño a " << enemigo->get_nombre() << "." << endl;
    cout << enemigo->get_nombre() << " le queda " << enemigo->get_vida() << " de vida." << endl;
}

void Brujo::posecion_demoniaca()
{
    cout << "El brujo " << this->nombre << " se deja poseer por su demonio." << endl;
    this->vida += this->vida_demonio;
    this->ataque += this->ataque_demonio;
    this->defensa_ad += this->defensa_demonio;
    this->velocidad += this->velocidad_demonio;
    cout << "El brujo " << this->nombre << " ahora tiene " << this->vida << " de vida, " << this->ataque << " de ataque, " << this->defensa_ad << " de defensa y " << this->velocidad << " de velocidad." << endl;
}

void Brujo::get_info()
{
    cout << "Habilidades del brujo " << this->nombre << ":" << endl;
    cout << "1. Ataque basico" << endl;
    cout << "2. Maldicion" << endl;
    cout << "3. Escudo sombrio" << endl;
    cout << "4. Ataque oscuro" << endl;
    cout << "5. Posecion demonica" << endl;
}
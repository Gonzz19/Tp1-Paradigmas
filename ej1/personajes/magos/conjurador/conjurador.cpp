#include "conjurador.hpp"
#include "../../../armas/armas.hpp"
#include <iostream>
#include <memory>
#include <string>

#define DANIO_ANIMAL 50

using namespace std;


Conjurador::Conjurador(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto)
    : Magos(nombre, vida, ataque, defensa_ad, defensa_ap, velocidad, bajo_efecto, 300, 300, nivel, PERSONAJES::CONJURADOR)
{
    this->recarga_curacion = 3;
}

Conjurador::~Conjurador()
{
    cout << "El conjurador ha sido destruido." << endl;
}

void Conjurador::ataque_basico(shared_ptr<Personaje> enemigo)
{
    cout << "El conjurador " << this->get_nombre() << " lanza un ataque basico a " << enemigo->get_nombre() << endl;
    enemigo->recibir_ataque(this->ataque, CLASE::FISICO);
    cout << "El conjurador " << this->get_nombre() << " le hace " << this->ataque << " de daño a " << enemigo->get_nombre() << endl;
    cout << "La vida de " << enemigo->get_nombre() << " es " << enemigo->get_vida() << endl;
}

void Conjurador::invocar(shared_ptr<Personaje> aliado, MASCOTAS mascota)
{
    cout << "El conjurador " << this->get_nombre() << " invoca a su mascota" << endl;
    switch (mascota)
    {
        case LOBO:
            cout << "Un lobo aparece para ayudar a " << aliado->get_nombre() << endl;
            break;
        case AGUILA:
            cout << "Un aguila aparece para ayudar a " << aliado->get_nombre() << endl;
            break;
        case TIBURON:
            cout << "Un tiburon aparece para ayudar a " << aliado->get_nombre() << endl;
            break;
        case SERPIENTE:
            cout << "Una serpiente aparece para ayudar a " << aliado->get_nombre() << endl;
            break;
    }
}

void Conjurador::ataque_coordinado(shared_ptr<Personaje> enemigo, MASCOTAS mascota)
{
    if (this->mana < 20)
    {
        cout << "El conjurador " << this->get_nombre() << " no tiene suficiente mana para lanzar el ataque coordinado" << endl;
        return;
    }
    this->mana -= 20;
    cout << "El conjurador " << this->get_nombre() << " lanza un ataque coordinado con su mascota" << endl;
    switch (mascota)
    {
        case LOBO:
            cout << "El lobo ataca a " << enemigo->get_nombre() << endl;
            break;
        case AGUILA:
            cout << "El aguila ataca a " << enemigo->get_nombre() << endl;
            break;
        case TIBURON:
            cout << "El tiburon ataca a " << enemigo->get_nombre() << endl;
            break;
        case SERPIENTE:
            cout << "La serpiente ataca a " << enemigo->get_nombre() << endl;
            break;
    }
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first)) + DANIO_ANIMAL, CLASE::MAGICO);
}

void Conjurador::curacion_espiritual(shared_ptr<Personaje> aliado)
{
    if (this->recarga_curacion > 0)
    {
        cout << "El conjurador " << this->get_nombre() << " no puede usar la curacion espiritual" << endl;
        return;
    }
    this->recarga_curacion = 3;
    cout << "El conjurador " << this->get_nombre() << " lanza la curacion espiritual a " << aliado->get_nombre() << endl;
    aliado->set_vida(aliado->get_vida() + 20);
    cout << "La vida de " << aliado->get_nombre() << " es " << aliado->get_vida() << endl;
}

void Conjurador::rey_de_las_calamidades(shared_ptr<Personaje> enemigo)
{
    if (this->mana < 90)
    {
        cout << "El conjurador " << this->get_nombre() << " no tiene suficiente mana para lanzar el rey de las calamidades" << endl;
        return;
    }
    this->mana -= 90;
    cout << "El conjurador " << this->get_nombre() << " lanza el rey de las calamidades a " << enemigo->get_nombre() << endl;
    enemigo->recibir_ataque(this->get_ataque(move(this->armas.first)), CLASE::MAGICO);
    cout << "La vida de " << enemigo->get_nombre() << " es " << enemigo->get_vida() << endl;
}

void Conjurador::get_info()
{
    cout << "Habilitades del conjurador " << this->get_nombre() << endl;
    cout << "1. Ataque basico" << endl;
    cout << "2. Invocar" << endl;
    cout << "3. Ataque coordinado" << endl;
    cout << "4. Curacion espiritual" << endl;
    cout << "5. Rey de las calamidades" << endl;
}

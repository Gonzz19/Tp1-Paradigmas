#include "nicromante.hpp"
#include "../../../armas/armas.hpp"


Nicromante::Nicromante(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto)
    : Magos(nombre, vida, ataque, defensa_ad, defensa_ap, velocidad, bajo_efecto, 400, 400, nivel, PERSONAJES::NICROMANTE)
{
    this->invocaciones = 0;
}

Nicromante::~Nicromante()
{
    cout << "El nicromante ha muerto" << endl;
}

void Nicromante::invocacion_mas_alla(ESQUELETOS esqueleto)
{
    if (this->invocaciones < this->max_invocaciones)
    {
        this->invocaciones++;
        cout << "Invocando un esqueleto de tipo: " << esqueleto << endl;
    }
    else
    {
        cout << "No se pueden invocar mas esqueletos" << endl;
    }
}

void Nicromante::ataque_basico(shared_ptr<Personaje> enemigo)
{
    cout << "El nicromante " << this->get_nombre() << " ataca a " << enemigo->get_nombre() << " con su ataque basico" << endl;
    enemigo->recibir_ataque(this->ataque, CLASE::FISICO);
    cout << "El enemigo " << enemigo->get_nombre() << " ahora tiene " << enemigo->get_vida() << " de vida" << endl;
}

void Nicromante::huesos_de_hierro(shared_ptr<Personaje> aliado)
{
    cout << "El nicromante " << this->get_nombre() << " usa huesos de hierro en " << aliado->get_nombre() << endl;
    aliado->set_defensa_ad(aliado->getDefensa_ad()+ (15 * this->invocaciones));
    cout << "La defensa de " << aliado->get_nombre() << " ahora es de " << aliado->getDefensa_ad() << endl;
}

void Nicromante::drenaje_de_vida(shared_ptr<Personaje> enemigo)
{
    cout << "El nicromante " << this->get_nombre() << " usa drenaje de vida en " << enemigo->get_nombre() << endl;
    this->vida += (this->ataque / 2);
    enemigo->set_vida(enemigo->get_vida() - (this->ataque / 2));
    cout << "El nicromante " << this->get_nombre() << " ahora tiene " << this->get_vida() << " de vida" << endl;
    cout << "El enemigo " << enemigo->get_nombre() << " ahora tiene " << enemigo->get_vida() << " de vida" << endl;
}

void Nicromante::resucitar(shared_ptr<Personaje> aliado)
{
    if (aliado->get_vida() == 0)
    {
        cout << "El nicromante " << this->get_nombre() << " resucita a " << aliado->get_nombre() << endl;
        aliado->set_vida(aliado->get_vida_max());
        cout << "El aliado " << aliado->get_nombre() << " ahora tiene " << aliado->get_vida() << " de vida" << endl;
    }
    else
    {
        cout << "El aliado " << aliado->get_nombre() << " no esta muerto" << endl;
    }
}

void Nicromante::get_info()
{
    cout << "Habilidades del nicromante " << this->get_nombre() << ":" << endl;
    cout << "1. Invocacion mas alla" << endl;
    cout << "2. Ataque basico" << endl;
    cout << "3. Huesos de hierro" << endl;
    cout << "4. Drenaje de vida" << endl;
    cout << "5. Resucitar" << endl;
}
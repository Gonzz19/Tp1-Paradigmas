#include "pocion.hpp"


Pocion::Pocion(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico) : Arma_magica(nombre, tipoArma, danio, durabilidad, nivel, poder_magico) 
{
    this->unidades = 10;
}

Pocion::~Pocion() 
{
    cout << "Destruyendo pocion" << endl;
}

void Pocion::lanzar(shared_ptr<Personaje> usuario, shared_ptr<Personaje> enemigo) 
{
    if (this->unidades > 0) 
    {
        cout << usuario->get_nombre() << " lanza la pocion  a " << enemigo->get_nombre() << endl;
        enemigo->recibir_ataque(this->danio_(usuario), CLASE::MAGICO);
        this->unidades--;
        cout << "Quedan " << this->unidades << " pociones." << endl;
    } 
    else 
    {
        cout << usuario->get_nombre() << " no tiene pociones para lanzar." << endl;
    }
}
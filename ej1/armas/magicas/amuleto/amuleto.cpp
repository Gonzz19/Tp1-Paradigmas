#include "amuleto.hpp"
#include "../armas_magicas.hpp"


Amuleto::Amuleto(string nombre, TipoArma tipoArma, int danio, int durabilidad, int nivel, int poder_magico)
    : Arma_magica(nombre, tipoArma, danio, durabilidad, nivel, poder_magico) {}

Amuleto::~Amuleto() 
{
    cout << "Destructor de Amuleto" << endl;
}

void Amuleto::usar_proteccion(shared_ptr<Personaje> usuario) 
{
    cout << "El amuleto protege a " << usuario->get_nombre() << " de los ataques mágicos." << endl;
    usuario->set_defensa_ap(usuario->getDefensa_ap() + 500);
    this->durabilidad = 0;
    cout << "Defensa aumentada a: " << usuario->getDefensa_ap() << endl;    
}
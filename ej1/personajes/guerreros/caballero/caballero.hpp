

#ifndef CABALLERO_HPP
#define CABALLERO_HPP

#include "../guerreros.hpp"


using namespace std;


class Caballero : public Guerrero
{   
    public:
        Caballero(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto);
        ~Caballero();

        void get_info() override;

        void ataque_basico(shared_ptr<Personaje> enemigo) override;
        void escudo_de_hierro(shared_ptr<Personaje> aliado);
        void carga_de_caballo(shared_ptr<Personaje> enemigo);
        void golpe_de_escudo(shared_ptr<Personaje> enemigo);

        void catastrofe(shared_ptr<Personaje> enemigo);
};

#endif
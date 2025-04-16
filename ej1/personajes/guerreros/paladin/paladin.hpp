

#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "../guerreros.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Paladin : public Guerrero 
{
    private:
        int magia;

    public:
        Paladin(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto);
        ~Paladin();

        void get_info() override;
        
        void ataque_basico(shared_ptr<Personaje> enemigo) override;
        void escudo_impenetrable();
        void encantamiento();
        void espada_divina(shared_ptr<Personaje> enemigo);

        void enormizar();

};

#endif
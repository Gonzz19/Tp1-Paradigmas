

#ifndef GLADIADOR_HPP
#define GLADIADOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include "../guerreros.hpp"

using namespace std;

class Gladiador : public Guerrero 
{
    private:
        int kills = 0;

    public:
        Gladiador(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto);
        ~Gladiador();

        void get_info() override;
        void ataque_basico(shared_ptr<Personaje> enemigo) override;
        void hermanos_de_sangre(shared_ptr<Personaje> enemigo);
        void heroico();
        void duelo(shared_ptr<Personaje> enemigo);

        void rey_de_la_arena(shared_ptr<Personaje> enemigo);

};

#endif
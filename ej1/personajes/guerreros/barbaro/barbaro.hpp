

#ifndef BARBARO_HPP
#define BARBARO_HPP

#include "../guerreros.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Barbaro : public Guerrero
{
    private:
        int vidas_max = 2;
    
    public:
        Barbaro(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto);
        ~Barbaro();

        void get_info() override;

        void ataque_basico(shared_ptr<Personaje> enemigo) override;
        void furia_bárbara();
        void ultimo_aliento();
        void espada_de_dos_manos(shared_ptr<Personaje> enemigo);

        void embestida_final(shared_ptr<Personaje> enemigo);   
};

#endif
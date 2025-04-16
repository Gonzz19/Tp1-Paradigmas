

#ifndef HECHICERO_HPP
#define HECHICERO_HPP


#include "../magos.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Hechicero : public Magos
{
    private:
        int edad;
        int chance_de_morir;

    public:
        Hechicero(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto);
        ~Hechicero();

        void get_info() override;

        // ataques basicos
        void ataque_basico(shared_ptr<Personaje> enemigo) override;
        void bola_de_fuego(shared_ptr<Personaje> enemigo);
        void congelar(shared_ptr<Personaje> enemigo);
        void envejecer();


        // ulti
        void tormenta_de_fuego(shared_ptr<Personaje> enemigo);
};

#endif
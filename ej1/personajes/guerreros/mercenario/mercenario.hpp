
#ifndef MERCENARIO_HPP
#define MERCENARIO_HPP


#include "../guerreros.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Mercenario : public Guerrero 
{
    private:
        int oro = 0;
    
    public:
        Mercenario(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto);
        ~Mercenario();

        void get_info() override;
        
        void ataque_basico(shared_ptr<Personaje> enemigo) override;
        void punta_de_canion(shared_ptr<Personaje> enemigo);
        void avaricia(shared_ptr<Personaje> enemigo);
        void disparo_de_oro(shared_ptr<Personaje> enemigo);

        void lluvia_dorada(shared_ptr<Personaje> enemigo);
};

#endif


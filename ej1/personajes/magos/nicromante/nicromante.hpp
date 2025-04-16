#ifndef NICROMANTE_HPP
#define NICROMANTE_HPP


#include "../magos.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

enum ESQUELETOS {CABALLERO, GUERRERO, MAGO, ARQUERO};   

class Nicromante : public Magos 
{
    private:
        const int max_invocaciones = 10;
        int invocaciones;

    public:
        Nicromante(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto);
        ~Nicromante();

        void get_info() override;
        
        void invocacion_mas_alla(ESQUELETOS esqueleto);
        void ataque_basico(shared_ptr<Personaje> enemigo) override;
        void huesos_de_hierro(shared_ptr<Personaje> aliado);
        void drenaje_de_vida(shared_ptr<Personaje> enemigo);

        void resucitar(shared_ptr<Personaje> aliado);

};  

#endif
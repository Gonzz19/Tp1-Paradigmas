

#ifndef BRUJO_HPP
#define BRUJO_HPP

#include "../magos.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

enum MALDICIONES {CONFUCION, PARALISIS, SUENIO, MIEDO};

class Brujo : public Magos
{
    private:
        string nombre_demonio;
        int vida_demonio;
        int ataque_demonio;
        int defensa_demonio;
        int velocidad_demonio;
        int tiempo_posecion;

    public:
        Brujo(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto);
        ~Brujo();
        
        void get_info() override;

        // ataques basicos
        void ataque_basico(shared_ptr<Personaje> enemigo) override;
        void maldicion(shared_ptr<Personaje> enemigo, MALDICIONES maldicion);
        void escudo_sombrio(shared_ptr<Personaje> aliado);
        void ataque_oscuro(shared_ptr<Personaje> enemigo);

        //ulti
        void posecion_demoniaca();
};

#endif 
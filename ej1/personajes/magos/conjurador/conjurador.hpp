

#ifndef CONJURADOR_HPP
#define CONJURADOR_HPP

#include "../magos.hpp"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

enum MASCOTAS {LOBO, AGUILA, TIBURON, SERPIENTE};

class Conjurador : public Magos
{
    private:
        int recarga_curacion;

    public:
        Conjurador(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto);
        ~Conjurador();

        void get_info() override;

        // ataques basicos
        void ataque_basico(shared_ptr<Personaje> enemigo) override;
        void invocar(shared_ptr<Personaje> aliado, MASCOTAS mascota);
        void ataque_coordinado(shared_ptr<Personaje> enemigo, MASCOTAS mascota);
        void curacion_espiritual(shared_ptr<Personaje> aliado);

        // ulti
        void rey_de_las_calamidades(shared_ptr<Personaje> enemigo);
};

#endif

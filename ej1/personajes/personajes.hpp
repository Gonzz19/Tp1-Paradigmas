#ifndef PERSONAJES_HPP
#define PERSONAJES_HPP

#include <string>
#include <memory>
#include <vector>
using namespace std;


enum class PERSONAJES {HECHICERO, CONJURADOR, BRUJO, NICROMANTE, MERCENARIO, PALADIN, CABALLERO, BARBARO, GLADIADOR};

enum CLASE {FISICO, MAGICO};

class Arma;

class Personaje 
{
    public:
        virtual ~Personaje() = default;
        virtual void ataque_basico(shared_ptr<Personaje> enemigo) = 0;
        virtual int get_ataque(unique_ptr<Arma> arma) = 0;
        virtual int get_vida() = 0;
        virtual int get_vida_max() = 0;
        virtual string get_nombre() = 0;
        virtual int getDefensa_ad() = 0;
        virtual int getDefensa_ap() = 0;
        virtual int getNivel() = 0;
        virtual int getVelocidad() = 0;
        virtual PERSONAJES getTipo_personaje() = 0;
        virtual void recibir_ataque(int ataque, CLASE tipo) = 0;      
        virtual void set_nombre(string nombre) = 0;
        virtual void set_vida(int vida) = 0;
        virtual void set_ataque(int ataque) = 0;
        virtual void set_defensa_ad(int defensa_ad) = 0;
        virtual void set_defensa_ap(int defensa_ap) = 0;
        virtual void set_nivel(int nivel) = 0;
        virtual void set_velocidad(int velocidad) = 0;
        virtual void set_bajo_efecto(bool bajo_efecto) = 0;
        virtual void set_tipo_personaje(PERSONAJES tipo_personaje) = 0;
        virtual void set_armas(unique_ptr<Arma> arma1, unique_ptr<Arma> arma2) = 0;
        virtual pair<unique_ptr<Arma>, unique_ptr<Arma>>& get_armas() = 0;
};

#endif

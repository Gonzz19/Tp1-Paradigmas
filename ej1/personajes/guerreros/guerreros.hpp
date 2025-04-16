#ifndef GUERREROS_HPP
#define GUERREROS_HPP

#include "../personajes.hpp"

class Guerrero : public Personaje, public std::enable_shared_from_this<Guerrero>
{
    protected:
        string nombre;
        int vida;
        int vida_max;
        int ataque;
        int defensa_ad;
        int defensa_ap;
        int nivel;
        int velocidad;
        pair<unique_ptr<Arma>, unique_ptr<Arma>> armas;
        bool bajo_efecto;
        int estamina;
        int estamina_max;
        PERSONAJES tipo_personaje; 
    
    public:
        Guerrero(string nombre, int vida, int ataque, int defensa_ad, int defensa_ap, int nivel, int velocidad, bool bajo_efecto, PERSONAJES tipo_personaje);
        virtual ~Guerrero(); 

        virtual void get_info() = 0;
        
        void set_estamina(int e);
        int get_estamina();
        int get_ataque(unique_ptr<Arma> arma);
        int get_vida();
        string get_nombre();
        int getDefensa_ad();
        int getDefensa_ap();
        int getNivel();
        int getVelocidad();
        void recibir_ataque(int ataque, CLASE tipo);
        PERSONAJES getTipo_personaje();
        void set_nombre(string nombre);
        void set_vida(int vida);
        void set_ataque(int ataque);
        void set_defensa_ad(int defensa_ad);
        void set_defensa_ap(int defensa_ap);
        void set_nivel(int nivel);
        void set_velocidad(int velocidad);
        void set_bajo_efecto(bool bajo_efecto);
        void set_tipo_personaje(PERSONAJES tipo_personaje);
        int get_vida_max();
        void set_armas(unique_ptr<Arma> arma1, unique_ptr<Arma> arma2);
        pair<unique_ptr<Arma>, unique_ptr<Arma>>& get_armas();
};

#endif
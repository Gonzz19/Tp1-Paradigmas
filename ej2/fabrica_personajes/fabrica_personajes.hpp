#ifndef FABRICA_PERSONAJES_HPP
#define FABRICA_PERSONAJES_HPP

#include <iostream>
#include <memory>
#include <string>
#include "../../ej1/personajes/magos/brujo/brujo.hpp"
#include "../../ej1/personajes/magos/hechicero/hechicero.hpp"
#include "../../ej1/personajes/magos/conjurador/conjurador.hpp"
#include "../../ej1/personajes/magos/nicromante/nicromante.hpp"

#include "../../ej1/personajes/guerreros/barbaro/barbaro.hpp"
#include "../../ej1/personajes/guerreros/caballero/caballero.hpp"
#include "../../ej1/personajes/guerreros/gladiador/gladiador.hpp"
#include "../../ej1/personajes/guerreros/mercenario/mercenario.hpp"
#include "../../ej1/personajes/guerreros/paladin/paladin.hpp"

#include "../../ej1/armas/magicas/amuleto/amuleto.hpp"
#include "../../ej1/armas/magicas/baston/baston.hpp"
#include "../../ej1/armas/magicas/libro_hechizos/libro_hechizo.hpp"
#include "../../ej1/armas/magicas/pocion/pocion.hpp"

#include "../../ej1/armas/combate/espada/espada.hpp"
#include "../../ej1/armas/combate/garrote/garrote.hpp"
#include "../../ej1/armas/combate/hacha_doble/hacha_doble.hpp"
#include "../../ej1/armas/combate/lanza/lanza.hpp"
#include "../../ej1/armas/combate/hacha_simple/hacha_simple.hpp"
#include "../../ej1/armas/combate/manos/manos.hpp"

using namespace std;

class FabricaPersonajes 
{
    public:
        static shared_ptr<Personaje> crear_personaje(PERSONAJES tipo);
        static unique_ptr<Arma> crear_arma(TipoArma tipo);
        static shared_ptr<Personaje> equipar_personaje(shared_ptr<Personaje> personaje, unique_ptr<Arma> arma1, unique_ptr<Arma> arma2);
};

#endif

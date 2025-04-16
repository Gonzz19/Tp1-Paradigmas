#include "fabrica_personajes.hpp"
#include "../../ej1/personajes/personajes.hpp"
#include "../../ej1/armas/armas.hpp"

using namespace std;

shared_ptr<Personaje> FabricaPersonajes::crear_personaje(PERSONAJES tipo) {
    switch (tipo) {
        case PERSONAJES::BRUJO:
            return make_shared<Brujo>("Brujo", 100, 50, 20, 15, 1, 10, false);
        case PERSONAJES::HECHICERO:
            return make_shared<Hechicero>("Hechicero", 90, 40, 15, 20, 1, 12, false);
        case PERSONAJES::NICROMANTE:
            return make_shared<Nicromante>("Nicromante", 80, 45, 18, 18, 1, 11, false);
        case PERSONAJES::CONJURADOR:
            return make_shared<Conjurador>("Conjurador", 85, 35, 17, 19, 1, 13, false);
        case PERSONAJES::BARBARO:
            return make_shared<Barbaro>("Barbaro", 120, 60, 25, 10, 1, 8, false);
        case PERSONAJES::CABALLERO:
            return make_shared<Caballero>("Caballero", 110, 55, 30, 12, 1, 9, false);
        case PERSONAJES::GLADIADOR:
            return make_shared<Gladiador>("Gladiador", 115, 58, 28, 11, 1, 10, false);
        case PERSONAJES::MERCENARIO:
            return make_shared<Mercenario>("Mercenario", 100, 50, 22, 14, 1, 10, false);
        case PERSONAJES::PALADIN:
            return make_shared<Paladin>("Paladin", 130, 65, 35, 20, 1, 7, false);
        default:
            throw invalid_argument("Tipo de personaje no válido");
    }
}

unique_ptr<Arma> FabricaPersonajes::crear_arma(TipoArma tipo) {
    switch (tipo) {
        case TipoArma::AMULETO:
            return make_unique<Amuleto>("Amuleto", TipoArma::AMULETO, 10, 100, 1, 20);
        case TipoArma::BASTON:
            return make_unique<Baston>("Baston", TipoArma::BASTON, 15, 80, 1, 25);
        case TipoArma::LIBRO_HECHIZOS:
            return make_unique<Libro_hechizo>("Libro de Hechizos", TipoArma::LIBRO_HECHIZOS, 20, 70, 1, 30);
        case TipoArma::POCION:
            return make_unique<Pocion>("Pocion", TipoArma::POCION, 5, 50, 1, 10);
        case TipoArma::ESPADA:
            return make_unique<Espada>("Espada", TipoArma::ESPADA, 25, 90, 1);
        case TipoArma::GARROTE:
            return make_unique<Garrote>("Garrote", TipoArma::GARROTE, 20, 85, 1);
        case TipoArma::HACHA_SIMPLE:
            return make_unique<Hacha_simple>("Hacha Simple", TipoArma::HACHA_SIMPLE, 30, 80, 1);
        case TipoArma::HACHA_DOBLE:
            return make_unique<Hacha_doble>("Hacha Doble", TipoArma::HACHA_DOBLE, 35, 75, 1);
        case TipoArma::LANZA:
            return make_unique<Lanza>("Lanza", TipoArma::LANZA, 28, 85, 1);
        case TipoArma::MANOS:
            return make_unique<Manos>("Manos", TipoArma::MANOS, 10, 100, 1);
        default:
            throw invalid_argument("Tipo de arma no válido");
    }
}

shared_ptr<Personaje> FabricaPersonajes::equipar_personaje(shared_ptr<Personaje> personaje, unique_ptr<Arma> arma1, unique_ptr<Arma> arma2) 
{
    personaje->set_armas(move(arma1), move(arma2));
    return personaje;
}


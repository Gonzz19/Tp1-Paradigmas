
#include <iostream>
#include <cstdlib> 
#include <ctime>    

#include "../ej2/fabrica_personajes/fabrica_personajes.hpp"

enum Ataque { GOLPE_FUERTE = 1, GOLPE_RAPIDO, DEFENSA_Y_GOLPE };

string ataque_to_string(Ataque a) 
{
    switch (a) 
    {
        case GOLPE_FUERTE: return "Golpe Fuerte";
        case GOLPE_RAPIDO: return "Golpe Rápido";
        case DEFENSA_Y_GOLPE: return "Defensa y Golpe";
        default: return "Desconocido";
    }
}

int calcularDanio(Ataque a1, Ataque a2) 
{
    if (a1 == a2) return 0;
    if ((a1 == GOLPE_FUERTE && a2 == GOLPE_RAPIDO) || (a1 == GOLPE_RAPIDO && a2 == DEFENSA_Y_GOLPE) || (a1 == DEFENSA_Y_GOLPE && a2 == GOLPE_FUERTE)) 
    {
        return 10;
    }
    return 0;
}

int main()
{
    srand(time(0));

    // Los personajes se llaman mago y guerrero, porque antes solo estaba probando entre ellos.
    int num = rand() % 9;
    PERSONAJES tipo_mago = static_cast<PERSONAJES>(num);
    shared_ptr<Personaje> mago = FabricaPersonajes::crear_personaje(tipo_mago);

    int num_armas = rand() % 3;
    if (num_armas == 0)
    {
        unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
        unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
        mago->set_armas(move(arma1), move(arma2));
    }
    else if (num_armas == 1)
    {
        unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
        int num_arma2 = rand() % 10;
        unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(num_arma2));
        mago->set_armas(move(arma1), move(arma2));
    }
    else
    {
        int num_arma1 = rand() % 10;
        int num_arma2 = rand() % 10;
        unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(num_arma1));
        unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(num_arma2));
        mago->set_armas(move(arma1), move(arma2));
    }

    int num2 = rand() % 9;
    PERSONAJES tipo_guerrero = static_cast<PERSONAJES>(num2);
    shared_ptr<Personaje> guerrero = FabricaPersonajes::crear_personaje(tipo_guerrero);
    int num_armas2 = rand() % 3;
    if (num_armas2 == 0)
    {
        unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
        unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
        guerrero->set_armas(move(arma1), move(arma2));
    }
    else if (num_armas2 == 1)
    {
        unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
        int num_arma2 = rand() % 10;
        unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(num_arma2));
        guerrero->set_armas(move(arma1), move(arma2));
    }
    else
    {
        int num_arma1 = rand() % 10;
        int num_arma2 = rand() % 10;
        unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(num_arma1));
        unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(num_arma2));
        guerrero->set_armas(move(arma1), move(arma2));
    }
    pair<unique_ptr<Arma>, unique_ptr<Arma>>& armas = mago->get_armas();
    pair<unique_ptr<Arma>, unique_ptr<Arma>>& armas2 = guerrero->get_armas();
    int arma_elg;
    cout << "Arma a utilizr: " << endl;
    cout << "1) " << armas.first->get_nombre() << endl;
    cout << "2) " << armas.second->get_nombre() << endl;
    cin >> arma_elg;

    if (arma_elg < 1 || arma_elg > 2) 
    {
        cout << "Opción inválida. Se usará la primera arma por defecto." << endl;
    }
    while (mago->get_vida() > 0 && guerrero->get_vida() > 0)
    {
        cout << "\nJugador 1 (" << mago->get_nombre() << ") HP: " << mago->get_vida() << endl;
        cout << "Jugador 2 (" << guerrero->get_nombre() << ") HP: " << guerrero->get_vida() << endl;
        cout << "Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: ";

        int opcion;
        cin >> opcion;
        while (opcion < 1 || opcion > 3) {
            cout << "Opción inválida. Intente de nuevo: ";
            cin >> opcion;
        }

        Ataque ataque1 = static_cast<Ataque>(opcion);
        Ataque ataque2 = static_cast<Ataque>((rand() % 3) + 1);

        if(arma_elg== 2)
        {
            cout << mago->get_nombre() << " ataca con " << armas.second->get_nombre() << " usando " << ataque_to_string(ataque1) << ".\n";
            cout << guerrero->get_nombre() << " responde con " << armas2.first->get_nombre() << " usando " << ataque_to_string(ataque2) << ".\n";
        }
        else 
        {
            cout << mago->get_nombre() << " ataca con " << armas.first->get_nombre() << " usando " << ataque_to_string(ataque1) << ".\n";
            cout << guerrero->get_nombre() << " responde con " << armas2.first->get_nombre() << " usando " << ataque_to_string(ataque2) << ".\n";
        }

        int danio1 = calcularDanio(ataque1, ataque2);
        int danio2 = calcularDanio(ataque2, ataque1);

        guerrero->set_vida(guerrero->get_vida() - danio1);
        mago->set_vida(mago->get_vida() - danio2);

        if (danio1 > 0)
            cout << mago->get_nombre() << " hace " << danio1 << " puntos de daño.\n";
        if (danio2 > 0)
            cout << guerrero->get_nombre() << " hace " << danio2 << " puntos de daño.\n";
        if (danio1 == 0 && danio2 == 0)
            cout << "Ambos eligieron lo mismo. ¡Empate en esta ronda!\n";
    }

    if (mago->get_vida() > 0)
        cout << mago->get_nombre() << " ha ganado la pelea(jg).\n";
    else
        cout << guerrero->get_nombre() << " ha ganado la pelea(mq).\n";
    cout << "Fin de la pelea.\n";

    return 0;
}

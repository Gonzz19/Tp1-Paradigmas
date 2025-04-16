#include <iostream>
#include <cstdlib> 
#include <ctime>    

#include "fabrica_personajes/fabrica_personajes.hpp"
#include "main.hpp"



using namespace std;

int numero_magos()
{
    return rand() % 5 + 3;
}

int numero_guerreros()
{
    return rand() % 5 + 3;
}

int numero_armas()
{
    return rand() % 3;
}

int main()
{
    srand(time(0));

    int cantidad_magos = numero_magos();
    int cantidad_guerreros = numero_guerreros();

    vector<shared_ptr<Personaje>> magos;
    vector<shared_ptr<Personaje>> guerreros;

    for (int i = 0; i < cantidad_magos; i++)
    {
        int num = rand() % 4; 
        PERSONAJES tipo_mago = static_cast<PERSONAJES>(num); 
        shared_ptr<Personaje> mago = FabricaPersonajes::crear_personaje(tipo_mago);
        magos.push_back(mago);
    }

    for (int i = 0; i < cantidad_guerreros; i++)
    {
        int num = rand() % 5 + 4; 
        PERSONAJES tipo_guerrero = static_cast<PERSONAJES>(num); 
        shared_ptr<Personaje> guerrero = FabricaPersonajes::crear_personaje(tipo_guerrero);
        guerreros.push_back(guerrero);
    }

    for (const auto& mago : magos)
    {
        int num_armas = numero_armas();
        if (num_armas == 0)
        {
            unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
            unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
            mago->set_armas(move(arma1), move(arma2));
        }
        else if (num_armas == 1)
        {
            unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(rand() % 10));
            unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
            mago->set_armas(move(arma1), move(arma2));
        }
        else
        {
            unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(rand() % 10));
            unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(rand() % 10));
            mago->set_armas(move(arma1), move(arma2));
        }
    }

    for (const auto& guerrero : guerreros)
    {
        int num_armas = numero_armas();
        if (num_armas == 0)
        {
            unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
            unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
            guerrero->set_armas(move(arma1), move(arma2));
        }
        else if (num_armas == 1)
        {
            unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(rand() % 10));
            unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(TipoArma::MANOS);
            guerrero->set_armas(move(arma1), move(arma2));
        }
        else
        {
            unique_ptr<Arma> arma1 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(rand() % 10));
            unique_ptr<Arma> arma2 = FabricaPersonajes::crear_arma(static_cast<TipoArma>(rand() % 10));
            guerrero->set_armas(move(arma1), move(arma2));
        }
    }

    cout << "Magos:" << endl;
    for (const auto& mago : magos)
    {
        cout << mago->get_nombre() << endl;
        pair<unique_ptr<Arma>, unique_ptr<Arma>>& armas = mago->get_armas();
        cout << "Arma 1: " << armas.first->get_nombre() << endl;
        cout << "Arma 2: " << armas.second->get_nombre() << endl;
        cout << "" << endl;
    }
    
    cout << "Guerreros:" << endl;
    for (const auto& guerrero : guerreros)
    {
        cout << guerrero->get_nombre() << endl;
        pair<unique_ptr<Arma>, unique_ptr<Arma>>& armas = guerrero->get_armas();
        cout << "Arma 1: " << armas.first->get_nombre() << endl;
        cout << "Arma 2: " << armas.second->get_nombre() << endl;
        cout << "" << endl;
    }
    return 0;
}



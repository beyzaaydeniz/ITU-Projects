//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

class pokemon
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    string name;
    int hpValue;
    int atkValue;

public:
    pokemon();
    pokemon(const int, const string);
    pokemon(const pokemon &pokemon);

    int gethpValue();
    int getatkValue();
    string getname();

    inline void changehpValue(const int &enemyatkValue) { hpValue = hpValue - enemyatkValue; }; // Changes the health of the pokemon
};

class pokedex
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    pokemon pokedexArray[100];
    int value;

public:
    pokedex();
    void updatePokedex(pokemon &);
    void printPokedex();
};

class player
{
private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    string name;
    int pokemonNumber;
    int pokeballNumber;
    int badgeNumber;
    pokemon playerPokemon;

public:
    pokedex playerPokedex;

    player();
    player(const string, const int);

    int showPokemonNumber();
    int showPokeballNumber();
    int showBadgeNumber();
    pokemon getPokemon();
    void battleWon();
    void catchPokemon();
};

class enemy
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    string name;
    pokemon enemyPokemon;

public:
    enemy();
    enemy(const string, const pokemon);

    pokemon getPokemon();
    string getName();
};

#endif
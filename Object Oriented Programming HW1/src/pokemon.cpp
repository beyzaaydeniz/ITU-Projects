//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

pokemon::pokemon() // Default constructor of pokemon
{
    hpValue = 100;
    atkValue = 0;
    name = "";
};

pokemon::pokemon(const int Atk, const string Name) // Pokemon constructor
{
    hpValue = 100;
    atkValue = Atk;
    name = Name;
};

pokemon::pokemon(const pokemon &copy) { *this = copy; }; // Copy constructer of pokemon
int pokemon::gethpValue() { return hpValue; };           // Returns pokemon's health
int pokemon::getatkValue() { return atkValue; };         // Returns pokemon's attack
string pokemon::getname() { return name; };              // Returns pokemon's name
pokedex::pokedex() { value = 0; };                       // Default constructor of pokedex

void pokedex::updatePokedex(pokemon &newPokemon) // Add new pokemons to pokedex
{
    for (int i = 0; i < value; i++)
    {
        if (pokedexArray[i].getname() == newPokemon.getname())
            return;
    }
    value++;
    pokedexArray[value] = pokemon(newPokemon);
};

void pokedex::printPokedex() // Prints player's pokedex
{
    for (int i = 0; i < value; i++)
        cout << pokedexArray[i + 1].getname() << endl;
};

player::player() // Default constructor of player
{
    name = "";
    playerPokemon = pokemon(20, "");
    pokemonNumber = 0;
    pokeballNumber = 10;
    badgeNumber = 0;
};

player::player(const string playerName, const int selectedPokemon) // Player constructor
{
    name = playerName;
    pokemonNumber = 0;
    pokeballNumber = 10;
    badgeNumber = 0;
    if (selectedPokemon == 1)
        playerPokemon = pokemon(20, "Bulbasaur");
    else if (selectedPokemon == 2)
        playerPokemon = pokemon(20, "Charmender");
    else if (selectedPokemon == 3)
        playerPokemon = pokemon(20, "Squirtle");
};

int player::showPokemonNumber() { return pokemonNumber; };   // Returns how many pokemon player have
int player::showPokeballNumber() { return pokeballNumber; }; // Returns how many pokeball player have
int player::showBadgeNumber() { return badgeNumber; };       // Returns how many badge player have
pokemon player::getPokemon() { return playerPokemon; };      // Returns player's pokemon

void player::battleWon() // Gives player 1 badge and 3 pokeball as reward of battle
{
    badgeNumber++;
    pokeballNumber += 3;
};

void player::catchPokemon() // Throws pokeball and catch a pokemon
{
    pokemonNumber++;
    pokeballNumber--;
};

enemy::enemy() // Default constructor of enemy
{
    name = "";
    enemyPokemon = pokemon(10, "");
};

enemy::enemy(const string Name, const pokemon Pokemon) // Enemy Constructer
{
    name = Name;
    enemyPokemon = Pokemon;
};

pokemon enemy::getPokemon() { return enemyPokemon; }; // Returns enemy's pokemon
string enemy::getName() { return name; };             // Returns enemy's name
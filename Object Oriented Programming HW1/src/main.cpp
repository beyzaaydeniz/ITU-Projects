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
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;           // Use this to keep track of the enemy names
int POK_COUNTER = 0;            // Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; // You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  // You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---//
//
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string *readEnemyNames(const char *);
string *readPokemonNames(const char *);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player *, string *, string *);
void catchPokemon(player *, string *);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---//
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char *argv[])
{
    system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string *enemyNames = readEnemyNames(argv[1]);
    string *pokemonNames = readPokemonNames(argv[2]);

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n"
         << endl;
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);

    int menuChoice;

    while (true)
    {
        mainMenu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout << newPlayer.showPokemonNumber() << endl;
            break;
        case 4:
            cout << newPlayer.showPokeballNumber() << endl;
            break;
        case 5:
            cout << newPlayer.showBadgeNumber() << endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" << endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;

        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string *readEnemyNames(const char *argv)
{
    //---Code Here---//
    ifstream f(argv);
    f >> NAME_COUNTER;
    string *names = new string[NAME_COUNTER];
    for (int i = 0; i < NAME_COUNTER; i++)
        f >> names[i];
    NAME_COUNTER = 0;
    return names;
    //---------------//
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string *readPokemonNames(const char *argv)
{
    //---Code Here---//
    ifstream f(argv);
    f >> POK_COUNTER;
    string *names = new string[POK_COUNTER];
    for (int i = 0; i < POK_COUNTER; i++)
        f >> names[i];
    POK_COUNTER = 0;
    return names;
    //---------------//
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice)
{
    //---Code Here---//
    return player(playerName, pokemonChoice);
    //---------------//
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu()
{
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player *newPlayer, string *enemyNames, string *pokemonNames)
{
    //---Code Here---//
    int optionSelector;
    pokemon opponentPokemon(ENEMY_POKEMON_ATTACK, pokemonNames[POK_COUNTER]);
    pokemon playerPokemon = pokemon(newPlayer->getPokemon());
    enemy opponent(enemyNames[NAME_COUNTER], opponentPokemon);
    cout << "You encounter with " << enemyNames[NAME_COUNTER]
         << " and his/hers pokemon " << pokemonNames[POK_COUNTER] << endl;
    cout << pokemonNames[POK_COUNTER] << " Health: 100"
         << " Attack: " << ENEMY_POKEMON_ATTACK << endl;
    newPlayer->playerPokedex.updatePokedex(opponentPokemon);
    POK_COUNTER++;
    NAME_COUNTER++;
    do
    {
        cout << "1- Fight" << endl
             << "2- Runaway" << endl
             << "Choice: ";
        cin >> optionSelector;
        if (optionSelector == 2)
            return;
        playerPokemon.changehpValue(ENEMY_POKEMON_ATTACK);
        opponentPokemon.changehpValue(PLAYER_POKEMON_ATTACK);
        cout << "Your Pokemons Health: " << playerPokemon.gethpValue() << endl
             << "Misty Pokemons Health: " << opponentPokemon.gethpValue() << endl;
        if (opponentPokemon.gethpValue() <= 0 || playerPokemon.gethpValue() <= 0)
        {
            cout << "You Won!" << endl;
            newPlayer->battleWon();
            return;
        }
    } while (optionSelector == 1);
    //---------------//
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player *newPlayer, string *pokemonNames)
{
    //---Code Here---//
    int optionSelector;
    pokemon wildPokemon(ENEMY_POKEMON_ATTACK, pokemonNames[POK_COUNTER]);
    POK_COUNTER++;
    newPlayer->playerPokedex.updatePokedex(wildPokemon);
    cout << "You encounter with " << wildPokemon.getname() << " Health: 100"
         << " Attack: " << ENEMY_POKEMON_ATTACK << endl
         << "1- Catch" << endl
         << "2- Runaway" << endl
         << "Choice: ";
    cin >> optionSelector;
    if (optionSelector == 1)
    {
        newPlayer->catchPokemon();
        cout << "You catch " << wildPokemon.getname() << endl;
    }
    //---------------//
};
//--------------------------------------------//
//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------//
#include "CommandCenter.h"
#include "Robot.h"
#include <iostream>
using namespace std;
/*
****************
BEGIN: CREW CLASS FUNCTION DECLARATIONS 
****************
*/


Crew::Crew(int maxExplorers, int maxMiners, int explorerCrewSize, int minerCrewSize){

    if(maxExplorers > 5 || maxExplorers < 0){
        maxExplorers = 2;
    }
    else{
        this->maxExplorers=maxExplorers;
    }
    if(maxMiners > 5 || maxMiners < 0){
        maxMiners = 2;
    }
    else{
        this->maxMiners=maxMiners;
    }

    if(explorerCrewSize > maxExplorers || explorerCrewSize < 0){
        explorerCrewSize = 2;
    }
    else{
        this->explorerCrewSize=explorerCrewSize;
    }
    if(minerCrewSize > maxMiners || minerCrewSize < 0){
        minerCrewSize = 2;
    }
    else{
        this->minerCrewSize = minerCrewSize;
    }


    
    Explorer *explorers[maxExplorers];
    Miner *miners[maxMiners];
    for (int i = 0; i < explorerCrewSize; explorers[i++] = reinterpret_cast<Explorer *>(manufactureRobot("explorer")))
        ;
    for (int i = 0; i < minerCrewSize; miners[i++] = reinterpret_cast<Miner *>(manufactureRobot("miner")))
        ;

}

Robot *Crew::manufactureRobot(string RobotType){

    if(RobotType != "explorer" && RobotType != "miner"){
        return NULL;
    }
        
    int durability = (rand()%5)+1;
    float speedExp = (rand()%2)+1.5;
    float speedMnr = (rand()%2)+0.5;
    float speed = (rand()%2) + 2;


    if(RobotType=="explorer"){
        Explorer *expRobot = new Explorer(RobotType,speedExp,durability,0,0,0,0);
        return expRobot;
    }else if(RobotType=="miner"){
        Miner *mnrRobot = new Miner(RobotType,speedMnr,durability,0,0,0,0);
        return mnrRobot;
    }
    
}






/*
****************
END: CREW CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/















/*
****************
END: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/
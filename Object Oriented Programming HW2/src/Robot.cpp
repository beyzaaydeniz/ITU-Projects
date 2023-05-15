//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------/

#include <iostream>
using namespace std;
#include "Robot.h"



/*
****************
BEGIN: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/

Robot::Robot(string RobotType, float speed, int durability, int manufactureCost, float maintenanceCost) //  Robot constructor
{

    if (RobotType == "explorer"){
        RobotName = "exp-" + unqID++;
    }
    else if(RobotType == "miner"){
        RobotName = "mnr-" + unqID++;
    }
    
    this->unqID=unqID;
    this->RobotName=RobotName;
    this->RobotType=RobotType;
    this->speed=speed;
    this->durability=durability;
    this->maintenanceCost=maintenanceCost;
    this->manufactureCost=manufactureCost;
    this->canMove=canMove;

}

Robot* Robot::operator=(const Robot *z)
{
    this->unqID = z->unqID;
	this->RobotType = z->RobotType;
    this->speed = z->speed;
	this->durability = z->durability;
	this->manufactureCost = z->manufactureCost; 
	this->maintenanceCost = z->maintenanceCost;
    this->RobotName = z->RobotName;

}

void Robot::showInfo(const Robot *R)
{
    cout << "Name: " << R->RobotName << endl; 
    cout << "Type: " << R->RobotType << endl;
    cout << "Speed: " << R->speed << endl;
    cout << "Durability: " << R->durability << endl;
    cout << "ManufactureCost: " << R->manufactureCost << endl; 
    cout << "MaintenanceCost " << R->maintenanceCost << endl;
}

/*
****************
END: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/


/*
****************
BEGIN: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/


Explorer::Explorer() //Default explorer constructor
{
    totalExploredArea = 0;
    totalNumberOfSeleniumArea = 0;
}

Explorer::Explorer(string RobotType, float speed, int durability, int totalExploredArea, int totalNumberOfSeleniumArea, 
int exploredArea, int detectedSelenium){ //Explorer constructor

    this->totalExploredArea = totalExploredArea;
    this->totalNumberOfSeleniumArea = totalNumberOfSeleniumArea;
    this->exploredArea = exploredArea;
    this->detectedSelenium = detectedSelenium;

    setManufactureCost(3000);
    setMaintenanceCost(450/(getSpeed()));
}   

bool Explorer::move(Explorer *E){
    if(E->getCanMove() == true)
        return true;
    if (E->getCanMove() == false)
        return false;
}

void Explorer::explore(){

    if((rand() % 100) >= 40){
        detectedSelenium = true;
        totalNumberOfSeleniumArea = totalNumberOfSeleniumArea + 1;
    }
    else{
        detectedSelenium = false;
    }
    totalExploredArea = totalExploredArea + 1500;
    exploredArea = 1500;
    //getMaintenanceCost(); mi acaba
    //  This exploration should cost you as the robot’s maintenanceCost ama ne yapıcam anlamadım
}

Explorer *Explorer::operator=(Explorer *z) 
{
    Robot::operator=(*z);
    this->totalExploredArea = z->totalExploredArea;
	this->totalNumberOfSeleniumArea = z->totalNumberOfSeleniumArea;
	this->exploredArea = z->exploredArea;
	this->detectedSelenium = z->detectedSelenium;

}

void Explorer::showInfo(const Explorer *E)
{
    cout << "Name: " << E->getRobotName() << endl; 
    cout << "Type: " << E->getRobotType() << endl;
    cout << "Speed: " << E->getSpeed() << endl;
    cout << "Durability: " << E->getDurability() << endl;
    cout << "ManufactureCost: " << E->getManufactureCost() << endl; 
    cout << "MaintenanceCost " << E->getMaintenanceCost() << endl;
    cout << "Total Explored Area: " << E->totalExploredArea << endl; 
    cout << "Total Number of Selenium Area " << E->totalNumberOfSeleniumArea << endl;
    cout << "explored Area: " << E->exploredArea << endl; 

}

/*
****************
END: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/



/*
****************
BEGIN: MINER CLASS FUNCTION DECLARATIONS 
****************
*/

Miner::Miner() //default miner constructor
{
    totalGatheredSelenium = 0;
}

Miner::Miner(string RobotType, float speed, int durability, int totalExploredArea, int totalNumberOfSeleniumArea, 
int exploredArea, int detectedSelenium){ 

    setManufactureCost(5000);
    setMaintenanceCost(750/getSpeed());
    this->totalGatheredSelenium = totalGatheredSelenium;
    this->gatheredSelenium = gatheredSelenium;
    
}

void Miner::mine(bool detectedSelenium){

    if(detectedSelenium = true)
        gatheredSelenium = 5*(10 + (rand() % 90));
    // This operation should cost you as the robot’s maintenanceCost ama nasıl bilmiyorum
}

bool Miner::move(bool detectedSelenium){

     if(detectedSelenium == true && getCanMove() == true)
        return true;
    else
        return false;
}

Miner* Miner::operator=(const Miner *z)
{
    Robot::operator=(*z);

    this->totalGatheredSelenium = z->totalGatheredSelenium;
    this->gatheredSelenium = z->gatheredSelenium;
}

void Miner::showInfo(const Miner *M)
{
    cout << "Name: " << M->getRobotName() << endl; 
    cout << "Type: " << M->getRobotType() << endl;
    cout << "Speed: " << M->getSpeed() << endl;
    cout << "Durability: " << M->getDurability() << endl;
    cout << "ManufactureCost: " << M->getManufactureCost() << endl; 
    cout << "MaintenanceCost " << M->getMaintenanceCost() << endl;
    cout << "Total Gathered Selenium: " << totalGatheredSelenium << endl; 
    cout << "Gathered Selenium: " << gatheredSelenium << endl;

}




/*
****************
END: MINER CLASS FUNCTION DECLARATIONS 
****************
*/


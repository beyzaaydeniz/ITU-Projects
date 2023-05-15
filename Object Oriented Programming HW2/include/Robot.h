//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//
#include <iostream>
#ifndef _H
#define _H
using namespace std;
class Robot {
	private:
		static int unqID;
		string RobotName;
		string RobotType;
		float speed; 
		int durability; 
		int manufactureCost;
		float maintenanceCost;
		bool canMove;

	public:
		Robot();
		Robot(string, float, int, int, float); // Declarition of the constructor
		Robot* operator= (const Robot *R); 
		void showInfo(const Robot *R);

		inline void setRobotType(string);
		inline void setSpeed(float);
		void setDurability(int);
		void setManufactureCost(int);
		void setMaintenanceCost(float);
		void setRobotName(string);
	

		string getRobotType() const;
		float getSpeed() const;
		int getDurability() const;
		int getManufactureCost() const;
		float getMaintenanceCost() const;
		string getRobotName() const;

		void setCanMove(bool);
		bool getCanMove() const;

		void setRobotName(string name){
		this->RobotName = name;
		}

		void setRobotType(string type){
			this->RobotType = type;
		}

		void setSpeed(float speed){
			this->speed = speed;
		}

		void setDurability(int durability){
			this->durability = durability;
		}

		void setManufactureCost(int manufactureCost){
			this->manufactureCost = manufactureCost;
		}

		void setMaintenanceCost(float maintenanceCost){
			this->maintenanceCost = maintenanceCost;
		}
		string getRobotName() const{
			return this->RobotName;
		}
		string getRobotType() const{
			return this->RobotType;
		}

		float getSpeed() const{
			return this->speed;
		}

		int getDurability() const{
			return this->durability;
		}

		int getManufactureCost() const{
			return this->manufactureCost;
		}

		float getMaintenanceCost() const{
			return this->maintenanceCost;
		}

		void setCanMove(bool canMove){
			this->canMove = canMove;
		}

		bool getCanMove() const{
			return this->canMove;
		}
				
}; 

int Robot::unqID = 1; // to give a start value to the static variable

class Explorer : public Robot { //inherits Robot class
	friend class CommandCenter; //CommandCenter can access all members of Explorer class
	friend class Miner;			//Miner can access all members of Explorer class
	private:
		float totalExploredArea;
		int totalNumberOfSeleniumArea;
		float exploredArea;
		bool detectedSelenium;
		
	public:
		Explorer();
		Explorer(string, float, int, int, int, int, int);

		bool move(Explorer *E);
		void explore(); 
		Explorer* operator= (Explorer *z); 
		void showInfo(const Explorer *E); 

		void setTotalExploredArea(float);
		void setTotalNumberOfSeleniumArea(int);
		void setExploredArea(float);
		void setDetectedSelenium(bool);

		float getTotalExploredArea() const; 
		int getTotalNumberOfSeleniumArea() const;
		float getExploredArea() const;
		bool getDetectedSelenium() const;

		void setTotalExploredArea(float totalExploredArea){
			this->totalExploredArea = totalExploredArea;
		}

		float getTotalExploredArea() const{
			return this->totalExploredArea;
		}

		void setTotalNumberOfSeleniumArea(int totalNumberOfSeleniumArea){
			this->totalNumberOfSeleniumArea = totalNumberOfSeleniumArea;
		}

		int getTotalNumberOfSeleniumArea() const{
			return this->totalNumberOfSeleniumArea;
		}


		void setExploredArea(float exploredArea){
			this->exploredArea = exploredArea;
		}

		float getExploredArea() const{
			return this->exploredArea;
		}

		void setDetectedSelenium(bool detectedSelenium){
			this->detectedSelenium = detectedSelenium;
		}

		bool getDetectedSelenium() const{
			return this->detectedSelenium;
		}

};

class Miner : public Robot { //inherits Robot class
	friend class CommandCenter;
	private:
		int totalGatheredSelenium;
		int gatheredSelenium;

		
	public:
		Miner();
		Miner(string, float, int, int, int, int, int);
		void mine(bool);
		bool move(bool);
		Miner* operator= (const Miner *M);
		void showInfo(const Miner *M);

		void setTotalGatheredSelenium(int);
		int getTotalGatheredSelenium() const;
		void setGatheredSelenium(int);
		int getGatheredSelenium() const;

		void setTotalGatheredSelenium(int totalGatheredSelenium){
			this->totalGatheredSelenium = totalGatheredSelenium;
		}

		int getTotalGatheredSelenium() const{
			return this->totalGatheredSelenium;
		}


		void setGatheredSelenium(int gatheredSelenium){
			this->gatheredSelenium = gatheredSelenium;
		}

		int getGatheredSelenium() const{
			return this->gatheredSelenium;
		}

};


#endif
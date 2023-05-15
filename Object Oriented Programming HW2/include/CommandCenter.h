//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//
#include <iostream>
#include "Robot.h"
using namespace std;
class Crew{
	friend class CommandCenter;
	private:
		int maxExplorers;
		int maxMiners;
		int crewManufactureCost;
		float crewMaintenanceCost;
		int explorerCrewSize;
		int minerCrewSize;
		Explorer **ExplorerCrew;
		Miner **MinerCrew;
		
	public:
		Crew(int, int, int, int);

		Robot * manufactureRobot(string);
		//void manufactureRobot();


		void setmaxExplorers(int);
		void setmaxMiners(int);
		void setcrewManufactureCost(int);
		void setcrewMaintenanceCost(float);
		void setexplorerCrewSize(int);
		void setminerCrewSize(int);

		int getmaxExplorers() const;
		int getmaxMiners() const;
		int getcrewManufactureCost() const;
		float getcrewMaintenanceCost() const;
		int getexplorerCrewSize() const;
		int getminerCrewSize() const;

		void setmaxExplorers(int maxExplorers){
			this->maxExplorers = maxExplorers;
		}
		void setmaxMiners(int maxMiners){
			this->maxMiners = maxMiners;
		}
		void setcrewManufactureCost(int crewManufactureCost){
			this->crewManufactureCost = crewManufactureCost;
		}
		void setcrewMaintenanceCost(float crewMaintenanceCost){
			this->crewMaintenanceCost = crewMaintenanceCost;
		}
		void setexplorerCrewSize(int explorerCrewSize){
			this->explorerCrewSize = explorerCrewSize;
		}
		void setminerCrewSize(int minerCrewSize){
			this->minerCrewSize = minerCrewSize;
		}
		int getmaxExplorers() const{
			return this->maxExplorers;
		} 
		int getmaxMiners() const{
			return this->maxMiners;
		} 
		int getcrewManufactureCost() const{
			return this->crewManufactureCost;
		} 
		float getcrewMaintenanceCost() const{
			return this->crewMaintenanceCost;
		} 
		int getexplorerCrewSize() const{
			return this->explorerCrewSize;
		} 
		int getminerCrewSize() const{
			return this->minerCrewSize;
		} 

};

class CommandCenter{
	private:
		int neededSelenium;
		float searchArea;
		int seleniumWorth;
		int turnCount;
		float totalCrewMaintenanceCost;
		float profit;
	public:
		void setneededSelenium(int);
		void setsearchArea(float);
		void setseleniumWorth(int);
		void setturnCount(int);
		void settotalCrewMaintenanceCost(float);
		void setprofit(float);

		int getneededSelenium() const;
		float getsearchArea() const;
		int getseleniumWorth() const;
		int getturnCount() const;
		float gettotalCrewMaintenanceCost() const;
		float getprofit() const;

		void setneededSelenium(int neededSelenium){
			this->neededSelenium = neededSelenium;
		}
		void setsearchArea(float searchArea){
			this->searchArea = searchArea;
		}
		void setseleniumWorth(int seleniumWorth){
			this->seleniumWorth = seleniumWorth;
		}
		void setturnCount(int turnCount){
			this->turnCount = turnCount;
		}
		void settotalCrewMaintenanceCost(float totalCrewMaintenanceCost){
			this->totalCrewMaintenanceCost = totalCrewMaintenanceCost;
		}

		void setprofit(float profit){
			this->profit = profit;
		}
		int getneededSelenium() const{
			return this->neededSelenium;
		} 
		float getsearchArea() const{
			return this->searchArea;
		} 
		int getseleniumWorth() const{
			return this->seleniumWorth;
		} 
		int getturnCount() const{
			return this->turnCount;
		} 
		float gettotalCrewMaintenanceCost() const{
			return this->totalCrewMaintenanceCost;
		} 
		float getprofit() const{
			return this->profit;
		} 		

};




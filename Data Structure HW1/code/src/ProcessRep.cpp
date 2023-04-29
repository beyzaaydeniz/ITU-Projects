/* @Author
Student Name: Beyza Aydeniz
Student ID : 150200039
Date: 24.10.2022
*/
#include <iostream> 
#include <stdio.h>
#include <string>
#include "ProcessRep.h"


using namespace std;

ProcessRep::ProcessRep(string processType, int processID, int deliverTime, int processTime)
{   
    /*
        YOUR CODE HEAR
    */
    this->mProcessType=processType;
    this->mProcessID=processID;
    this->mDeliverTime=deliverTime;
    this->mProcessTime=processTime;
    this->mpNext=NULL;
    remainingTime = processTime;
    startTime = -1;
    endTime = -1;
}

ProcessRep::~ProcessRep()
{
    if(this->mpNext!=NULL)
        delete this->mpNext;
}

ProcessRep* ProcessRep::getNext()
{
    /*
        YOUR CODE HEAR
    */
   return this->mpNext;
}

void ProcessRep::setNext(ProcessRep *next)
{
    /*
        YOUR CODE HEAR
    */
   this->mpNext=next;
}

string ProcessRep::getProcessType()
{
    /*
        YOUR CODE HEAR
    */
   return this->mProcessType;
}

void ProcessRep::setProcessType(string processType)
{
    /*
        YOUR CODE HEAR
    */
   this->mProcessType=processType;
}

int ProcessRep::getDeliverTime()
{
    /*
        YOUR CODE HEAR
    */
   return this->mDeliverTime;
}

void ProcessRep::setDeliverTime(int deliverTime)
{
    /*
        YOUR CODE HEAR
    */
   this->mDeliverTime=deliverTime;
}

int ProcessRep::getProcessID()
{
    /*
        YOUR CODE HEAR
    */
   return this->mProcessID;
}

void ProcessRep::setProcessID(int processID)
{
    /*
        YOUR CODE HEAR
    */
   this->mProcessID=processID;
}

int ProcessRep::getProcessTime()
{
    /*
        YOUR CODE HEAR
    */
   return this->mProcessTime;
}

void ProcessRep::setProcessTime(int ProcessTime)
{
    /*
        YOUR CODE HEAR
    */
   this->mProcessTime=ProcessTime;
}
/* @Author
Student Name: Beyza Aydeniz
Student ID : 150200039
Date: 24.10.2022
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
// #include "node.h"
#include "ProcessRep.h"
#include "FIFORep.h"
#include "CPURep.h"

using namespace std;

CPURep::CPURep()
{
    /*
        YOUR CODE HEAR
    */
    mFinishedProcess = new FIFORep();
}

CPURep::~CPURep()
{
    delete this->mFinishedProcess;
}

ProcessRep* CPURep::runCPU(ProcessRep* p, int time)
{   
    /*
        YOUR CODE HEAR
    */
    p->remainingTime = p->remainingTime - 1;
    if(p->remainingTime==0){
        p->endTime=time+1;                  //I added 1 to time because this will be shown at the end of the time.
        mFinishedProcess->queue(p);         //I added the finished process to the Finished Process queue.
        
        
    }
    return p;
}

FIFORep* CPURep::getFinishedProcess()
{
    /*
        YOUR CODE HEAR
    */
   return this->mFinishedProcess;
}

void CPURep::setFinishedProcess(FIFORep* finishedProcess)
{
    /*
        YOUR CODE HEAR
    */
   this->mFinishedProcess=finishedProcess;
}
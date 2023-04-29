/* @Author
Student Name: Beyza Aydeniz
Student ID : 150200039
Date: 24.10.2022
*/
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include "SchedulerRep.h"

using namespace std;

SchedulerRep::SchedulerRep()
{
    /*
        YOUR CODE HEAR
    */
    mpProcessFIFO[0] = new FIFORep();
    mpProcessFIFO[1] = new FIFORep();
    mpProcessFIFO[2] = new FIFORep();
    this->mpRunningProcess=NULL;
    pCpuObj = new CPURep();
    this->timeSliceCount = -1;
    this->totalTime = -1;

}
SchedulerRep::~SchedulerRep()
{
    
    delete mpProcessFIFO[0];
    delete mpProcessFIFO[1];
    delete mpProcessFIFO[2];
    delete mpRunningProcess;
    delete pCpuObj;
}

FIFORep* SchedulerRep::getProcessFIFO(int index)
{
    /*
        YOUR CODE HEAR
    */
   return this->mpProcessFIFO[index];
   
}

void SchedulerRep::setProcessFIFO(FIFORep* fifo, int index)
{
    /*
        YOUR CODE HEAR
    */
   this->mpProcessFIFO[index] = fifo;
}

void SchedulerRep::setRunningProcess(ProcessRep* p)
{
    /*
        YOUR CODE HEAR
    */
   this->mpRunningProcess=p;
}

ProcessRep* SchedulerRep::getRunningProcess()
{
    /*
        YOUR CODE HEAR
    */
   return this->mpRunningProcess;
}

void SchedulerRep::pushProcess(ProcessRep* p)
{
    /*
        YOUR CODE HEAR
    */
    if(p->getProcessType()=="A"){
        getProcessFIFO(0)->queue(p);
    }
    
    if(p->getProcessType()=="B"){
        getProcessFIFO(1)->queue(p);
    }

    if(p->getProcessType()=="C"){
        getProcessFIFO(2)->queue(p);
    }
}

ProcessRep* SchedulerRep::popProcess()
{
    /*
        YOUR CODE HEAR
    */
    if(getProcessFIFO(0)->getHead()!=NULL){
        ProcessRep* p = getProcessFIFO(0)->getHead();
        getProcessFIFO(0)->dequeue();
        return p;
    }
    else if(getProcessFIFO(1)->getHead()!=NULL){
        ProcessRep* p = getProcessFIFO(1)->getHead();
        getProcessFIFO(1)->dequeue();
        return p;
    }
    else if(getProcessFIFO(2)->getHead()!=NULL){
        ProcessRep* p = getProcessFIFO(2)->getHead();
        getProcessFIFO(2)->dequeue();
        return p;
    }
}

bool SchedulerRep::checkTimeSlice()
{   
    /*
        YOUR CODE HEAR
    */
    if(getRunningProcess()->getProcessType()=="A" && timeSliceCount == 2)
        return true;
    else if(getRunningProcess()->getProcessType()=="B" && timeSliceCount == 4)
        return true;
    else if(getRunningProcess()->getProcessType()=="C" && timeSliceCount == 8)
        return true;
    else return false;
}
ProcessRep* SchedulerRep::sendProcessToCPU(ProcessRep* p){
    /*
        YOUR CODE HEAR
    */

    timeSliceCount = 0;
    if(p->startTime==-1){
        p->startTime=totalTime;
    }
    pCpuObj->runCPU(p, totalTime);
    
    return mpRunningProcess; 
}
void SchedulerRep::schedule(string type, int id, int arrivalTime, int processTime)
{   
    /*  
        The function is used to schedule the processes. If a process is reached the function it will be scheduled by the function
        according to the rules which is defined below.

            1) All process types have their own time slice (quantum). When running a process, If the scheduler reachs the time slice 
                (quantum) of the running process, the process will be preempted and put back to the queue.
            2) if a process that has higher priority comes, the running process will be preempted and put back to the queue.
            3) if a process that has less or same priority with running process comes, the running process will continue to run. 
                The new process will be put back to the queue.
            4) If running process and new process have same priority and they are put back to the queue, the new process will 
                be put back to the queue first.


    */
    /*
        YOUR CODE HEAR
    */

    ProcessRep* p = new ProcessRep(type, id, arrivalTime, processTime);
    pushProcess(p); //Since priority of new job is bigger than the process coming from CPU, I pushed new job first.


    totalTime++;
    timeSliceCount++;

    
    if(mpRunningProcess!=NULL){
        if(mpRunningProcess->getProcessType()=="B" && getProcessFIFO(0)->getHead()!=NULL){  //I checked the priorities.
            pushProcess(getRunningProcess());  //I pushed back to FIFO since running process will be replaced.
            setRunningProcess(popProcess());
            sendProcessToCPU(getRunningProcess());
        }
        else if (mpRunningProcess->getProcessType()=="C" && getProcessFIFO(0)->getHead()!=NULL){ //I checked the priorities.
            pushProcess(getRunningProcess());   //I pushed back to FIFO since running process will be replaced.
            setRunningProcess(popProcess());
            sendProcessToCPU(getRunningProcess());
        }
        
        else if(mpRunningProcess->getProcessType()=="C" && getProcessFIFO(1)->getHead()!=NULL){ //I checked the priorities.
            pushProcess(getRunningProcess());   //I pushed back to FIFO since running process will be replaced.
            setRunningProcess(popProcess());
            sendProcessToCPU(getRunningProcess());
        }

        else if(checkTimeSlice()==true){ //Quantum reached its limit so running process will be replaced.
            pushProcess(getRunningProcess()); //I pushed back to FIFO since running process will be replaced.
            setRunningProcess(popProcess());
            sendProcessToCPU(getRunningProcess());
        }
        else if(checkTimeSlice()==false){ //Since there is no priority problem or quantum did not reach its limit, running process did not change.
            getRunningProcess()->remainingTime=getRunningProcess()->remainingTime - 1; //Still I decreased the remaining time.
        }
    }

    else if (getRunningProcess()==NULL){
        setRunningProcess(popProcess());
        if(getRunningProcess()!=NULL)
            sendProcessToCPU(getRunningProcess());
    }

    if(getRunningProcess()!=NULL && getRunningProcess()->remainingTime==0){ //I checked if remaining time is 0 to push processor to the finished process queue.
        getRunningProcess()->endTime=totalTime+1; //I added 1 to total time because it will be shown at the end of the time.
        pCpuObj->getFinishedProcess()->queue(mpRunningProcess);
        setRunningProcess(popProcess());
        timeSliceCount=-1; //Since it is reseted, timeSliceCount is also reseted.
        if(getRunningProcess()!=NULL && getRunningProcess()->startTime==-1)
            getRunningProcess()->startTime=totalTime+1; //I added 1 to total time because it will be shown at the end of the time.
    }
}


void SchedulerRep::schedule(ProcessRep* p){   
    
    /*  
        The function is used to schedule the processes. If a process is reached the function it will be scheduled by the function
        according to the rules which is defined below.

            1) All process types have their own time slice (quantum). When running a process, If the scheduler reachs the time slice 
                (quantum) of the running process, the process will be preempted and put back to the queue.
            2) if a process that has higher priority comes, the running process will be preempted and put back to the queue.
            3) if a process that has less or same priority with running process comes, the running process will continue to run. 
                The new process will be put back to the queue.
            4) If running process and new process have same priority and they are put back to the queue, the new process will 
                be put back to the queue first.


    */
/*
    YOUR CODE HEAR
*/

    
    totalTime++;
    timeSliceCount++;

    if(getRunningProcess()!=NULL){ //I did not check priority since there was not new job.
        if(checkTimeSlice()==true){ //Quantum reached its limit so running process will be replaced.
            pushProcess(getRunningProcess()); //I pushed back to FIFO since running process will be replaced.
            setRunningProcess(popProcess());
            sendProcessToCPU(getRunningProcess());
        }
        else if(checkTimeSlice()==false){ //Since there is no priority problem or quantum did not reach its limit, running process did not change.
            getRunningProcess()->remainingTime=(getRunningProcess()->remainingTime - 1); //Still I decreased the remaining time.
        }
    }

    else if (getRunningProcess()==NULL){
        setRunningProcess(popProcess());
        if(getRunningProcess()!=NULL)
            sendProcessToCPU(getRunningProcess());
    }

    if(getRunningProcess()!=NULL && getRunningProcess()->remainingTime==0){ //I checked if remaining time is 0 to push processor to the finished process queue.
        getRunningProcess()->endTime=totalTime+1; //I added 1 to total time because it will be shown at the end of the time.
        pCpuObj->getFinishedProcess()->queue(getRunningProcess());
        setRunningProcess(popProcess());
        timeSliceCount=-1; //Since it is reseted, timeSliceCount is also reseted.
        if(getRunningProcess()!=NULL && getRunningProcess()->startTime==-1)
            getRunningProcess()->startTime=totalTime+1; //I added 1 to total time because it will be shown at the end of the time.
    }
    
    
}

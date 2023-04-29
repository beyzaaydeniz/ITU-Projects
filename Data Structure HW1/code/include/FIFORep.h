/* @Author
Student Name: Beyza Aydeniz
Student ID : 150200039
Date: 24.10.2022
*/
#ifndef _FIFOREP
#define _FIFOREP

#include <iostream>
#include <stdio.h>
#include "ProcessRep.h"
class FIFORep 
{
    /*
        The class construct a FIFO queue.
    */

private:
    ProcessRep* mpHead;
    ProcessRep* mpTail;
public:
    FIFORep();
    FIFORep(ProcessRep*);
    ~FIFORep();

    void setHead(ProcessRep*);
    ProcessRep* getHead();

    void setTail(ProcessRep*);
    ProcessRep* getTail();

    void queue(ProcessRep*);
    ProcessRep* dequeue();

    ProcessRep* searchID(int);
    void printFIFO();
};


#endif
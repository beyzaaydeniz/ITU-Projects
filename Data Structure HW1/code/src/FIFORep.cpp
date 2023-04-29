/* @Author
Student Name: Beyza Aydeniz
Student ID : 150200039
Date: 24.10.2022
*/
#include <iostream> 
#include <stdio.h>
#include <string.h>

#include "ProcessRep.h"
#include "FIFORep.h"

using namespace std;

FIFORep::FIFORep()
{
    /*
        YOUR CODE HEAR
    */
   this->mpHead=NULL;
   this->mpTail=NULL;

}

FIFORep::FIFORep(ProcessRep* head)
{
    /*
        YOUR CODE HEAR
    */
    this->mpHead=head;
    this->mpTail=head;
}


FIFORep::~FIFORep()
{
    if(mpHead!=NULL)
        delete mpHead;
}

void FIFORep::setHead(ProcessRep* head)
{
    /*
        YOUR CODE HEAR
    */
   this->mpHead=head;
}

ProcessRep* FIFORep::getHead()
{
    /*
        YOUR CODE HEAR
    */
   return this->mpHead;
}

void FIFORep::setTail(ProcessRep* tail)
{
    /*
        YOUR CODE HEAR
    */
   this->mpTail=tail;
}

ProcessRep* FIFORep::getTail()
{
    /*
        YOUR CODE HEAR
    */
   return this->mpTail;
}

void FIFORep::queue(ProcessRep* p)
{
    /*
        The function add a process to the tail of the queue.
    */
    /*
        YOUR CODE HEAR
    */
   
    if(mpHead==NULL){
        mpHead=p;
        mpTail=p; //Since p is the only member of FIFO, p is both head and tail of it.
        p->setNext(NULL); 
    }
    else{
        p->setNext(NULL);
        mpTail->setNext(p);
        mpTail=p;
    }
}

ProcessRep* FIFORep::dequeue()
{   
    /*
        The function remove a process from the head of the queue and returns it.
    */   
    /*
        YOUR CODE HEAR
    */
   
    if(mpHead!=NULL){
        ProcessRep* p = mpHead;
        if(mpHead==mpTail) //if FIFO has only 1 member, both tail and head become NULL.
            mpTail=NULL;
            mpHead=NULL;
        if(mpHead!=mpTail){
            mpHead = p->getNext();
            p->setNext(NULL);
        }
        else
            mpHead=NULL;
        return p;
    }
    else
        return NULL;

}

ProcessRep* FIFORep::searchID(int id)
{   
    /*
        The function search a process by id and returns it if it exist otherwise returns NULL.
    */ 
    /*
        YOUR CODE HEAR
    */
    ProcessRep* p = mpHead;
    if(p->getProcessID()!=id && p->getNext()!=NULL){
        p=p->getNext();
    }
    else if(p->getProcessID()==id){
        return p;
    }
    else if(p->getNext()==NULL){
        return NULL;
    }
}

void FIFORep::printFIFO()
{
    /*
        The function prints the proceses in the queue starting from Head to tail.
    */
    /*
        YOUR CODE HEAR
    */
   ProcessRep* p = mpHead;
   
   while(p!=NULL){
        cout << p->getProcessType() << p->getProcessID() << " " << p->startTime << " " << p->endTime << " ";
        p=p->getNext();
   }
}
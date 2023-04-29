//--- 2022-2023 Fall Semester Data Structure Assignment 2 ---//
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

#include "structs.h"

using namespace std;

//-------------Complete The Functions Below-------------//

//-------------Initialize Priority Queue-------------//
PriorityQueue::PriorityQueue(){
    //TODO
    this->head = NULL;
};

//-------------Insert New Node To Priority Queue-------------//
void PriorityQueue::enque(Node* newnode){
    //TODO
    Node* temp = head; //creates temporary object to not lose head of the priority queue

    if(head==NULL){
        head = newnode;
        newnode->next = NULL; //if head is null, new node directly becomes the head of the queue
    }

    else if(head!=NULL && newnode->token.val<head->token.val){ //if new node is smaller than head, new node becomes head
        newnode->next = head;                                           //and old head becomes the next of the new head
        head = newnode;
    }

    else{
        while(temp!=NULL){
            if(newnode->token.val>=temp->token.val && temp->next!=NULL && newnode->token.val>=temp->next->token.val){
                temp = temp->next; //if new node is equal or higher than both temp and and temp->next, we shift the queue one time
            }
            else if(newnode->token.val>=temp->token.val && temp->next!=NULL && newnode->token.val<=temp->next->token.val){
                newnode->next = temp->next; //if new node is equal or higher than temp but equal or smaller than temp->next
                temp->next = newnode;           //we put the new node between temp and temp->next
                temp = NULL;                    //temp becomes null so that the loop can stop
            }
            else if(newnode->token.val>=temp->token.val && temp->next==NULL){
                temp->next = newnode; //if new node is equal or higher than the temp and there is no next node, new node becomes the last element
                temp = NULL;                    //temp becomes null so that the loop can stop
            }
        }
    }
};

//-------------Remove Node From Priority Queue-------------//
Node* PriorityQueue::dequeue(){
    //TODO
    Node* temp = head; //created temporary object to not lose head of the priority queue

    if(head==NULL){                 //if head is null, we cannot dequeue from queue
        return NULL;
    }
    else if(head->next==NULL){      //if head has no next, we return head and head becomes null
        head = NULL;
    }
    else if(head->next!=NULL){
        head = head->next;            //we shift queue one time, head->next becomes the new head
    }
    return temp;                    //we return temp that is same as head
};

//-------------Initialize Tree-------------//
Tree::Tree(){
    //TODO
    this->root = NULL;
};

//-------------Delete Tree Nodes From Memory-------------//
Tree::~Tree(){
    //TODO
    if(this->root !=NULL){
        this->deleteTree(this->root); //we use deleteTree function to delete all the nodes
    }
    this->root = NULL;
};

//-------------Delete Tree From Memory-------------//
void Tree::deleteTree(Node* node){
    //-------------This Function Is Not Necessary-------------//
    //-----------------Use It At Your Own Will----------------//
    if(node!=NULL){
        this->deleteTree(node->left);
        this->deleteTree(node->right);
        delete node;
    }
}

//-------------Merges Two Node Into One-------------//
Node* Tree::mergeNodes(Node* temp1, Node* temp2){
   //TODO
   
   Node* mergedNode = new Node(); //creates a new object for the merged nodes, which are the parent nodes
   mergedNode->token.symbol = temp1->token.symbol + temp2->token.symbol;    //merges their symbols
   mergedNode->token.val = temp1->token.val + temp2->token.val;             //merges their values
   mergedNode->left = temp1;      //parent's left child is temp1
   mergedNode->right = temp2;     //parent's right child is temp2
   return mergedNode;           //returns parent
    
};

void Tree::printTree(Node* traverse, int level){
    cout << level << "\t";
    for (int i = 0; i < level; i++)
        cout << "\t"; 

    cout << traverse->token.symbol << "(" << traverse->token.val << ")" << endl;

    if(traverse->left)
        printTree(traverse->left, level + 1);  
    if(traverse->right)
        printTree(traverse->right, level + 1);
};
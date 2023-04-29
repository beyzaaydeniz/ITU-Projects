//--- 2022-2023 Fall Semester Data Structure Assignment 2 ---//
//--------------------------//
//---Name & Surname: Beyza Aydeniz
//---Student Number: 150200039
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>

#include "huffman.h"
#include "structs.h"

using namespace std;

//-------------Complete The Functions Below-------------//

//-----------------------------------------------------//
//-----------Reads the key from text file--------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::readKey(const char* argv){
    ifstream readKeyFile;
    readKeyFile.open(argv);

    if(readKeyFile.is_open()){
        while(!readKeyFile.eof()){
            readKeyFile >> key;
        }
    }
    readKeyFile.close();
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//---------Sorts the key in an alpabetic order---------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::sortKey(){
    sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());
};
//-----------------------------------------------------//


//-----------------------------------------------------//
//-------Finds the frequency of the characters---------//
//-----------------------------------------------------//
void Huffman::findFrequency(){
    //DO NOT CHANGE THIS
    sortKey();
    //DO NOT CHANGE THIS
    
    //TODO
    int count = 0;
    for(unsigned int i=0; i<sortedKey.size(); i++){
        count++;
        if(sortedKey[i+1]!=sortedKey[i]){           //checks if consecutive letters are the same
            Node* newNode = new Node();             //creates new node for each letter
            newNode->token.symbol = sortedKey[i];
            newNode->token.val = count;             //counts the repetition and equals to token value
            queue.enque(newNode);                   //sends the new node to the priority queue
            count = 0;                              //resets the count for the new letter
        }
    }

};
//-----------------------------------------------------//


//-----------------------------------------------------//
//----------------Creates Huffman Tree-----------------//
//-----------------------------------------------------//
void Huffman::createHuffmanTree(){
    //TODO
    findFrequency();
    while(queue.head->next!=NULL){ //merges nodes until only one element, root, remains
            Node* temp1 = queue.dequeue();
            Node* temp2 = queue.dequeue();
            huffmanTree.root = huffmanTree.mergeNodes(temp1, temp2);
            queue.enque(huffmanTree.root);  //pushes merged nodes back to the priority queue
        }
    huffmanTree.root = queue.dequeue(); //last remaining element of the priority queue is root of Huffman Tree
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//---------------Prints the Huffman Tree---------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printHuffmanTree(){
    huffmanTree.printTree(huffmanTree.root, 0);
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Finds and returns the binary------------//
//----------------value to given character-------------//
//-----------------------------------------------------//
string Huffman::getTokenBinary(char tokenChar, Node* traverse, string tokenBinary){
    //TODO
    while(traverse->token.symbol.size()>1){  //if size is 1, this means that remaining node is what we searched for
        if(traverse->left->token.symbol.find(tokenChar)!=string::npos){
            tokenBinary += "0";             //adds 0 to tokenBinary when we move left
            traverse = traverse->left;
        }
        else if(traverse->right->token.symbol.find(tokenChar)!=string::npos){
            tokenBinary += "1";             //adds 1 to tokenBinary when we move right
            traverse = traverse->right;
        }
    }
    return tokenBinary;
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//--------------Encodes the given password-------------//
//-----------------------------------------------------//
void Huffman::encodePassword(string password){
    //TODO
    string tokenBinary = ""; //to send empty string to the getTokenBinary function
    string temp = "";
    for(unsigned int i=0; i<password.size(); i++){
        temp = getTokenBinary(password[i], huffmanTree.root, tokenBinary);
        tokenBinary = "";   //resets the tokenBinary for the new password letter
        encodedBinaryPassword += temp;      //adds binary token to the encodedBinaryPassword string
        encodedValPassword += to_string(temp.size()); //encodedValPassword is equal to size of what getTokenBinary function returns
    }
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Prints the encoded password-------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printEncodedPassword(){
    cout << "Encoded Password Binary: " << encodedBinaryPassword << endl;
    cout << "Encoded Password Value: " << encodedValPassword << endl;
};

//-----------------------------------------------------//
//--------------Decodes the given password-------------//
//-----------------------------------------------------//
void Huffman::decodePassword(string encodedBinaryPassword, string encodedValPassword){
    //TODO
    int order = 0; //letter order of the word
    string EncodedToken = "";
    for(unsigned int i = 0; i<encodedValPassword.size(); i++){ //loop that will continue for the length of encodedValPassword 
        for(int y = 0; y<((int)encodedValPassword[i]-48); y++){ ///loop that will continue for the value of encodedValPassword
            EncodedToken += encodedBinaryPassword[order]; //at the end of the loop, it will be final binary that will give the token symbol
            order++;
        }
        decodeToken(EncodedToken); //decodes the given binary and adds to the end of decodedPassword
        EncodedToken = ""; //resets the EncodedToken to use decodeToken function again
        }
};

//-----------------------------------------------------//

//-----------------------------------------------------//
//---------------Decodes the given binary--------------//
//-----------------------------------------------------//
void Huffman::decodeToken(string encodedToken){
    //TODO
    Node* temp = huffmanTree.root;  //creates a temporary node to see current node
    for(unsigned int i = 0; i<encodedToken.size(); i++){    //continues until it checks all encodedToken elements
        if((int)encodedToken[i]-48==0){             //if the element is 0, moves left
            temp = temp->left;
        }
        else if((int)encodedToken[i]-48==1){        //if the element is 1, moves right
            temp = temp->right;
        }
    }
    decodedPassword += temp->token.symbol;    //every time the function runs, it adds the decoded token to the end of the decodedPassword string
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Prints the decoded password-------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printDecodedPassword(){
    cout << "Decoded Password: " << decodedPassword << endl;
};
#ifndef DATA_STRUCTURES_ASSIGNMENT_1_STACK_H
#define DATA_STRUCTURES_ASSIGNMENT_1_STACK_H
#include "Item.h"
#include "List.h"

class Stack{
    vector<Item> itemsVector;
    Item* lastIn = nullptr;
    unsigned int numOfItems = 0;

public:
    //Constructors
    Stack() = default; //Also functions as makeEmpty.

    //Methods
    void push(Item& item);
    Item pop();
    bool isEmpty() const {return numOfItems == 0;}
};

#endif //DATA_STRUCTURES_ASSIGNMENT_1_STACK_H
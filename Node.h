#ifndef DATA_STRUCTURES_ASSIGNMENT_1_NODE_H
#define DATA_STRUCTURES_ASSIGNMENT_1_NODE_H
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Node {
    int cityNumber = 0;
    Node* next = nullptr;

public:
    //Constructors
    Node() = default;
    Node(int _cityNumber, Node* _next);
    Node(Node& node);

    //Getters
    int getCityNum() {return cityNumber;}
    Node* getNext() {return next;}

    //Setters
    void setNumber(int _cityNumber) {cityNumber = _cityNumber;}
    void setNext(Node* _next) {next = _next;}
};

#endif //DATA_STRUCTURES_ASSIGNMENT_1_NODE_H
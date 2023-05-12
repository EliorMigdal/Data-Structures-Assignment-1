#ifndef DATA_STRUCTURES_ASSIGNMENT_1_LIST_H
#define DATA_STRUCTURES_ASSIGNMENT_1_LIST_H
#include "Node.h"

class List {
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    //Constructors & Destructor
    List() = default;
    List(Node* _head, Node* _tail);
    ~List();

    //Getters
    Node* getHead() const {return head;}
    Node* getTail() const {return tail;}

    //Global Methods
    friend void checkAllocation(void* pointer);

    //Methods
    bool isListEmpty();
    void insertDataToList(int cityNumber);
    void insertAfter(Node* node);
};

#endif //DATA_STRUCTURES_ASSIGNMENT_1_LIST_H
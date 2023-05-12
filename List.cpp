#include "List.h"

//Constructor & Destructor
//--------------------------------------------------
List::List(Node *_head, Node *_tail) :
head(_head), tail(_tail) {}
//--------------------------------------------------
List::~List() //Destructor
{
    Node* currNode = this->getHead();
    Node* freeNode = currNode;

    while (currNode != nullptr)
    {
        currNode = currNode->getNext();
        delete freeNode;
        freeNode = currNode;
    }
}
//--------------------------------------------------

//Global Methods
//--------------------------------------------------
void checkAllocation(void* pointer) //Verifies allocation.
{
    if (pointer == nullptr)
    {
        cout << "Memory allocation failed. Shutting program down..." << endl;
        exit(1);
    }
}
//--------------------------------------------------

//Methods
//--------------------------------------------------
bool List::isListEmpty() //Checks whether a list is empty.
{return this->head == nullptr;}
//--------------------------------------------------
void List::insertDataToList(int cityNumber) //Inserts new data to the end of the list.
{
    Node* nodeToInsert = new Node(cityNumber, nullptr);
    checkAllocation(nodeToInsert);
    List::insertAfter(nodeToInsert);
}
//--------------------------------------------------
void List::insertAfter(Node *node) //Inserts a node in an ordered way.
{
    if(isListEmpty())
        this->head = this->tail = node;

    else if(this->head->getCityNum() > node->getCityNum())
    {
        node->setNext(this->head);
        this->head = node;
    }

    else if(this->tail->getCityNum() < node->getCityNum())
    {
        this->tail->setNext(node);
        this->tail = node;
    }

    else
    {
        Node* currNode = this->head;
        bool inserted = false;
        while(currNode != nullptr && !inserted)
        {
            if (currNode->getCityNum() < node->getCityNum()
            && currNode->getNext()->getCityNum() > node->getCityNum())
            {
                node->setNext(currNode->getNext());
                currNode->setNext(node);
                inserted = true;
            }

            currNode = currNode->getNext();
        }
    }
}
//--------------------------------------------------
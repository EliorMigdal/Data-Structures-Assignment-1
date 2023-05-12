#include "Node.h"

//Constructors
//--------------------------------------------------
Node::Node(int _cityNumber, Node *_next) : cityNumber(_cityNumber), next(_next){}
//--------------------------------------------------
Node::Node(Node &node) //Copy constructor.
{
    this->cityNumber = node.getCityNum();
    this->next = node.getNext();
}
//--------------------------------------------------
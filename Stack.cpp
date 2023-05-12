#include "Stack.h"

//-------------------------------------------------
void Stack::push(Item& item)
{
    itemsVector.push_back(item);
    lastIn = &itemsVector[numOfItems];
    numOfItems++;
}
//-------------------------------------------------
Item Stack::pop()
{
    Item output (itemsVector[numOfItems - 1]);
    itemsVector.pop_back();
    numOfItems--;
    return output;
}
//-------------------------------------------------
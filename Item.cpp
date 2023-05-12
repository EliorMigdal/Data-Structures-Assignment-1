#include "Item.h"

//Constructors
//--------------------------------------------------
Item::Item(const Item& _item): //Copy constructor.
        isFirst(_item.isItFirst()), isForward(_item.isItForward()),
        isTheSameCity(_item.isSameCity()), areThereWhiteCities(_item.getWhiteCities()),
        routeEnd(_item.hasRouteEnded())
{

}
//--------------------------------------------------
Item::Item(bool _isFirst, bool _isForward, bool _isTheSameCity, bool _areThereWhiteCities, bool _routeEnd):
    isFirst(_isFirst), isForward(_isForward), isTheSameCity(_isTheSameCity),
    areThereWhiteCities(_areThereWhiteCities), routeEnd(_routeEnd)
{

}
//--------------------------------------------------
#ifndef DATA_STRUCTURES_ASSIGNMENT_1_ITEM_H
#define DATA_STRUCTURES_ASSIGNMENT_1_ITEM_H

class Item {
    bool isFirst = false;
    bool isForward = false;
    bool isTheSameCity = false;
    bool areThereWhiteCities = false;
    bool routeEnd = false;

public:
    //Constructors
    Item() = default;
    Item(const Item& _item);
    Item(bool _isFirst, bool _isForward, bool _isTheSameCity, bool _areThereWhiteCities, bool _routeEnd);

    //Setters
    void setIsFirst(bool _isFirst) {isFirst = _isFirst;}
    void setIsForward(bool _isForward) {isForward = _isForward;}
    void setSameCity(bool _isSame) {isTheSameCity = _isSame;}
    void setWhiteCities(bool _whiteCities) {areThereWhiteCities = _whiteCities;}
    void setRouteEnd(bool _newRoute) {routeEnd = _newRoute;}

    //Getters
    bool isItFirst() const {return isFirst;}
    bool isItForward() const {return isForward;}
    bool isSameCity() const {return isTheSameCity;}
    bool getWhiteCities() const {return areThereWhiteCities;}
    bool hasRouteEnded() const {return routeEnd;}
};

#endif //DATA_STRUCTURES_ASSIGNMENT_1_ITEM_H
#include "Globals.h"

//Input & Output functions
//-------------------------------------------------
void getInputSize(int& numOfCities, int& numOfRoads) //Reads input size from user.
{
    cin >> numOfCities;
    cin >> numOfRoads;

    if (numOfCities <= 1 || numOfRoads <= 1 || (numOfCities > 1 && numOfRoads > 1
    && numOfRoads > binomialCoefficient(numOfCities, PAIR)))
    {
        cout << "Invalid input" << endl;
        exit(-1);
    }
}
//--------------------------------------------------
void getRoadsInput(List* arrOfLists, const int& numOfCities, const int& numOfRoads) //Reads roads input from user.
{
    char input = getchar(); //flush.
    input = ' ';
    int startPoint, endPoint;
    unsigned int roadsInserted = 0;

    while (input != '\n')
    {
        if (roadsInserted == numOfRoads)
        {
            cout << "Invalid input" << endl;
            exit(-1);
        }

        cin >> startPoint;
        cin >> endPoint;
        input = getchar();

        while (!checkFirstInput(arrOfLists, numOfCities, startPoint, endPoint))
        {
            cout << "Invalid input" << endl;
            exit(-1);
        }

        arrOfLists[startPoint - 1].List::insertDataToList(endPoint);
        arrOfLists[endPoint -1].List::insertDataToList(startPoint);
        roadsInserted++;
    }
}
//--------------------------------------------------
void getCurrentAndTargetInput(int numOfCities, int& currentCity, int& targetCity)
//Reads parameters for townDistance functions.
{
    cin >> currentCity;
    cin >> targetCity;

    checkSecondInput(numOfCities, currentCity, targetCity);
}
//--------------------------------------------------
bool checkFirstInput(List* arrOfLists, unsigned int numOfCities, int& startingPoint, int& endPoint)
//Verifies roads input.
{
    bool output = false;

    while (startingPoint <= 0 || startingPoint > numOfCities
    || endPoint <= 0 || endPoint > numOfCities || startingPoint == endPoint)
    {
        cout << "Invalid input" << endl;
        exit(-1);
    }

    if (arrOfLists != nullptr)
        output = doesARoadExists(arrOfLists, startingPoint, endPoint);

    return output;
}
//--------------------------------------------------
void checkSecondInput(unsigned int numOfCities, int& startingPoint, int& endPoint) //Verifies townDistance parameters.
{
    while (startingPoint <= 0 || startingPoint > numOfCities
           || endPoint <= 0 || endPoint > numOfCities)
    {
        cout << "Invalid input" << endl;
        exit(-1);
    }
}
//--------------------------------------------------
int binomialCoefficient(int n, int k) //Calculates nCk.
{
    if (k == 0 || k == n)
        return 1;

    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1 , k);
}
//--------------------------------------------------

//Assistance Functions
//-------------------------------------------------
bool doesARoadExists(List* arrOfLists, int startingPoint, int endingPoint) //Checks for duplicate roads.
{
    bool found = false;
    Node* currNode = arrOfLists[startingPoint-1].getHead();

    while (currNode != nullptr && !found)
    {
        if (currNode->getCityNum() == endingPoint)
            found = true;

        currNode = currNode->getNext();
    }

    return !found;
}
//--------------------------------------------------
void setColorsArrAsWhites(unsigned short int* colorsArr, int numOfCities)
//Sets colors array for each townDistance function.
{
    for (unsigned int i = 0; i < numOfCities; i++)
        colorsArr[i] = WHITE;
}
//--------------------------------------------------
int getFirstWhiteCityNum(List* arrOfLists, int currentCity, unsigned short int colorsArr[])
//Finds first white city neighbor for a given city.
{
    int output = 0;
    Node* currNode = arrOfLists[currentCity - 1].getHead();

    while (currNode != nullptr && !output)
    {
        if (colorsArr[currNode->getCityNum() - 1] == WHITE)
            output = currNode->getCityNum();

        else
            currNode = currNode->getNext();
    }

    return output;
}
//--------------------------------------------------
bool checkForWhiteCities(List* arrOfLists, int currentCity, unsigned short int colorsArr[])
//Returns whether a city is connected to white cities.
{
    bool output = false;
    Node* currNode = arrOfLists[currentCity - 1].getHead();

    while (currNode != nullptr)
    {
        if (colorsArr[currNode->getCityNum() - 1] == WHITE)
            output = true;

        currNode = currNode->getNext();
    }

    return output;
}
//--------------------------------------------------

//townDistance Functions
//-------------------------------------------------
int townDistance(List* arrOfLists, int currentCity, int targetCity, unsigned short int colorsArr[])
//Recursive townDistance.
{
    colorsArr[currentCity - 1] = BLACK;
    int d;

    if (currentCity == targetCity)
        return 0;

    else
    {
        if (!checkForWhiteCities(arrOfLists, currentCity, colorsArr))
            return NO_ROUTE;

        else
        {
            while (checkForWhiteCities(arrOfLists, currentCity, colorsArr))
            {
                int firstWhiteCity = getFirstWhiteCityNum(arrOfLists, currentCity, colorsArr);
                d = townDistance(arrOfLists, firstWhiteCity, targetCity, colorsArr);

                if (d != NO_ROUTE)
                    return 1 + d;
            }
        }
    }

    return d;
}
//--------------------------------------------------
int iterTownDistance(List* arrOfLists, int currentCity, int targetCity, unsigned short int colorsArr[])
//Iterative version of townDistance.
{
    if (currentCity == targetCity)
        return 0;

    else if (!checkForWhiteCities(arrOfLists, currentCity, colorsArr))
        return NO_ROUTE;

    else
        colorsArr[currentCity - 1] = BLACK;

    int distance = 0, originalCity = currentCity;
    bool goingForward = true, reachedLastIteration = false, foundRoute = false;
    Stack iterationsInfo;
    vector<int> citiesOrder;

    Item firstIteration(true,
                        goingForward,
                        currentCity == targetCity,
                   checkForWhiteCities(arrOfLists, currentCity, colorsArr),
                   !checkForWhiteCities(arrOfLists, currentCity, colorsArr));
    iterationsInfo.push(firstIteration);
    citiesOrder.push_back(currentCity);
    int* last = &citiesOrder[citiesOrder.size() - 1];

    while (!reachedLastIteration && !foundRoute)
    {
        if (goingForward)
        {
            currentCity = getFirstWhiteCityNum(arrOfLists, currentCity, colorsArr);
            goingForward = currentCity != 0;
            citiesOrder.push_back(currentCity);
            last = &citiesOrder[citiesOrder.size() - 1];
            colorsArr[currentCity - 1] = BLACK;
        }

        Item otherIterations(currentCity == originalCity,
                             goingForward,
                             currentCity == targetCity,
                             checkForWhiteCities(arrOfLists, currentCity, colorsArr),
                             !checkForWhiteCities(arrOfLists, currentCity, colorsArr) || currentCity == targetCity);
        iterationsInfo.push(otherIterations);

        if (otherIterations.isSameCity())
            foundRoute = true;

        else if (otherIterations.hasRouteEnded() && currentCity == originalCity)
            reachedLastIteration = true;

        else if (otherIterations.hasRouteEnded() && currentCity != originalCity)
        {
            goingForward = false;
            last = &citiesOrder[citiesOrder.size() - 1];
            currentCity = *last;
            citiesOrder.pop_back();

            if (checkForWhiteCities(arrOfLists, currentCity, colorsArr))
            {
                citiesOrder.push_back(currentCity);
                goingForward = true;
            }
        }

        else if (!otherIterations.hasRouteEnded())
            goingForward = true;
    }

    while (!iterationsInfo.isEmpty())
    {
        Item info = iterationsInfo.pop();

        if (foundRoute && info.isItForward() && !info.isItFirst())
            distance++;

        else if (foundRoute && !info.isItForward())
            distance--;

        else if (!foundRoute)
            distance = -1;
    }

    return distance;
}
//Data Structures programming assignment#1, submitted by Elior Migdal, ID# 313455321.
#include "Globals.h"

int main()
{
    List* cities;
    int numOfCities, numOfRoads, currentCity, destination;
    getInputSize(numOfCities, numOfRoads);
    cities = new List[numOfCities];
    checkAllocation(cities);
    getRoadsInput(cities, numOfCities, numOfRoads);
    getCurrentAndTargetInput(numOfCities,currentCity, destination);

    unsigned short int colorsArr[numOfCities];
    setColorsArrAsWhites(colorsArr, numOfCities);

    int distance = townDistance(cities, currentCity, destination, colorsArr);
    cout << "Preferred distance (recursive algorithm): " << distance << endl;
    setColorsArrAsWhites(colorsArr, numOfCities);

    distance = iterTownDistance(cities, currentCity, destination, colorsArr);
    cout << "Preferred distance (iterative stack algorithm): " << distance << endl;

    delete[] cities;
    return 1;
}
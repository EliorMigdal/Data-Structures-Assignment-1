#ifndef DATA_STRUCTURES_ASSIGNMENT_1_GLOBALS_H
#define DATA_STRUCTURES_ASSIGNMENT_1_GLOBALS_H
#include "List.h"
#include "Stack.h"

const unsigned short int BLACK = 0;
const unsigned short int WHITE = 1;
const unsigned short int PAIR = 2;
const short int NO_ROUTE = -1;

void getInputSize(int& numOfCities, int& numOfRoads);
void getRoadsInput(List* arrOfLists, const int& numOfCities, const int& numOfRoads);
void getCurrentAndTargetInput(int numOfCities, int& currentCity, int& targetCity);
bool checkFirstInput(List* arrOfLists, unsigned int numOfCities, int& startingPoint, int& endPoint);
void checkSecondInput(unsigned int numOfCities, int& startingPoint, int& endPoint);
int binomialCoefficient(int n, int k);

bool doesARoadExists(List* arrOfLists, int startingPoint, int endingPoint);
void setColorsArrAsWhites(unsigned short int* colorsArr, int numOfCities);
int getFirstWhiteCityNum(List* arrOfLists, int currentCity, unsigned short int colorsArr[]);
bool checkForWhiteCities(List* arrOfLists, int currentCity, unsigned short int colorsArr[]);

int townDistance(List* arrOfLists ,int currentCity, int targetCity, unsigned short int colorsArr[]);
int iterTownDistance(List* arrOfLists, int currentCity, int targetCity, unsigned short int colorsArr[]);

#endif //DATA_STRUCTURES_ASSIGNMENT_1_GLOBALS_H
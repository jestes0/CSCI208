#include "marble.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

//Default function defines marble
Marble::Marble()
{
color = "Cyan";
}

//Function sets the color
void Marble::setcolor(string C)
{

color = C;

}


//Function gets the color
string Marble::getcolor()
{
return color;
}

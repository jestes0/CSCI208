/****************************************************************
/****************************************************************
/*   FILE NAME: marble.h
/*
/*    AUTHOR: Andy Estes
/*
/*   DESCRIPTION: defines a default marbler
/*
/****************************************************************/

#ifndef marble_h
#define marble_h

#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class Marble
{
private:

string color;

public:

  Marble(); //default
  void setcolor(string C); //sets the color
  string getcolor(); //gets the color

};

#endif

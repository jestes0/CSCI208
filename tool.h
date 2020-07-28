#ifndef tool_h
#define tool_h

#include <iostream>
#include<string>

using namespace std;

class Tool
{

protected:
  string type;
  int strength;

public:

  Tool()
  {
    strength=0;
  }

  string getType()
  {
    return type;
  }

  virtual int fight(Tool* arg1)=0;

};

class Rock: public Tool
{

public:
  Rock()
  {

   type="Rock";
   //strength=34;
  }
  int fight(Tool* arg1)
  {
    if (arg1->getType() == "Rock")
    {
      return 0;
    }

    else if (arg1->getType() == "Paper")
    {
      return 1;
    }

    else if (arg1->getType() == "Scissors")
    {
      return 2;
    }
  }
};

class Paper: public Tool
{

public:
  Paper()
  {

   type="Paper";
   //strength=17;
  }

  int fight(Tool* arg1)
  {
    if (arg1->getType() == "Paper")
    {
      return 0;
    }

    else if (arg1->getType() == "Scissors")
    {
      return 1;
    }

    else if (arg1->getType() == "Rock")
    {
      return 2;
    }
  }

};


class Scissors: public Tool
{
public:
  Scissors()
  {

   type="Scissors";
   //strength=29;
  }

  int fight(Tool* arg1)
  {
    if (arg1->getType() == "Scissors")
    {
      return 0;
    }

    else if (arg1->getType() == "Rock")
    {

      return 1;
    }

    else if (arg1->getType() == "Paper")
    {
      return 2;
    }
  }

};
#endif

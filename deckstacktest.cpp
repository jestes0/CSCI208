#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string.h>

//Needed to call the Deck and Card Classes
#include "deck.h"
#include "card.h"
// *  *  *  *  *  *  *  *  *

using namespace std;

int main()
{
  //Variable Declaration
  Deck test;
  Card a;
  Card b;


//Making sure the stack is functional
  cout<<"Case 1: Testing The Stack/Node."<<endl;

//Outputs the card
  a=test.deal();
  cout<<a.toString()<<endl;
// *  *  *  *  *  *  *  *  *

  cout<<a.toString()<<" is the first card in the deck."<<endl;
  cout<<endl<<endl;

//Making sure shuffle is functional
  cout<<"Test 2: Shuffle function Test."<<endl;

//Sets a random variable that randomly runs x number of times
  int random = (rand() % 1000) + 8;

//Loop runs through and uses the stacks and shuffles
  for (int l=0; l <random; l++)
  {
    test.shuffle(); //step 1
  }

//Outputs the shuffled card
  cout<<a.toString();
  cout<<"Shuffle will shuffle deck."<<endl;
  cout<<"The loop adds a pure random feel by doing it a random # of times."<<endl;

  cout<<endl<<endl;

cout<<"End of Test."<<endl;
  return 0;

//End of Program
}

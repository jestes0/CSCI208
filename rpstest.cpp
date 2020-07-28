#include "tool.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;


int main()
{
srand(time(0));

int dec, spec=0;
string choice;
string cpuchoice;
int result, pscore=0, cscore=0;

//debug  Tool* toold = &t;
Tool* player;
Tool* cpu;

spec = (rand() % 3)+1;

switch (spec)
{
  case 1:
  cpu = new Rock();
  break;

  case 2:
  cpu = new Paper();
  break;

  case 3:
  cpu = new Scissors();
  break;
}

for (int i=0; i<3; i++)
{

cout<<"select 1 for Rock, 2 for Paper, and 3 for Scissors."<<endl;
cin>>dec;

if (dec == 1)
{

player = new Rock();

  cout<<"You Chose: "<<player->getType()<<endl;
}

if (dec == 2)
{

player = new Paper();

  cout<<"You Chose: "<<player->getType()<<endl;
}

if (dec == 3)
{

player = new Scissors();

  cout<<"You Chose: "<<player->getType()<<endl;
}

cout<<"CPU Chose: "<<cpu->getType()<<endl;


result=player->fight(cpu);

  if (result==0)
  {
    cout<<"This match was a draw!."<<endl;
  }
  if (result==1)
  {
    cout<<"The CPU wins this round!"<<endl;
    cscore++;
  }
  if (result==2)
  {
    cout<<"This Player has won this round!"<<endl;
    pscore++;
  }

}
return 0;
}

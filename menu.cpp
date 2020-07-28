/****************************************************************
/****************************************************************
/*   FILE NAME: menu.cpp
/*
/*    AUTHOR: Andy Estes
/*
/*   DESCRIPTION: Game menu to play several different games
/*
/****************************************************************/

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string.h>

#include "Linklist.h"
#include "monte.h"
#include "deck.h"
#include "tool.h"
#include "card.h"

using namespace std;

void war();             //Runs the Game of War
void MonteM();
void MonteC();
void Blackjack();       //Runs Blackjack
void Rps();             //Plays RPS
void Special();

int main()
{
srand(time(0));

int choice;

do
{

//Output to show all of the Game Options
cout<<"* * * * * * Game Menu * * * * * *"<<endl;
cout<<"Select 1 for War"<<endl;
cout<<"Select 2 For Monte (Marbles)"<<endl;
cout<<"Select 3 For Monte (Cards)"<<endl;
cout<<"Select 4 For Blackjack"<<endl;
cout<<"Select 5 For Rock-Paper-Scissors"<<endl;
cout<<"Select 6 For a Special Card Game."<<endl;
cout<<"Or select 99 to exit."<<endl;

cin>>choice;

switch (choice)
{
        case 1:
        war();
        break;

        case 2:
        MonteM();
        break;

        case 3:
        MonteC();
        break;

        case 4:
        Blackjack();
        break;

        case 5:
        Rps();
        break;

	case 6:
	Special();
	break;

        case 99:
        cout<<"Thanks for Playing!"<<endl;
        break;

        default:
        cout<<"Not a valid choice"<<endl;
        cin.clear();
        cin.ignore(100, '\n');
        break;

}
} while (choice != 99);

        return 0;
}


/****************************************************************
/*  FUNCTION NAME: war()
/*  Description:   Plays the game of war
/*
/****************************************************************/

void war()
{
int draw, i=0,j , p1score=0, cpuscore=0;

Deck gamedeck;
Card p1card;
Card cpucard;
int random = (rand() % 1000) + 8;

for (int l=0; l <random; l++)
{

gamedeck.shuffle(); //step 1

}

cout<<"Welcome to the game of War!"<<endl;
cout<< "* * * * * * * * * * * * * * * * * * * * * * * "<<endl;


cout<<"Press Enter to Draw"<<endl;
//cin.get();
//shuffles and pushes a card for the player and cpu

for (int k=0; k < 26; k++)
{

  cout<<"Press 1 to Draw"<<endl;
  cin>>draw;

while (draw !=1)
{

  cout<<"Not a valid choice"<<endl;
  cin.clear();
  cin.ignore(100, '\n');
  cin>>draw;

}

p1card = gamedeck.deal();

cpucard = gamedeck.deal(); //step 2

//All three if functions test to see which card is higher
//If a card is the same number the suit will determine the winner/If a tie occurs a card was outputted twice (error)
 if (p1card > cpucard)
 {

  cout<<"Players Card: "<<p1card.toString()<<endl; //outputs player card
  cout<<"Computer's Card: "<<cpucard.toString()<<endl; //outputs cpu card

  cout<<"Player 1 wins this round!"<<endl;
  p1score++; //increments score
  cout<<"Player One's Score: "<<p1score<<endl;
  cout<<"Computer's Score: "<<cpuscore<<endl;

 }

else if (cpucard > p1card)
 {

  cout<<"Players Card: "<<p1card.toString()<<endl;
  cout<<"Computer's Card: "<<cpucard.toString()<<endl;


  cout<<"The CPU wins this round!"<<endl;
  cpuscore++;
  cout<<"Player One's Score: "<<p1score<<endl;
  cout<<"Computer's Score: "<<cpuscore<<endl;

 }

i++;
cout<<endl;
}while (i<10);

//last if function determines the winner

 cout<<"Press 1 to view the results"<<endl;
  cin>>draw;

while (draw !=1)
{

  cout<<"Not a valid choice. Please Re-Enter."<<endl;
  cin.clear();
  cin.ignore(100, '\n');
  cin>>draw;

}

  cout<<"Player One's Score: "<<p1score<<endl;
  cout<<"Computer's Score: "<<cpuscore<<endl;



if (p1score > cpuscore)
{

 cout<<"Player 1 wins!"<<endl;

}
else if (p1score < cpuscore)
{

 cout<<"Player 1 loses!"<<endl;

}

cout<<"You will now return to the menu."<<endl;


}


/****************************************************************
/*  FUNCTION NAME: MonteM()
/*  Description:   Plays monte with marbles
/*
/****************************************************************/
void MonteM()
{
  int condition;

  //string test = "Cyan" ;

  Monte<int> marbles ;
  marbles.Shuffle() ;
  condition = marbles.Pick() ;

  if(condition == 1)
  {
    cout << "You have chosen the Cyan marble"<<endl;
    cout<<"You win!!!"<<endl;
  }
  else
  {
    cout << "You have chosen a Blue marble.\n" ;
    cout<< "Too bad!"<<endl;
  }

  cout<<"Thanks for playing! You will now be returned to the menu."<<endl;

}

/****************************************************************
/*  FUNCTION NAME: MonteC()
/*  Description:   Plays monte with cards
/*
/****************************************************************/

void MonteC()
{

  int condition;

  Monte<int> cards ;
  cards.Shuffle() ;
  condition = cards.Pick() ;

  if(condition == 1)
  {
    cout << "You have chosen the Ace of Spades"<<endl;
    cout<<"You win!!!"<<endl;
  }
  else
  {
    cout << "You have chosen 2 of Clubs"<<endl;
    cout<< "Too bad!"<<endl;
  }

  cout<<"Thanks for playing! You will now be returned to the menu."<<endl;
}

/****************************************************************
/*  FUNCTION NAME: Blackjack()
/*  Description:   Plays the game of Blackjack
/*
/****************************************************************/
void Blackjack()
{

//All Variable initialized

//Class variables
  Deck gamedeck;
  Card pcard1, pcard2, cpucard, cpucard2;
  Card rank1, rank2;

//*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *

//Other Variables
  int pscore1, pscore2, playerscore;
  int cpuscore, cpuscore2, cputotal;
  int random=0, draw;
  char ans='n', win;
//  *  *  *  *  *  *  *  *  *


//Variable to set and shuffle the deck.
  random = (rand() % 5000) + 500;
  for (int l=0; l <random; l++)
  {
    gamedeck.shuffle(); //step 1
  }

  cout<<"Welcome to Blackjack!"<<endl;


//Input to draw a card. If 1 is not pressed input validation kicks in
  cout<<"Press 1 to Draw"<<endl;
  cin>>draw;

  while (draw !=1)
  {
    cout<<"Not a valid choice"<<endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin>>draw;
  }


//Deals Cards for the player and CPU
  pcard1 = gamedeck.deal();
  pcard2 = gamedeck.deal();
  cpucard = gamedeck.deal();
  cpucard2 = gamedeck.deal();
//  *  *  *  *  *  *  *  *  *  *  *  *

  cout<<"Players First Card: "<<pcard1.toString()<<endl; //outputs player card
  cout<<"Players Second Card: "<<pcard2.toString()<<endl; //outputs player card

//Gets a integer value for Rank
  pscore1 = pcard1.getrank();
  pscore2 = pcard2.getrank();

//Sets rank to 10 if Card is a Jack or Higher
  if (pscore1 >10)
  {
    pscore1 = 10;
  }
  if (pscore2 >10)
  {
    pscore2 = 10;
  }

//Adds up Player Total Score
  playerscore=pscore1+pscore2;
  cout<<"Player Score: "<<playerscore<<endl;


//CPU's Output and Rank added into a score.
  cout<<"Computer First Card: "<<cpucard.toString()<<endl;
  cout<<"Computer's Second Card: "<<cpucard2.toString()<<endl;

  cpuscore = cpucard.getrank();
  cpuscore2 = cpucard2.getrank();

  if (cpuscore >10)
  {
    cpuscore=10;
  }
  if (cpuscore2 >10)
  {
    cpuscore2=10;
  }

  cputotal=cpuscore+cpuscore2;
  cout<<"Computer Score: "<<cputotal<<endl;



//This Loop runs under a set condition
  while (cputotal < playerscore && cputotal <21 && playerscore <21)
  {
    cout<<"The House Draws another Card!"<<endl;
    cpucard = gamedeck.deal();
    cout<<"Computer's Card: "<<cpucard.toString()<<endl; //outputs player card
    cpuscore = cpucard.getrank();
    if (cpuscore >10)
    {
      cpuscore=10;
    }
    cputotal = cputotal+cpuscore;
    cout<<"Computers Score: "<<cputotal<<endl;
    }

//Runs When the conditions below are met
  while (cputotal <21 && playerscore<21)
  {

//Asks whether or not the player wants a card.
    cout<<"Would you like to draw another card?"<<endl;
    cout<<"y or Y for yes"<<endl;
    cout<<"N or n for no"<<endl;
    cin>>ans;

//Exits the loop if one hits n or
    if ((ans == 'n') || (ans == 'N'))
    {
      break;
    }

    else if (ans == 'y' || ans== 'Y')
    {
      pcard1 = gamedeck.deal();
      cout<<"Player's Card: "<<pcard1.toString()<<endl;
      pscore1 = pcard1.getrank();

      if (pscore1 >10)
        {
          pscore1 = 10;
        }

        playerscore=playerscore+pscore1;
        cout<<"Players Score: "<<playerscore<<endl;

        if (playerscore ==21)
        {
          break;
        }

        while (cputotal < playerscore && cputotal <21 && playerscore <21)
        {
          cout<<"The House Draws another Card!"<<endl;
          cpucard = gamedeck.deal();
          cout<<"Computer's Card: "<<cpucard.toString()<<endl;
          cpuscore = cpucard.getrank();

          if (cpuscore >10)
          {
            cpuscore=10;
          }
          cputotal = cputotal+cpuscore;
          cout<<"Computers Score: "<<cputotal<<endl;
        }

        if(cputotal > 21)
        {
          break;
        }

        else if (playerscore > 21)
        {
          break;
        }

        else if (playerscore == 21)
        {
          break;
        }

      }

      else
      {
        cout<<"Not a valid choice."<<endl;
        cout<<"y or Y for yes"<<endl;
        cout<<"N or n for no"<<endl;
        cin>>ans;
      }
    }

  cout<<"Players Final Score: "<<playerscore<<endl;
  cout<<"Computers Final Score: "<<cputotal<<endl;

  if (playerscore ==21)
  {
    cout<<"Blackjack! The Player Wins!!!"<<endl;
  }

  else if(playerscore < 21 && cputotal > 21 && playerscore !=21)
  {
  cout<<"The Player Wins!!!"<<endl;
  }

  else if(playerscore <21 && cputotal <21 && playerscore > cputotal)
  {
    cout<<"The Player Wins!!!"<<endl;
  }

  else if(playerscore == cputotal)
  {
    cout<<"It's a tie!"<<endl;
  }

  else if(cputotal > playerscore)
  {
    cout<<"The House Wins!"<<endl;
  }

  else if(playerscore > 21)
  {
    cout<<"The House Wins!"<<endl;
  }

}

/****************************************************************
/*  FUNCTION NAME: Rps()
/*  Description:   Plays Rock-Paper-Scissors
/*
/****************************************************************/
void Rps()
{
//Plays Rock Paper Scissors
  cout<<endl;
  cout<<"* * * * * * * * * * * * * * * * * *"<<endl;
  cout<<"Welcome To Rock Paper Scissors!!!"<<endl;

  //Random function Set for CPU decision
  srand(time(0));

  //Variables set
  int choice;
  int spec=0;
  int result, pscore=0, cscore=0;

  //Pointers for virtual classes
  Tool* player;
  Tool* cpu;

//For Loop Plays the game three times
  for (int i=0; i<3; i++)
  {

  spec=0;
  spec = (rand() % 3)+1;

  //Switch determines what type the cpu is going to be.
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

  /*
  This choice determines what the player is going to player
  Each functions calls either rock, paper, or scissors
  */
  cout<<"select 1 for Rock, 2 for Paper, and 3 for Scissors."<<endl;
  cin>>choice;
  cout<<endl;

  //Choice For Rock
  if (choice == 1)
  {
  player = new Rock();
  cout<<"You Chose: "<<player->getType()<<endl;
  }

  //Choice For Paper
  if (choice == 2)
  {
  player = new Paper();
  cout<<"You Chose: "<<player->getType()<<endl;
  }

  // Choice for Scissors
  if (choice == 3)
  {
  player = new Scissors();
  cout<<"You Chose: "<<player->getType()<<endl;
  }

  //Outputs the CPU's Choice
  cout<<"CPU Chose: "<<cpu->getType()<<endl;

  //Runs the Virtual Function to determine the result
  result=player->fight(cpu);


  //Displays the results of the above function
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
      cout<<"The Player has won this round!"<<endl;
      pscore++;
    }
  }

cout<<endl;
cout<<"Results: "<<endl;

//If statement to determine the winner
if (pscore > cscore)
{
  cout<<"The Player has won!!!"<<endl;
  cout<<"Player Score: "<<pscore<<endl;
  cout<<"CPU's Score: "<<cscore<<endl;
}

else if (pscore < cscore)
{
  cout<<"The CPU has won!!!"<<endl;
  cout<<"Player Score: "<<pscore<<endl;
  cout<<"CPU's Score: "<<cscore<<endl;
}

else if (pscore == cscore)
{
  cout<<"The match is a Tie!!!"<<endl;
  cout<<"Player Score: "<<pscore<<endl;
  cout<<"CPU's Score: "<<cscore<<endl;
}

cout<<endl;
cout<<"Thank you for playing. You will be returned to the Menu"<<endl;
cout<<endl;
//Returns to Main Menu
}


/****************************************************************
/*  FUNCTION NAME: Special()
/*  Description:   Plays a Special Card Game
/*
/****************************************************************/

void Special()
{

//Standard Variables
int random, pscore, cscore, ptotal, ctotal;
int choice;
Deck gamedeck;
Card player, cpu;

//These control three linked lists:
Linkedlist<Card> phand;
Linkedlist<Card> chand;
Linkedlist<Card> discard;


//Draw interface
random = (rand() % 7000) + 1200;
for (int l=0; l <random; l++)
  {
   gamedeck.shuffle();
  }


cout<<"Welcome to a special game!"<<endl;

for (int i=0; i<5; i++)
{
 player = gamedeck.deal();
 pscore = player.getrank();

//Sets rank to 10 if Card is a Jack or Higher
 if (pscore >10)
 {
   pscore = 10;
 }
 ptotal=pscore+pscore;

 cout<<"Player's Score: "<<ptotal<<endl;
 phand.push_front(player);
}

for (int i=0; i<5; i++)
{
 cpu= gamedeck.deal();
 chand.push_front(cpu);
}

//chand.printList(); Debug to test computer's list.


//Options for the user while playing the game
while (choice != 99)
{
  cout<<"Select Your Options: "<<endl;
  cout<<"1 to view hand"<<endl;
  cout<<"2 to show your score."<<endl;
  cout<<"Or 99 to return to menu."<<endl;
  cin>>choice;

switch (choice)
{
        case 1:
        cout<<"Players Hand: "<<endl;
        //Prints the hand
        phand.printList();
        break;

        case 2:
        //Outputs the score
        cout<<"Score: "<<ptotal<<endl;
        break;

        case 99:
        //exits the game and goes to the menu
        cout<<"Thanks for playing!"<<endl;
        break;
}

}

}

/****************************************************************
/****************************************************************
/*   FILE NAME: deck.cpp
/*
/*    AUTHOR: Andy Estes
/*
/*   DESCRIPTION: Sets the functions for creating a deck of cards.
/*                Includes Deck and Shuffle. Stack handles the rest.
/****************************************************************
/****************************************************************/

#include "deck.h"
#include "stack.h"
#include "card.h"

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int i;


/****************************************************************
/*  FUNCTION NAME: Deck::Deck()
/*  Description: Default constructor. Builds the deck of 52 cards.
/*
/*  PARAMETERS: takes in a card argument and pushes it into the deck.
/*
/*  RETURN VALUES: None
/*
/****************************************************************/

Deck::Deck()
{

  Card cardtemp;
  Suit cardsuit;
  int rank = 1;

  //Build the deck structure of 52.
cardsuit = Clubs;
    for(i=1; i<=13; i++){
      cardtemp = Card(i, Clubs);
      push(Card(i, Clubs)); //builds the card in here

    }
cardsuit = Diamonds;
    for(i=1; i<=13; i++){
      cardtemp = Card(i, Diamonds);
      push(Card(i,Diamonds)); //builds the card in here
    }

cardsuit = Hearts;
    for(i=1; i<=13; i++){
      cardtemp = Card(i, Hearts);
      push(Card(i, Hearts)); //builds the card in here
    }

    cardsuit = Spades;
        for(i=1; i<=13; i++){
          cardtemp = Card(i, Spades);
          push(Card(i, Spades)); //builds the card in here
        }

}

/****************************************************************
/*  FUNCTION NAME: void Deck::shuffle()
/*  Description: Shuffles the deck by splitting the deck using stacks
/*
/*  PARAMETERS: uses stack to make two piles and pushes them back in
/*
/*  RETURN VALUES: None
/*
/****************************************************************/

//void shuffle(); //shuffles the Deck
void Deck::shuffle()
{

    srand(time(0));
    int count = 0;
    int num = (rand() % 8) + 1; //random number for pilea
    num = 22 + num;

    Stack<Card> spota;  //stack 1 to split deck
    Stack<Card> spotb;  //stack 2 to split deck
    Card stackedcard;

    do
    {
      spota.push(pop());
      count++;
    } while (count < num); //ensures all cards in spot a is pushed in

    while (this->isEmpty() ==false)
    {

     spotb.push(this->pop()); //All spots in spotb are filled

   }

while (!spota.isEmpty() || !spotb.isEmpty() )
{

if (!spota.isEmpty())
  {

     stackedcard=spota.pop();
     this->push(stackedcard); //pushes back into the default deck stack

  }

if (!spotb.isEmpty())
  {

    stackedcard=spotb.pop();
    this->push(stackedcard);  //pushes back into default stack

  }
}
}

/****************************************************************
/*  FUNCTION NAME: Card Deck::deal()
/*  Description: Returns the top card of the deck
/*
/*  PARAMETERS: uses pop to get the card on top of the stack.
/*
/*  RETURN VALUES: dealt
/*
/****************************************************************/

//Card deal(); //will return a card
Card Deck::deal()
{

Card dealt;

  dealt = pop(); //sets variable = pop function.
  return dealt;  //returns the card item

}

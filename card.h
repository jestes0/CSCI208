/****************************************************************
/****************************************************************
/*   FILE NAME: card.h
/*
/*    AUTHOR: Andy Estes
/*
/*   DESCRIPTION: Builds the card class for a deck of cards
/*
/****************************************************************/

#ifndef card_h
#define card_h

#include <iostream>
#include <string.h>

enum Suit //Defines all 4 suits including the joker
{

Clubs,
Diamonds,
Hearts,
Spades,
Joker

};

class Card
{

private:

  int rank;
  Suit cardsuit;

public:


Card(int cardrank, Suit suit);
Card();
int getrank();
int getsuit();
std::string toString();
bool friend operator> (Card a, Card b);
};

#endif


/****************************************************************
/****************************************************************
/*   FILE NAME: card.cpp
/*
/*    AUTHOR: Andy Estes
/*
/*   DESCRIPTION: Outputs Several Test Cases for outputting cards
/*
/****************************************************************
/****************************************************************/
#include "card.h"
#include <iostream>
#include <string.h>

using namespace std;

string array[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
string array2[5] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const double Error = 999.99;

Card::Card(int cardrank, Suit suit)
    {

      if (cardrank < 0 || cardrank > 14)
      {

        throw Error;

      }
      rank = cardrank; //pulls variable from private
      cardsuit = suit;

    };

/****************************************************************
/*   STRUCTURE NAME: Card()
/*
/*   DATA ELEMENTS WITH DESCRIPTION
/*  default constructor for rank and suit
/****************************************************************/

Card::Card()
  {

    rank = 0; //default rank
    cardsuit = Joker; //default suit

  }

  int Card::getrank()
  {

    return (rank);

  }

  int Card::getsuit()
  {

    return (cardsuit);

  }

  std::string Card::toString()
   {

    string cardname;

    if (rank == 0)
    {
      cardname = array2[cardsuit]; //output for joker
    }
    else
    {
      cardname = array[rank-1] + " of " + array2[cardsuit]; //output for others
    }

    return cardname;

  }

  bool operator> (Card a, Card b)
 {

  if (a.getrank() > b.getrank())
  {

    return (true);

  }

  else if (b.getrank() > a.getrank())
  {

    return (false);

  }

  else if (a.getsuit() > b.getsuit())
  {

    return (true);

  }

}


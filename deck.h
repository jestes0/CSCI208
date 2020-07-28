 #ifndef deck_h
 #define deck_h

 #include <time.h>
 #include <math.h>
 #include <cstdlib>

 #include "card.h"
 #include "stack.h" //included to run stack and node respectively

const int DeckisEmpty = 1042;
//Variable to check input validation.

 class Deck : public Stack<Card> //deck is a child of stack
 {

public:
    Deck();         //Default constructor
    Card deal();    //Returns a Card
    void shuffle(); //shuffles the Deck

};

#endif

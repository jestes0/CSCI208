/****************************************************************
/****************************************************************
/* FILE NAME: stack.h
/*
/* AUTHOR: Andy Estes
/*
/* DESCRIPTION: Builds a dynamic stack for a deck of cards.
/*
/****************************************************************
/****************************************************************/

#ifndef stack_h
#define stack_h

#include "node.h"

const int Stackempty=99;

template <typename T>

class Stack
{

protected:
  Node<T>* TOSptr;

public:

  Stack();            //constructor
  ~Stack();           //destructor
  bool isEmpty();     //check for empty deck
  void push(T arg_T); //pushes the next argument
  T pop();            //returns an item of type T
  T peek();           //looks at next card but does not pop it

};

/****************************************************************
/*  FUNCTION NAME: Stack<T>::Stack()
/*  Description: DEfault constructor to reset Ptr position
/*
/*  PARAMETERS: TOSptr=NULL
/*
/*  RETURN VALUES: None.
/*
/****************************************************************/

template <typename T>
Stack<T>::Stack()
{

TOSptr = NULL;

}

/****************************************************************
/*  FUNCTION NAME: Stack<T>::isEmpty()
/*  Description: Checks if the stack is empty
/*
/*  PARAMETERS: TOSptr
/*
/*  RETURN VALUES: true if empty, false if not.
/*
/****************************************************************/

template <typename T>
bool Stack<T>::isEmpty()
{
  if (TOSptr == NULL)
  {

    return (true);

  }

  else
  {

    return (false);

  }

}

/****************************************************************
/*  FUNCTION NAME: Stack<T>::isEmpty()
/*  Description: Checks if the stack is empty
/*
/*  PARAMETERS: TOSptr
/*
/*  RETURN VALUES: true if empty, false if not.
/*
/****************************************************************/

template <typename T>
void Stack<T>::push(T arg_T)
{
//create a new Node
//should point to old TOS

  Node<T>* newNode = new Node<T>(arg_T, TOSptr);

    TOSptr= newNode;

}

/****************************************************************
/*  FUNCTION NAME:  T Stack<T>::pop()
/*  Description: pops the next item in the stack
/*
/*  PARAMETERS: needs items to be in the stack. must not be empty
/*
/*  RETURN VALUES: returnItem
/*
/****************************************************************/

template <typename T>
 T Stack<T>::pop()
{

if (isEmpty()) //Checks if the stack is empty
{

    throw Stackempty;

}

else
{

//Remove top node_h
Node<T>* popNodePTR = TOSptr;
TOSptr = TOSptr->getnextPtr();

T returnItem = popNodePTR->getItem();
//returnItem is being set to next item using the pointer

//delete old node_h
delete popNodePTR;
//resets pointer
popNodePTR=NULL;

return returnItem;

}

}

/****************************************************************
/*  FUNCTION NAME:  T Stack<T>::peek()
/*  Description: Peeks at the next item in the stack
/*
/*  PARAMETERS: needs items to be in the stack. must not be empty
/*
/*  RETURN VALUES: returnItem
/*
/****************************************************************/

template <typename T>
T Stack<T>::peek()
{

  if (isEmpty()) //checks for empty stack
  {

      throw isEmpty;

  }

  T returnItem = TOSptr->getItem(); //finds item from stack
  return returnItem; //returns the item
}

/****************************************************************
/*  FUNCTION NAME:  Stack<T>::~Stack()
/*  Description: De constructs the deck after it is no longer necessary
/*
/*  PARAMETERS: needs items to be in the stack and must not be empty
/*
/*  RETURN VALUES: none. deck is cleared at end.
/*
/****************************************************************/

template <typename T>
Stack<T>::~Stack()
{
  while (! isEmpty())
  {

    pop(); //pops all cards until deck is empty. no values will remain.

  }
}


#endif

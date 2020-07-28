#ifndef housekeeping_h
#define housekeeping_h

#include "node.h"
#include "card.h"
#include<iostream>

using namespace std ;

template <typename T>
class Linkedlist
{

private:
Node<T>* headnodePtr ;
T value ;

public:
        Linkedlist() ;
        bool isEmpty() ;
        void printList() ;
        void push_front(T value) ;
        void push_back(T value) ;
        void insert(int position , T value) ;
        void insert(T value) ;
        int size() ;
        T pop_front() ;
        T pop_back() ;
        void clear() ;
        T remove (T value) ;
        T removeAtPos(int position) ;



static const int ItemNotFound=8001 ;
static const int IndexOutofBounds = 8002 ;
static const int ListisEmpty = 8003 ;

} ;

template<typename T>
Linkedlist<T>::Linkedlist()
  {

    headnodePtr = NULL ;

  }

template<typename T>
bool Linkedlist<T>::isEmpty()
  {
    if (headnodePtr == NULL)
      {
        return true ;
      }
    else
  return false ;
  }

template<typename T>
void Linkedlist<T>::printList ()
  {
    if (headnodePtr == NULL)
    {
      throw ListisEmpty ;
    }

    Node<T>* something = headnodePtr ;
    int count=1;

  while (something != NULL)
    {
      T item;
      item=something->getItem();
      cout <<"Card "<<count<<" is: "<<item.toString()<<endl;
      count++;
      //line is used to call the string of a Card object
      something = something->getnextPtr() ;
      cout << endl ;
// this cout is for when we want to see the entire list
    }
  //something->getnextPtr();
//  cout<<something->getItem();
//  cout<<value<<endl;
  }

template<typename T>
void Linkedlist<T>::push_front(T value)
  {

    Node<T>* tempnode = new Node<T>(value , headnodePtr) ;

    headnodePtr = tempnode ;
 //   value++ ;
  }

template<typename T>
void Linkedlist<T>::push_back(T value)
  {

    Node<T>* temp = new Node<T>(value) ;
//Node<T>* front = new Node<T>(value, 0);

    if(isEmpty())
      {
	       headnodePtr = temp ;
	       return ;
      }

    if (headnodePtr->getnextPtr() == NULL)
      {
	       headnodePtr->setnextPtr(temp) ;
         return ;
      }


    Node<T>* current = headnodePtr ;

    while (current->getnextPtr() != NULL)
      {
	       current = current->getnextPtr() ;
      }

      current->setnextPtr(temp) ;
  }

template<typename T>
void Linkedlist<T>::insert(int position , T arg_item)
  {

    if (headnodePtr == NULL)
      {
        push_front(arg_item) ;
        return ;
      }

    if (position == this->size() )
      {
	       this->push_back(arg_item) ;
      }

    Node<T>* temp = new Node<T>(arg_item) ;

    if (position == 0 )
      {
        temp->setnextPtr(headnodePtr) ;
        headnodePtr = temp ;
        return ;
      }

    Node<T>* current = headnodePtr ;
    Node<T>* prev = current ;

    int counter = 0 ;

    while (counter != position )
      {
	       prev = current ;
	       current = current->getnextPtr() ;
	       counter++ ;
      }

    prev->setnextPtr(temp) ;
    temp->setnextPtr(current) ;

  }

template<typename T>
void Linkedlist<T>::insert(T arg_item)
  {

    if (isEmpty() )
      {
        return push_front(arg_item) ;
        //return ;
      }
    Node<T>* item = new Node<T>(arg_item) ;
    Node<T>* current = headnodePtr ;
    Node<T>* prev = current ;

    if(arg_item > current->getItem() )
      {
        while (arg_item > current->getItem() )
          {
            prev = current ;
            current = current->getnextPtr() ;
          }
        prev->setnextPtr(item) ;
        item->setnextPtr(current) ;
      }
    else if( arg_item < current->getItem() )
      {
        push_front(arg_item) ;
      }
  }

template<typename T>
int Linkedlist<T>::size()
  {
    int count = 0 ;

    if (headnodePtr == NULL)
      {
        return count ;
      }

    Node<T>* check = headnodePtr ;


    while (check->getnextPtr() != NULL)
      {
        check = check->getnextPtr() ;
        count++ ;
      }

    return (count + 1) ;
  }

template<typename T>
T Linkedlist<T>::pop_front()
  {

	   if (this->isEmpty() )
	    {
        cout << "empty" << endl ;
	      throw ListisEmpty ;
	    }

    Node<T>* current = headnodePtr ;
    headnodePtr = headnodePtr->getnextPtr() ;
    T returnItem = current->getItem() ;

    delete current ;
    current = NULL ;

    return (returnItem) ;
  }

template<typename T>
T Linkedlist<T>::pop_back()
  {

	  if (isEmpty() )
	    {
	       throw ListisEmpty ;
	    }

 //size =1;
    if (size() == 1 )
      {
        return this->pop_front() ;
      }

    Node<T>* current = headnodePtr ;
    Node<T>* prev = NULL ;

    while(current->getnextPtr() != NULL)
      {
	       prev = current ;
	       current = current->getnextPtr() ;
      }

    value = current->getItem() ;

    delete current ;
    current = NULL ;
    prev->setnextPtr(NULL) ;
    return (value) ;
  }

template<typename T>
void Linkedlist<T>::clear()
  {
    while(size() > 0 )
      {
        this->pop_front() ;
      }
  }

template<typename T>
T Linkedlist<T>::remove(T arg_item)
  {
    if (isEmpty() )
      {
         throw ListisEmpty ;
      }

      if (arg_item == headnodePtr->getItem())
      {
        return pop_front();
      }

      Node<T>* current = headnodePtr ;
      Node<T>* prev = current ;

     if(size() == 1 && current->getItem() == arg_item)
      {
        pop_back() ;
        return (arg_item) ;
      }


    while(current->getItem() != arg_item )
      {
        prev = current ;
        current = current->getnextPtr() ;

        if(current == NULL )
          {
            cout << "You have chosen a value not in the list.\n" ;
            throw ItemNotFound ;
          }
      }



    Node<T>* next = current ;
    next = next->getnextPtr() ;
    T number = current->getItem() ;

    cout << number << endl ;


    delete current ;

    current = NULL ;

    prev->setnextPtr(next) ;

    return (number) ;

  }

template<typename T>
T Linkedlist<T>::removeAtPos(int position)
    {
      T item ;
      int counter = 0 ;
      if (isEmpty() )
        {
           throw ListisEmpty ;
        }

      if( position > size() )
        {
            throw IndexOutofBounds ;
        }

      Node<T>* current = headnodePtr ;
      Node<T>* prev = current ;

      if(position == size() )
        {
          while(current->getnextPtr() != NULL)
            {
              current = current->getnextPtr() ;
              item = current->getItem() ;
            }
          pop_back() ;
          return (item) ;
        }
      else if(position == 1 )
        {
          item = headnodePtr->getItem() ;
          pop_front() ;
          return (item) ;
        }
      else
      {

        while (counter != (position - 1) )
          {
            cout << "We are in the count loop.\n" ;
    	      prev = current ;
    	      current = current->getnextPtr() ;
    	      counter++ ;
          }

        Node<T>* next = current ;
        next = next->getnextPtr() ;
        item = current->getItem() ;

        cout << item << endl ;

        delete current ;
        current = NULL ;
        prev->setnextPtr(next);

        return(item) ;
      }

    }

#endif

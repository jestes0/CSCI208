#include<iostream>    	// IO operations
//#include <cstdlib> 		//
//#include <cstddef>
#include "Linklist.h"  // Linked lists files

using namespace std;

int readInt(string); // function that reads in input from standard input

int main()
{

     int choice;
     int item;
     int pos;
     int size;
     int num ;
     Linkedlist<int> a;

 	cout << "***************************************************************************" << endl;
 	cout<<"1:  isEmpty() (Indicate whether the list is empty)\n";
 	cout<<"2:  size() (Count the number of items in the list)\n";
 	cout<<"3:  printList()  (Print the content of the current list)\n";
 	cout<<"4:  clear() (Clears or empties the list\n";
 	cout<<"5:  push_front(int)(Insert an element at the beginning of the list)\n";
 	cout<<"6:  push_back(int) (Append an element to the end of the list)\n";
 	cout<<"7:  insert(int position, int value) (Insert an element at given position)\n";
 	cout<<"8:  insert(int value) (Insert an element in order ) \n";
 	cout<<"9:  pop_front()(Remove an element at the beginning of the list)\n";
 	cout<<"10: pop_back() (Remove an element to the end of the list)\n";
 	cout<<"11: removeAtPos(int) (Return and delete a node at a given position)\n";
 	cout<<"12: remove(int value) (Remove an element from the list ) \n";

 	cout<<"99: Quit   (Quit the program)\n";
 	cout << "***************************************************************************" << endl << endl;
 	cout<<"\n   Please enter your choice here:  ";
 	 cin>>choice;

   while(choice != 99)
    {


       switch(choice)
       {
 	 case 1:  //isEMPTY : Indicate whether the list is empty
 		    // Add your code here
 		cout << "isEmpty Test" << endl;
    cout << a.isEmpty() << endl ;
 		cout << endl ;
 	    break;

 	 case 2:  // SIZE: Count the number of items in the list
 	    // Add your code here
 				cout << "Size Test" << endl;
        size=a.size();
        cout <<size<<endl;

 		cout << endl<< endl;
 	    break;

 	case 3: // PRINTLIST: Print the content of the current list
          if (a.isEmpty())
          {
            cout<<"Nothing inside the list"<<endl;
            break;
          }

          a.printList();
 	    break;

 	case 4:  //CLEAR: Clears or empties the list
          a.clear() ;
          cout << endl << endl;
 	    break;

 // INSERTION METHODS
 	 case 5:  // PUSH_FRONT: Insert an element at the beginning of the list
 	    item=readInt("to insert at the front of the list:  ");
 	    // Add your code here
      a.push_front(item);
//      a.printList(); debug line
 		cout << endl << endl;
 	    break;

 	 case 6: 	 // PUSH_BACK: Append an element to the end of the list
 	    item=readInt("to append to the end:  ");
      a.push_back(item);
      cout << endl << endl;
 	    break;

 	 case 7: 	 // INSERT: Insert an element at given position
 	    pos=readInt("of position in list where to add item:   ");
 	    item=readInt("to add to list:  ");
 	    a.insert(pos, item);
 		cout << endl << endl;
 	    break;

 	case 8: 	 // INSERT: Insert an element in order
 	    item=readInt("to add to list:  ");
      a.insert(item);
      cout << endl<< endl;
 	    break;

 // DELETION METHODS

 	 case 9: // POP_FRONT : Remove first element in list
 	    num = a.pop_front() ;
      cout << "The item you removed from the front of the list is: " << num ;
 		  cout << endl<< endl;
 	    break;

 	 case 10: // POP_BACK: Remove last element in list
 	 	  num = a.pop_back() ;
      cout << "The item you removed from the back of the list is: " << num ;
 		  cout << endl<< endl;
 	    break;

 	  case 11: // REMOVEATPOS: Return and delete a node at a given position
              cout << "What position do you want to remove.\n" ;
              cin >> pos ;
 	            cout << a.removeAtPos(pos) ;
    		      cout << endl<< endl;

              break;

 	  case 12: // REMOVEP: Return a specific element
      cout << "What value do you want to remove from the list.\n" ;
      cin >> item ;
 	    cout << a.remove(item) << endl ;
    	cout << endl << endl;
 	    break;
 	 default:
 		 cin.clear();
 		 cin.ignore();
 	    cout<<"\n Invalid choice. Please try again.\n";
 	    break;
       }
 	cout<<"\n   Please enter your next choice here:  ";
 	cin>>choice;
    }
    cout<<"\n Bye\n";
    return 0;
 }



int readInt(string descr)
{
   int item;
   cout << "\n   Please enter an integer value " << descr;
   cin >> item;

	while (cin.fail()) // no extraction took place
   {
      cout << "\n Please try again:";
	  cin.clear(); // reset the state bits back to goodbit so we can use ignore()
	  cin.ignore(1000, '\n'); // clear out the bad input from the stream
      cin >> item;
   }

   while (item < 0)
   {
      cout << "\n Please try again:";
      cin >> item;
   }
   return item;
}

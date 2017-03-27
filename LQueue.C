/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
#include <cstdlib>

using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}

//--- Definition of back()
QueueElement Queue::back() const
{
   if (!empty())
      return (myBack->data);
   else
   {
	return 0;
   }
}

//--- Definition of middle()
QueueElement Queue::middle() const
{
   	Queue::NodePointer ptr = myFront;
   	int midLength = length()/2;

   if (!empty()){
   for (int i = 1; i< midLength;i++){
   ptr = ptr->next;
   }
      return (ptr->data);
      }
   else
   {
	return 0;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}

//--- Move to Front
void Queue::move_to_front(const QueueElement & value)
{
// check if given value is already at the front
 if(front() == value){
        return;
    }

//check empty
if (!empty())
	{
	Queue::NodePointer ptr;
    Queue::NodePointer prevPtr = NULL;

    bool found = false;

    //iterate through queue
    for (ptr = myFront; ptr != 0; ptr = ptr->next){
    //found value
        if(ptr->data == value){
            found = true;
            if(ptr == myBack){
                prevPtr->next = 0;
                myBack = prevPtr;
            }
            else{
                prevPtr->next = ptr->next;
            }
            //set ptr as the first element
            ptr->next = myFront;
            myFront = ptr;
            break;
        } else {
        //record previous pointer
        prevPtr = ptr;
}
    }

//cannot find value
    if (found == false)
    {cout << "***Value is not found in Queue***" << endl;}
    // if element is not in queue
	} else
		cout << "***Queue is empty -- can't move a value to front***" << endl;

}


//--- Merge
void Queue::merge_two_queues(Queue & q1, Queue & q2){
Queue::NodePointer ptr;

           while(!q1.empty()){
               q2.enqueue(q1.myFront->data);
               q1.dequeue();
           }

           while(!q2.empty()){
               QueueElement minValue = q2.myFront->data;
               for (ptr = q2.myFront; ptr != 0; ptr = ptr->next){
                   if(ptr->data<minValue){
                       minValue=ptr->data;
                   }
               }
               q2.move_to_front(minValue);
               q1.enqueue(q2.myFront->data);
               q2.dequeue();
           }

   return;
}

//Size
int Queue::length() const
{
    int length = 0;
    Queue::NodePointer ptr;
    for (ptr = myFront; ptr != 0; ptr = ptr->next){
        length++;
    }

    return length;
}
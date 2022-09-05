#include<iostream>
#include "QueueADT.h"
#define defaultSize 5
using namespace std;

template <typename E> class Link {

public:

E element; // Value for this node
Link *next; // Pointer to next node in queue

Link(const E& elemval, Link* nextval = NULL)
{ element = elemval;
  next = nextval;
}
Link(Link* nextval = NULL) {
    next = nextval;
}
};

template <typename E> class LQueue: public Queue<E> {

private:

Link<E>* front; // Pointer to front queue node
Link<E>* rear;  // Pointer to rear queue node
Link<E>* curr;
int size;      // Number of elements in queue

void removeall() { // Return link nodes to free store
   while(front != NULL) {
   curr = front;
   front = front->next;
   delete curr;
   }
}

public:

LQueue(int sz = defaultSize) // Constructor
{ front = rear = new Link<E>();
  size = 0; }

~LQueue() { clear();
delete front; } // Destructor

void clear() { // Clear queue
removeall();
front = rear = new Link<E>(); size = 0;
}

void enqueue(const E& it) { // Put element on rear
rear->next = new Link<E>(it, NULL);
rear = rear->next;
size++;
}

E dequeue() { // Remove element from front

E it = front->next->element;
Link<E>* ltemp = front->next;
front->next = ltemp->next; // Advance front
if (rear == ltemp) rear = front; // Dequeue last element
delete ltemp; // Delete link
size --;
return it;
}

int length() const { return size; }

const E& frontValue() const { // Get front element
//Assert(size != 0, "Queue is empty");
return front->next->element;
}

const E& rearValue() const { // Get rear element
 return rear->element;
}

E leaveQueue() {

E it = rear->element;
Link<E>* temp = front;
while (temp->next!=rear)
        temp=temp->next;
    if(temp->next == rear)
        rear = temp;
    delete temp->next;
    size --;

 return it;
}

};

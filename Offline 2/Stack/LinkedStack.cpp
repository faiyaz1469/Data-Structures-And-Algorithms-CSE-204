#include<iostream>
#include "StackADT.h"
using namespace std;

template <typename E> class Link {

public:

E element; // Value for this node
Link *next; // Pointer to next node in list
// Constructors
Link(const E& elemval, Link* nextval = NULL)
{ element = elemval;
  next = nextval;
}
Link(Link* nextval = NULL) {
    next = nextval;
  }
};

template <typename E> class LStack: public Stack<E> {
private:

Link<E>* top; // Pointer to first element
int size; // Number of elements


public:
int direction = 1;

LStack(int sz) // Constructor
{ top = NULL; size = 0; }

~LStack(){ clear(); } // Destructor

void clear() { // Reinitialize
    while (top != NULL) { // Delete link nodes
        Link<E>* temp = top;
        top = top->next;
        delete temp;
    }
    size = 0;
}

void push(const E& it) { // Put "it" on stack
    top = new Link<E>(it, top);
    size++;
}

E pop() { // Remove "it" from stack
    E it = top->element;
    Link<E>* ltemp = top->next;
    delete top;
    top = ltemp;
    size--;
    return it;
}

const E& topValue() const { // Return top value
    return top->element;
}

int length() const { return size; } // Return length

void setDirection(int dir){
      //direction = dir;
}
};

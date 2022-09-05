#include<iostream>
#include "QueueADT.h"
#define defaultSize 5
using namespace std;

template <typename E> class AQueue: public Queue<E> {
private:

int maxSize; // Maximum size of queue
int top;     // Index for front element
int listSize; // Number of list items now
E *listArray; // Array holding queue elements

public:

AQueue(int size = defaultSize ) // Constructor
{
    maxSize = size;
    top = 0;
    listSize=0;
    listArray = new E[size];
}

AQueue(E *var) // Constructor
{
    listArray = new E[defaultSize];
    top = *var;
    listSize = 0;
}

~AQueue() { delete [] listArray; } // Destructor

void clear() { top = 0;
    listSize = 0; } // Reinitialize

void resize() {

    size_t newSize = maxSize * 2;
    E* newlistArray = new E[newSize];

    memcpy( newlistArray, listArray, maxSize * sizeof(E) );

    maxSize = newSize;
    delete [] listArray;
    listArray = newlistArray;
}

void enqueue(const E& it) {
        if(listSize < maxSize){
            listArray[top++] = it;
            listSize++;
        }
        else if(listSize == maxSize){
            resize();
            listArray[top++] = it;
            listSize++;
        }

}

E dequeue() {
        E it = listArray[0]; // Copy the element
        for(int i=0; i<listSize-1; i++) // Shift them down
        listArray[i] = listArray[i+1];
        listSize--;
        --top;
        return it;
}

const E& frontValue() const { // Return front element
        return listArray[0];
}

const E& rearValue() const { // Return rear element
        return listArray[top-1];
}

int length() const { return top; } // Return length

int maxLength() const { return maxSize; }

E leaveQueue() {
     return listArray[--top];
}


};


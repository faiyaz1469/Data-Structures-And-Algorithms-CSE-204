#include<iostream>
#include "StackADT.h"
#define defaultSize 2
using namespace std;

template <typename E> class AStack: public Stack<E> {
private:

int maxSize; // Maximum size of stack
int top; // Index for top element
int listSize; // Number of list items now
E *listArray; // Array holding stack elements
//int direction = 1;

public:
int direction = 1;

AStack(int size = defaultSize ) // Constructor
{
    maxSize = size;
    top = 0;
    listSize=0;
    listArray = new E[size];
}

AStack(E (*ArrayGiven)[5], int dir) // Constructor
{
    top = 0;
    listSize = 0;
    direction = dir;
}

~AStack() { delete [] listArray; } // Destructor

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

void push(const E& it) { // Put "it" on stack
    if(direction == -1){
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
    else if(direction == 1){
         if(listSize < maxSize){
            for(int i=listSize; i>0; i--) // Shift elements up
               listArray[i] = listArray[i-1];
            listArray[0] = it;
            top++;
            listSize++;
        }
        else if(listSize == maxSize){
            resize();
             for(int i=listSize; i>0; i--) // Shift elements up
               listArray[i] = listArray[i-1];
            listArray[0] = it;
            top++;
            listSize++;
        }
    }

}

E pop() { // Pop top element
    if(direction == -1)
       return listArray[--top];
    if(direction == 1){
        E it = listArray[0]; // Copy the element
        for(int i=0; i<listSize-1; i++) // Shift them down
        listArray[i] = listArray[i+1];
        listSize--;
        --top;
        return it;
    }
}

const E& topValue() const { // Return top element
    if(direction == -1)
        return listArray[top-1];
    else if (direction == 1)
        return listArray[0];
}

int length() const { return top; } // Return length

int maxLength() const { return maxSize; }

void setDirection(int dir){
      direction = dir;
}
};

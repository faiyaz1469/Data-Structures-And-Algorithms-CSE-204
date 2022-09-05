#include <bits/stdc++.h>
#include<iostream>
#include "List.h"
using namespace std;

template <typename E>
class AList : public List <E> {
private:
int maxSize; // Maximum size of list
int listSize; // Number of list items now
int curr; // Position of current element
E* listArray; // Array holding list elements
int size;

public:

AList() { // Constructor
maxSize = listSize = curr = 0;
listArray = new E[maxSize];

}

AList(E arrayGiven[],int elemCnt, int max) { // Constructor

    maxSize = max;
    size = max;
    listArray = new E[maxSize];
    listSize = elemCnt;
    curr = 0;

    int i = 0;
    while(i<elemCnt)
    {
        listArray[i] = arrayGiven[i];
        i++;
    }

}

AList(int defaultSize) { // Constructor
maxSize = defaultSize;
listSize = curr = 0;
listArray = new E[maxSize];
}

AList(int defaultSize, int max) { // Constructor
size = max;
maxSize = max;
listSize = curr = 0;
listArray = new E[maxSize];
}

~AList(){ delete [] listArray; } // Destructor

void clear() {
delete [] listArray; // Remove the array
listSize = curr = 0; // Reset the size
listArray = new E[maxSize]; // Recreate array
}

void insert(const E& it) {
    //int c = maxSize;
  if(listSize < maxSize){
    for(int i=listSize; i>curr; i--) // Shift elements up
    listArray[i] = listArray[i-1];
    listArray[curr] = it;
    listSize++;
  }
  else if(listSize == maxSize){

    size_t newSize = maxSize + size;
    E* newlistArray = new E[newSize];

    memcpy( newlistArray, listArray, maxSize * sizeof(E) );

    maxSize = newSize;
    delete [] listArray;
    listArray = newlistArray;

    for(int i=listSize; i>curr; i--) // Shift elements up
   listArray[i] = listArray[i-1];
   listArray[curr] = it;
   listSize++;
  }
}

/*void resize() {
    size_t newSize = maxSize * 2;
    E* newlistArray = new E[newSize];

    memcpy( newlistArray, listArray, maxSize * sizeof(E) );

    maxSize = newSize;
    delete [] listArray;
    listArray = newlistArray;
}*/

void append(const E& it) {
    //int d = maxSize;
    if(listSize < maxSize){
        listArray[listSize++] = it;
    }
    else if(listSize == maxSize){
        size_t newSize = maxSize + size;
        E* newlistArray = new E[newSize];

        memcpy( newlistArray, listArray, maxSize * sizeof(E) );

        maxSize = newSize;
        delete [] listArray;
        listArray = newlistArray;

        listArray[listSize++] = it;
    }
}

E remove() {
E it = listArray[curr]; // Copy the element
for(int i=curr; i<listSize-1; i++) // Shift them down
listArray[i] = listArray[i+1];
listSize--;
return it;
}

void moveToStart() { curr = 0; }

void moveToEnd() { curr = listSize-1; }

void prev() {
    if (curr != 0)
        curr--;
}

void next() {
    if (curr < listSize)
        curr++;
}

int length() const { return listSize; }

//int maxLength() const { return maxSize; }

int currPos() const { return curr; }

void moveToPos(int pos) {
curr = pos;
}

const E& getValue() const {
    return listArray[curr];
}

int Search(const E& it) const {
    int x = 0,y;
  for( int i = 0; i<listSize; i++){
    if( listArray[i] == it ){
         x = 1;
         y = i;
    }
  }
  if ( x == 1)
    return y;
  else
    return -1;

}

/*void printList(){
    int i;
    if (length() == 0){
        cout<<"<>";
    }
    else if (length() == 1){
        cout<<"<| "<<listArray[0]<<">";
    }
    else{
    for(i=0; i<curr; i++){
       if( i == 0 ){
        cout<<"<"<<listArray[i]<<" ";
       }
       else{
        cout<<listArray[i]<<" ";
       }
    }

    for(int i=curr ; i<length(); i++){
        if( i == 0 && curr == 0){
        cout<<"<| "<<listArray[i]<<" ";
       }
       else if ( i!=0 && i == curr && i == length() - 1)
          cout<<"| "<<listArray[i]<<">";
        else if ( i!=0 && i == curr && i < length() - 1)
          cout<<"| "<<listArray[i]<<" ";
       else if( i == length() - 1){
        cout<<listArray[i]<<">";
       }
       else{
        cout<<listArray[i]<<" ";
       }
    }
   }

}*/
};

#include<iostream>
#include "List.h"
using namespace std;

// Singly linked list node
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

template <typename E> class LList: public List<E> {

private:

Link<E>* head; // Pointer to list header
Link<E>* tail; // Pointer to last element
Link<E>* curr; // Access to current element
int cnt; // Size of list

void init() { // Intialization helper method
curr = tail = head = new Link<E>;
cnt = 0;
}

void removeall() { // Return link nodes to free store
   while(head != NULL) {
   curr = head;
   head = head->next;
   delete curr;
   }
}

public:

LList() {
    init();
}

LList(int defaultSize) {
    int size = defaultSize;
    init();
} // Constructor

LList(E arrayGiven[],int elemCnt){

    init();
    for (int i = 0; i < elemCnt ; i++){
       tail = tail->next = new Link<E>(arrayGiven[i], NULL);
       cnt++;
    }
}

~LList(){removeall(); } // Destructor

void clear() {
    removeall();
    init();
}

void insert(const E& it) {
 curr->next = new Link<E>(it, curr->next);
   if (tail == curr)
    tail = curr->next;
 cnt++;
}

void append(const E& it) { // Append "it" to list
tail = tail->next = new Link<E>(it, NULL);
cnt++;
}

E remove() {
E it = curr->next->element; // Remember value
Link<E>* ltemp = curr->next; // Remember link node
if (tail == curr->next) tail = curr; // Reset tail
curr->next = curr->next->next; // Remove from list
delete ltemp; // Reclaim space
cnt--; // Decrement the count
return it;
}

void moveToStart()
{ curr = head; }

void moveToEnd()
{ //curr = tail;
Link<E>* temp = head;
// March down list until we find the previous element of tail
while (temp->next!=tail) temp=temp->next;
curr = temp; }

// Move curr one step left; no change if already at front
void prev() {
if (curr == head) return; // No previous element
Link<E>* temp = head;
// March down list until we find the previous element
while (temp->next!=curr) temp=temp->next;
curr = temp;
}

// Move curr one step right; no change if already at end
void next()
{ if (curr != tail) curr = curr->next; }

int length() const { return cnt; }

int currPos() const {
Link<E>* temp = head;
int i;
for (i=0; curr != temp; i++)
temp = temp->next;
return i;
}

void moveToPos(int pos) {
  curr = head;
  for(int i=0; i<pos; i++)
     curr = curr->next;
}

const E& getValue() const {
   return curr->next->element;
}

int Search(const E& it) const {

   Link<E>* current = head;
   int i=0;
   while (current != NULL)
    {
        if (current->element == it)
            return i-1;
        current = current->next;
            i++;
    }
    return -1;
}

/*void printList(){
    int i;
    Link<E>* current = head;
    current = current->next;
    if (length() == 0){
        cout<<"<>";
    }
    else if (length() == 1){
        cout<<"<| "<<current->element<<">";
    }
    else{
    for(i=0; i<currPos(); i++){
       if( i == 0 ){
        cout<<"<"<<current->element<<" ";
        current = current->next;
       }
       else{
        cout<<current->element<<" ";
        current = current->next;
       }
    }

    for(int i=currPos() ; i<length(); i++){
        if( i == 0 && currPos() == 0){
        cout<<"<| "<<current->element<<" ";
        current = current->next;
       }
       else if ( i!=0 && i == currPos() && i == length() - 1)
          cout<<"| "<<current->element<<">";
          //current = current->next;
       else if ( i!=0 && i == currPos() && i < length() - 1)
          {cout<<"| "<<current->element<<" ";
          current = current->next;}
       else if( i == length() - 1){
        cout<<current->element<<">";
       }
       else{
        cout<<current->element<<" ";
        current = current->next;
       }
    }
  }
 }*/
};


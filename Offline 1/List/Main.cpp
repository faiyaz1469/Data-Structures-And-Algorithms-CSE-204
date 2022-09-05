#include <bits/stdc++.h>
#include<iostream>
#include "ArrayListImplementation.cpp"
#include "LinkedListImplementation.cpp"
using namespace std;
void printList(int length, int curr, AList<int> &AL2){
    int x;
    if (length == 0){
        cout<<"<>";
    }
    else if (length == 1){
             AL2.moveToPos(0);
        cout<<"<| "<<AL2.getValue()<<">";
    }
    else{
    for(x=0; x<curr; x++){
       if( x == 0 ){
            AL2.moveToPos(x);
        cout<<"<"<<AL2.getValue()<<" ";
       }
       else{
            AL2.moveToPos(x);
        cout<<AL2.getValue()<<" ";
       }
    }

    for(int i=curr ; i<length; i++){
        if( i == 0 && curr == 0){
                AL2.moveToPos(i);
        cout<<"<| "<<AL2.getValue()<<" ";
       }
       else if ( i!=0 && i == curr && i == length - 1){
            AL2.moveToPos(i);
          cout<<"| "<<AL2.getValue()<<">";}
        else if ( i!=0 && i == curr && i < length - 1){
                AL2.moveToPos(i);
          cout<<"| "<<AL2.getValue()<<" ";}
       else if( i == length - 1){
            AL2.moveToPos(i);
        cout<<AL2.getValue()<<">";
       }
       else{
           AL2.moveToPos(i);
        cout<<AL2.getValue()<<" ";
       }
    }
   }

}

int main(){

   int K,X;

   cin>>K;
   cin>>X;
   int i;
   int c,x;

   AList<int> AL(K,X);
   //LList<int> AL(K);
   int Y;
   int P;

   //AList<char> AL(K);
   //LList<char> AL(K);
   //char Y;
   //char P;

   //AList<float> AL(K);
   //LList<float> AL(K);
   //float Y;
   //float P;

   int arr3[5] = {10,12,34,9,1};
   //AList<int> AL(arr3,K,X);
   //LList<int> AL(arr3,K);


   for (AL.moveToStart(); AL.currPos()<K; AL.next()) {
        cin>>Y;
       AL.append(Y);
   }

   int Q = 14;
   int arr1[256],arr2[256];
   int m=0,n=0;
   while (Q != 0){
        cin>>Q;
        arr1[m] = Q;
        m++;
        cin>>P;
        arr2[n] = P;
        n++;
    }

     //AList<int> AL1;
     //LList<int> AL1;
     //AL1.printList();
     //cout<<endl;

    AL.moveToStart();
    //AL.moveToEnd();
    c = AL.currPos();
    printList(AL.length(),AL.currPos(), AL);
    AL.moveToPos(c);
    //AL.printList();
    cout<<endl;

   for( i = 0; i<256; i++){
        Q = arr1[i];
        P = arr2[i];
        if(Q !=0){
      switch(Q)
        {
        case 1:

            AL.clear();
            cout<<"<>"<<endl;
            cout<<"-1"<<endl;
            break;

        case 2:

            AL.insert(P);

            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);

            //AL.printList();
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 3:

            AL.append(P);

            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);

            //AL.printList();
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 4:

            cout<<AL.remove()<<endl;
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
            //AL.printList();
            cout<<endl;
            break;

        case 5:
            AL.moveToStart();
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
           // AL.printList();
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 6:
            AL.moveToEnd();
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
           // AL.printList();
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 7:
            AL.prev();
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
            //AL.printList();
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 8:
            AL.next();
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
            //AL.printList();
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 9:
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
            //AL.printList();
            cout<<endl;
            cout<<AL.length()<<endl;
           // cout<<AL.maxLength()<<endl;
            break;

        case 10:
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
            //AL.printList();
            cout<<endl;
            cout<<AL.currPos()<<endl;
            break;

        case 11:
            AL.moveToPos(P);
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
            //AL.printList();
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 12:
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
            //AL.printList();
            cout<<endl;
            cout<<AL.getValue()<<endl;
            break;

        case 13:
            c = AL.currPos();
            printList(AL.length(),AL.currPos(), AL);
            AL.moveToPos(c);
            //AL.printList();
            cout<<endl;
            cout<<AL.Search(P)<<endl;
            break;

        default:
            break;
        }
      }
      else{
        break;
      }
   }

}




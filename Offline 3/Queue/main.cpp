#include<iostream>
#include "ArrQueue.cpp"
#include "LinkedQueue.cpp"
using namespace std;

template<typename E>
void printList(int length, Queue<E> &AL2){
    int i;
    E arr[length];
        for(i=0; i<length; i++){
            arr[i] = AL2.dequeue();
        }
        if (length == 0){
            cout<<"<>";
        }
        else if (length == 1){
            cout<<"<"<<arr[0]<<">";
        }
        else{
            for(i=0; i<length; i++){
               if( i == 0 ){
                  cout<<"<"<<arr[i]<<",";
               }
               else if(i == length - 1){
                   cout<<arr[i]<<">";
               }
               else{
                   cout<<arr[i]<<",";
               }
            }
        }
        for(i=0;i<length;i++)
             AL2.enqueue(arr[i]);
}



int main(){

   int K;
   cin>>K;

   int i;
   int c,x;

   //AQueue<int> AL(K);
   LQueue<int> AL(K);
   int Y;
   int P;

   for (i=0; i<K; i++) {
        cin>>Y;
        AL.enqueue(Y);
   }

    printList(AL.length(),AL);
    cout<<endl;

   int Q = 14;
   while (Q != 0){
        cin>>Q;
        cin>>P;
      switch(Q)
        {
        case 1:

            AL.clear();
            printList(AL.length(),AL);
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 2:

            AL.enqueue(P);
            printList(AL.length(),AL);
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 3:

            if (AL.length() != 0){
                cout<<AL.dequeue()<<endl;
                printList(AL.length(),AL);
                cout<<endl;
                break;
            }
            else{
                cout<<"Queue is empty!"<<endl;
                break;
            }

        case 4:

            printList(AL.length(), AL);
            cout<<endl;
            cout<<AL.length()<<endl;
            //cout<<AL.maxLength()<<endl;
            break;

        case 5:
            if (AL.length() != 0){
                printList(AL.length(), AL);
                cout<<endl;
                cout<<AL.frontValue()<<endl;
                break;
            }
            else{
                cout<<"Queue is empty!"<<endl;
                break;
            }

        case 6:
            if (AL.length() != 0){
                printList(AL.length(), AL);
                cout<<endl;
                cout<<AL.rearValue()<<endl;
                break;
            }
            else{
                cout<<"Queue is empty!"<<endl;
                break;
            }

        case 7:
            if (AL.length() != 0){
                 cout<<AL.leaveQueue()<<endl;
                 printList(AL.length(),AL);
                 cout<<endl;
                 break;
            }
            else{
                cout<<"Queue is empty!"<<endl;
                break;
            }

        case 8:

            break;

        case 9:


            break;

        case 10:

            break;

        case 11:

            break;

        case 12:

            break;

        case 13:

            break;

        default:
            break;
        }
      }

}









#include<iostream>
#include "ArrayStack.cpp"
#include "LinkedStack.cpp"
using namespace std;

template<typename E>
void printList(int length, int dir, Stack<E> &AL2){
    int i;
    int arr[length];

    if ( dir == -1){
        for(i=length-1; i>=0; i--){
            arr[i] = AL2.pop();
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

        for(i=0; i<length; i++){
            AL2.push(arr[i]);
         }
    }
    else if(dir == 1){
        for(i=0; i<length; i++){
            arr[i] = AL2.pop();
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
        for( i= length-1; i>=0; i--)
             AL2.push(arr[i]);

    }
}



int main(){

   int K;
   cin>>K;

   int i;
   int c,x;

   //AStack<int> AL(K);
   LStack<int> AL(K);
   int Y;
   int P;

   //AStack<char> AL(K);
   //LStack<char> AL(K);
   //char Y;
   //char P;

   //AStack<float> AL(K);
   //LStack<float> AL(K);
   //float Y;
   //float P;

    //int B[5];
    //AStack<int> AL(&B,1);

   for (i=0; i<K; i++) {
        cin>>Y;
        AL.push(Y);
   }


    printList(AL.length(),AL.direction,AL);
    cout<<endl;

   int Q = 14;
   while (Q != 0){
        cin>>Q;
        cin>>P;
      switch(Q)
        {
        case 1:

            AL.clear();
            printList(AL.length(),AL.direction,AL);
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 2:

            AL.push(P);
            printList(AL.length(),AL.direction,AL);
            cout<<endl;
            cout<<"-1"<<endl;
            break;

        case 3:

            if (AL.length() != 0){
                cout<<AL.pop()<<endl;
                printList(AL.length(),AL.direction,AL);
                cout<<endl;
                break;}
            else{
                cout<<"Stack is empty!"<<endl;
                break;
            }

        case 4:

            printList(AL.length(),AL.direction, AL);
            cout<<endl;
            cout<<AL.length()<<endl;
            //cout<<AL.maxLength()<<endl;
            break;

        case 5:
           if (AL.length() != 0){
            printList(AL.length(), AL.direction,AL);
            cout<<endl;
            cout<<AL.topValue()<<endl;
            break;}
            else{
                cout<<"Stack is empty!"<<endl;
                break;
            }

        case 6:
            if(P == 1 || P == -1){
                AL.setDirection(P);
                printList(AL.length(),AL.direction,AL);
                cout<<endl;
                cout<<"-1"<<endl;
                break;
            }
            else{
                cout<<"Wrong direction!"<<endl;
            }

        case 7:

            break;

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








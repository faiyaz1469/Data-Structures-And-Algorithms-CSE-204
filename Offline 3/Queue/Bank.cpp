#include<iostream>
#include "ArrQueue.cpp"
#include "LinkedQueue.cpp"
using namespace std;

int bookBooth1(int arr1[],int arr2[],Queue<int> &AQ,int time){
    int serviceTime = arr2[AQ.dequeue()-1];
    return time+serviceTime;
}

int bookBooth2(int arr1[],int arr2[],Queue<int> &AQ,int time){
    int serviceTime = arr2[AQ.dequeue()-1];
    return time+serviceTime;
}


int enterTime(int arr1[], Queue<int> &AQ){

   int length = AQ.length();
   int arr[length];
   int i;
   for(i=0; i<length; i++){
     arr[i] = AQ.dequeue();
   }

   int entryTime = arr1[arr[0]-1];
   for(i=0; i<length; i++){
      AQ.enqueue(arr[i]);
   }

   return entryTime;
}

int main(){
   int n;
   cin>>n;

   int Q,P,i;
   int arr1[256],arr2[256];

   AQueue<int> AQ(n);
   AQueue<int> Q1(n);
   AQueue<int> Q2(n);

   for(i=0; i<n; i++){
        AQ.enqueue(i+1);
        cin>>Q;
        arr1[i] = Q;
        cin>>P;
        arr2[i] = P;
    }


    int time = 0;
    int serveTime1 = -1;
    int serveTime2 = -1;
    int serviceFinishTime1,serviceFinishTime2;
    int flag1=0,flag2=0;

    while(1){

        if ( time == enterTime(arr1,AQ) || time == serveTime1 || time == serveTime2 ) {

            if (time == serveTime1)
                    flag1 = 0;
            if (time == serveTime2)
                    flag2 = 0;

            if (Q1.length() != 0 && Q2.length() != 0) {

                    if( flag1 == 0 && flag2 == 0){
                        serveTime1 = bookBooth1(arr1,arr2,Q1,time);
                        flag1 = 1;
                    }
                    else if (flag1 == 0 && flag2 == 1){
                        serveTime1 = bookBooth1(arr1,arr2,Q1,time);
                        flag1 = 1;
                    }
                    else if (flag1 == 1 && flag2 == 0){
                        serveTime2 = bookBooth2(arr1,arr2,Q2,time);
                        flag2 = 1;
                    }
                    else if(flag1 == 1 && flag2 == 1){

                        if(Q1.length() > Q2.length())
                            Q2.enqueue(AQ.dequeue());
                        else
                            Q1.enqueue(AQ.dequeue());
                    }
            }

            else if (Q1.length() == 0 && Q2.length() != 0){

                    if( flag1 == 0 && flag2 == 0){
                        serveTime2 = bookBooth1(arr1,arr2,Q2,time);
                        flag2 = 1;
                    }
                    else if (flag1 == 0 && flag2 == 1){
                        serveTime1 = bookBooth1(arr1,arr2,Q1,time);
                        flag1 = 1;
                    }
                    else if (flag1 == 1 && flag2 == 0){
                        serveTime2 = bookBooth2(arr1,arr2,Q2,time);
                        flag2 = 1;
                    }
                    else if(flag1 == 1 && flag2 == 1){
                        Q1.enqueue(AQ.dequeue());
                    }

            }

            else if (Q1.length() != 0 && Q2.length() == 0){

                    if( flag1 == 0 && flag2 == 0){
                        serveTime1 = bookBooth1(arr1,arr2,Q1,time);
                        flag1 = 1;
                    }
                    else if (flag1 == 0 && flag2 == 1){
                        serveTime1 = bookBooth1(arr1,arr2,Q1,time);
                        flag1 = 1;

                    }
                    else if (flag1 == 1 && flag2 == 0){
                        serveTime2 = bookBooth2(arr1,arr2,Q2,time);
                        flag2 = 1;
                    }
                    else if(flag1 == 1 && flag2 == 1){
                        Q2.enqueue(AQ.dequeue());
                    }

            }

            else if ( Q1.length() == 0 && Q2.length() == 0){

                    if( flag1 == 0 && flag2 == 0){
                        serveTime2 = bookBooth2(arr1,arr2,AQ,time);
                        flag2 = 1;
                    }
                    else if (flag1 == 0 && flag2 == 1){
                        serveTime1 = bookBooth1(arr1,arr2,AQ,time);
                        flag1 = 1;
                    }
                    else if (flag1 == 1 && flag2 == 0){
                        serveTime2 = bookBooth2(arr1,arr2,AQ,time);
                        flag2 = 1;
                    }
                    else if(flag1 == 1 && flag2 == 1){
                        Q2.enqueue(AQ.dequeue());
                    }
            }

            if(Q1.length() != 0 && Q2.length() != 0){

                if(Q1.length() > Q2.length()){
                    Q2.enqueue(Q1.leaveQueue());
                }
                else if(Q2.length() > Q1.length()){
                    Q1.enqueue(Q2.leaveQueue());
                }
            }

        }

        //if(AQ.length() == 0 && Q1.length() == 0 && flag1 == 0){
        if(AQ.length() == 0 && Q1.length() == 0){
                flag1 = 0;
            serviceFinishTime1 = serveTime1;
        }

        //if(AQ.length() == 0 && Q2.length() == 0 && flag2 == 0){
        if(AQ.length() == 0 && Q2.length() == 0){
                flag2 = 0;
            serviceFinishTime2 = serveTime2;
        }

        if(AQ.length() == 0 && Q1.length() == 0 && flag1 == 0 && Q2.length() == 0 && flag2 == 0){
        //if(AQ.length() == 0 && Q1.length() == 0 && Q2.length() == 0 ){
            break;
        }

        time++;
    }

    cout<<"Booth 1 finishes service at t = "<<serviceFinishTime1<<endl;
    cout<<"Booth 2 finishes service at t = "<<serviceFinishTime2<<endl;


}


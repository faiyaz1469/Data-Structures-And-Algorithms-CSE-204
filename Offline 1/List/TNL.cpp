#include<iostream>
#include "ArrayListImplementation.cpp"
#include "LinkedListImplementation.cpp"
using namespace std;

int main(){

   int K,L,M;
   int B,T;

   cin>>K;

   /*AList<int> RS(K);
   AList<int> BS(K);
   AList<int> TS(K);*/

   LList<int> RS(K);
   LList<int> BS(K);
   LList<int> TS(K);

   cin>>L;

   for (BS.moveToStart(); BS.currPos()<L; BS.next()) {
        cin>>B;
        BS.append(B);
  }

   cin>>M;

   for (TS.moveToStart(); TS.currPos()<M; TS.next()) {
        cin>>T;
        TS.append(T);
   }

   cin>>T;

   int i=0,j=0,x=0,y=0;
   //int m=0,n=0,u=0,v=0;

   switch(T){

   case 1:

   //int i = 0;
   for (RS.moveToStart(); RS.currPos()<K; RS.next()) {
       RS.append(i);
       i++;
   }
   //int j = 0;
   for (RS.moveToStart(); RS.currPos()<K; RS.next()) {
     if ( j == K-1)
       cout<<RS.getValue()<<endl;
    else
       cout<<RS.getValue()<<",";
       j++;
   }

   //int x =0;
   for (BS.moveToStart(); BS.currPos()<L; BS.next()) {
     for (RS.moveToPos(x); RS.currPos()<K; RS.next()){
        if ( BS.getValue() == RS.getValue()){
            if(RS.currPos() != K-1 && BS.currPos() == L-1){
            x = RS.currPos();
            cout<<BS.getValue();
            //break;
            }
            else{
             x = RS.currPos();
             cout<<BS.getValue();
             break;
            }
        }
        else
           cout<<",";
      }

   }

   cout<<endl;

   //int y =0;
   for (TS.moveToStart(); TS.currPos()<M; TS.next()) {
     for (RS.moveToPos(y); RS.currPos()<K; RS.next()){
        if ( TS.getValue() == RS.getValue()){
            if(RS.currPos() != K-1 && TS.currPos() == M-1){
              y = RS.currPos();
              cout<<TS.getValue();
              //break;
            }
            else{
              y = RS.currPos();
              cout<<TS.getValue();
              break;
            }

        }
        else
             cout<<",";

      }
   }

   break;

   case 2:
          break;

   case 3:
          break;

   default:
          break;

 }

}

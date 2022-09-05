#include<iostream>
#include "ArrayStack.cpp"
#include "LinkedStack.cpp"
using namespace std;

void printList(int length, int dir, AStack<int> &AL2){
    int i;
    int arr[length];

    if ( dir == -1){
        for(i=length-1; i>=0; i--){
            arr[i] = AL2.pop();
        }
        if (length == 0){
            cout<<" ";
        }
        else if (length == 1){
            cout<<""<<arr[0]<<"";
        }
        else{
            for(i=0; i<length; i++){
               if( i == 0 ){
                cout<<""<<arr[i]<<",";
               }
               else if(i == length - 1){
                   cout<<arr[i]<<"";
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
  int n,x;
  cin>>n;
  cin>>x;
  int i,j;
  int arr1[x];
  for(i=0;i<x;i++){
    cin>>j;
    arr1[i] = j;
  }

   int k = 14;
   int t,s;
   int arr3[256],arr2[256],arr4[256];
   int m=0,v=0,w=0;
   int totaltime = 0;

   AStack<int> DS(n*x);
   AStack<int> CS(n*x);
   AStack<int> AT(n);
   AStack<int> AL(n);

   /*LStack<int> DS(n*x);
   LStack<int> CS(n*x);
   LStack<int> AT(n);
   LStack<int> AL(n);*/

   while (k != 0){

        DS.push(m);
        cin>>arr2[m];
        k = arr2[m] ;
        //m++;
        cin>>arr3[m];
        t = arr3[m];
        //v++;
        cin>>arr4[m];
        //s=arr4[m];
        //w++;
        m++;
     if(k !=0){
        if(totaltime >= t)   {
                 s=arr4[DS.pop()];
                totaltime = arr1[s-1]+totaltime;
                CS.push(DS.pop());
                AT.push(totaltime);
             }
        else{
                s=arr4[DS.pop()];
                totaltime = t;
                totaltime = arr1[s-1]+totaltime;
                CS.push(DS.pop());
                AT.push(totaltime);
             }
     }
    }


    //for( i = 0; i<m; i++){
        //k = arr2[i];
        //t = arr3[i];
        //s = arr4[i];
        /*if(k !=0){
             if(totaltime >= t)   {
                totaltime = arr1[s-1]+totaltime;
                AT.push(totaltime);
             }
             else{
                totaltime = t;
                totaltime = arr1[s-1]+totaltime;
                AT.push(totaltime);
             }
        }*/
   // }
    cout<<totaltime<<endl;
    printList(AT.length(),-1,AT);
    cout<<endl;
    int count ,c;
    for( i=1; i<=n;i++){
            count = 0;
        for(c=0; c<m; c++){
            if(arr2[c]==i){
                count++;
            }
            if(count == x){
                  AL.push(i);
                  break;
            }
        }
    }

    if( AL.length() == n)
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;

    printList(AL.length(),-1,AL);


}

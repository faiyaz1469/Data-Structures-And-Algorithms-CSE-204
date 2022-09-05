#include<iostream>
#include<vector>
using namespace std;

class Heap
{

private:

    int array_size;
    int heap_size;
    int *H;
    int upper_limit;
    bool isSorted = false;

public:

    // default constructor
    Heap()
    {
        array_size = 5 + 1;
        heap_size = 0;
        H = new int[array_size];
    }

    // first parameterized constructor
    Heap(int n)
    {
        array_size = n + 1; // H[0] garbage value & counting starts from H[1]
        heap_size = 0;
        H = new int[array_size];
    }

    // second parameterized constructor
    Heap(vector<int> &V)
    {
        for (auto j = V.begin(); j != V.end(); ++j){
            insert(*j);
        }
     }


    // insert method
    void insert(int x)
    {
        if(heap_size >= array_size - 1)
        {
            cout<<"Heap Overflows!"<<endl;
            return;
        }

        int temp = x;
        int i = heap_size + 1;

        while(i > 1 && temp > H[i/2])
        {
            H[i] = H[i/2];
            i = i/2;
        }
        H[i] = temp;
        heap_size++;

        isSorted = false;
    }

    // delete method
    void deleteKey()
    {
        int i, j;
        int temp;
        temp = H[1];

        H[1] = H[heap_size]; // transferring last element to root
        i = 1;
        j = 2*i;

        while(j <= heap_size-1)
        {
            if(H[j+1] > H[j])
                j++;

            if(H[i] < H[j])
            {
                swap(H[i], H[j]);
                i = j;
                j = 2*j;
            }
            else
            {
                break;
            }
        }
        H[heap_size] = temp;
        heap_size--;
    }

    // size method
    int size()
    {
        return heap_size;
    }

    // getMax method
    int getMax()
    {
        int maxValue = H[1];

        return maxValue;
    }

    void createHeap(int *A, int n)
    {
        for(int i=0; i<n; i++)
        {
            insert(A[i]);
        }
    }

    void heapsort()
    {
        upper_limit = heap_size;
        while(heap_size > 0)
            deleteKey();
        isSorted = true;
    }

    void printHeap()
    {
        if(heap_size == 0 || isSorted == true)
        {
            cout<<"Heap is empty"<<endl;
            return;
        }

        for(int i=1; i<=heap_size; i++)
        {
            cout<<H[i]<<" ";
        }
        cout<<endl;
    }

    void printSortedArray()
    {
        if(isSorted == false)
        {
            cout<<"Array not sorted"<<endl;
            return;
        }

        for(int i=1; i<=upper_limit; i++)
        {
            cout<<H[i]<<" ";
        }
        cout<<endl;
    }

    int getUpperLimit()
    {
        return upper_limit;
    }

    int* getSortedArray()
    {
        if(isSorted == false)
            return nullptr;
        return H;
    }
};

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void heapsort(vector<int> &V)
{
    int t = V.size();
    int *B;
    B = &V[0];

    Heap h(t);
    h.createHeap(B,t);
    h.heapsort();

    B = h.getSortedArray();

    for(int i=t; i>=1; i--)
    {
        V[t-i] = B[i];
    }

}

void printVector(vector<int> &V)
{
    for(int i=0; i<V.size(); i++)
        cout<< V[i] <<" ";
    cout<<endl;
}

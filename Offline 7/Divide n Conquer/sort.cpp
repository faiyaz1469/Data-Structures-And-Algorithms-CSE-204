#include<ctime>
#include <chrono>
#include <thread>
#include<fstream>
#include<vector>
#include<cstdio>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/// generateRandomArray function
int* generateRandomArray(int n)
{
    srand(time(NULL));
    int *R = new int[n];

    for(int i=0; i<n; i++)
    {
        R[i] = rand() % n;
    }
    return R;
}

/// generate a copy from a given array
int* generateArrayCopy(int *A, int n)
{
    int *R = new int[n];

    for(int i=0; i<n; i++)
    {
        R[i] = A[i];
    }
    return R;
}

/// Insertion Sort
void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

///Merge Sort
void merge(int *A, int low, int mid, int high)
{
    int i=low;
    int j=mid+1;
    int k=0;

    int *C = new int[high-low+1];

    while(i<=mid && j<=high)
    {
        if(A[i] <= A[j])
            C[k++] = A[i++];
        else
            C[k++] = A[j++];
    }

    // copy if any elements remain in the first part of the list
    while(i<=mid)
    {
        C[k++] = A[i++];
    }

    // copy if any elements remain in the second part of the list
    while(j<=high)
    {
        C[k++] = A[j++];
    }

    k=0;
    // copying back merged elements
    for(int i=low; i<=high; i++)
    {
        A[i] = C[k++];
    }
}

// mergeSort function
void mergeSort(int *A, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}


/// Quicksort (Last element as Pivot)
void swap2(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array,
and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int partition (int *arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap2(&arr[i], &arr[j]);
        }
    }
    swap2(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void normalQuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        normalQuickSort(arr, low, pi - 1);
        normalQuickSort(arr, pi + 1, high);
    }
}

/// Randomized Quicksort
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}


int partition2(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {

        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If two pointers met
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
// In Hoare partition the low element is selected
// as first pivot
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swap A[random] with A[high]
    swap(arr[random], arr[low]);

    return partition2(arr, low, high);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low  --> Starting index,
// high  --> Ending index
void randQuickSort(int arr[], int low, int high)
{
    if (low < high) {
        // pi is partitioning index,
        // arr[p] is now at right place
        int pi = partition_r(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        randQuickSort(arr, low, pi);
        randQuickSort(arr, pi + 1, high);
    }
}
// Hoare's partition function
/*int HoarePartition(int *A, int low, int high)
{
    int pivot = A[low+(high-low)/2];
    int i = low-1;
    int j = high+1;

    while(true)
    {
        while(A[++i] < pivot);
        while(A[--j] > pivot);

        if(i>=j) return j;
        swap(A[i], A[j]);
    }
}

// Random quickSort function recursive
void randQuickSort(int *A, int low, int high)
{
    int p = HoarePartition(A, low, high);
    if(low >= high) return;

    randQuickSort(A, low, p);
    randQuickSort(A, p+1, high);
}
*/
/// calculate average running time function
void calculateAverageRunningTime(int n)
{
    ofstream fout;
    fout.open("table.csv", ios::out | ios::app);
    int *A1,*A2,*A3,*A4,*A5,*A6,*A7;

    int k=0;
    clock_t start_time;
    clock_t end_time;

    float durationMerge=0,durationQuick=0,durationRandQuick=0,durationInsert=0,durationSortedQuick=0,durationSortedRandQuick=0,durationSTLSort=0;
    float time_sum_Merge=0,time_sum_Quick=0,time_sum_RandQuick=0,time_sum_Insert=0,time_sum_SortedQuick=0,time_sum_SortedRandQuick=0,time_sum_STLSort=0;
    float time_avg_Merge=0,time_avg_Quick=0,time_avg_RandQuick=0,time_avg_Insert=0,time_avg_SortedQuick=0,time_avg_SortedRandQuick=0,time_avg_STLSort=0;

        while(k<20)
        {

            A1 = generateRandomArray(n);
            A2 = generateArrayCopy(A1, n);
            A3 = generateArrayCopy(A1, n);
            A4 = generateArrayCopy(A1, n);
            A5 = generateArrayCopy(A1, n);


            start_time = clock();
            mergeSort(A1, 0, n-1);
            end_time = clock();
            durationMerge = ((end_time - start_time)*1000) / CLOCKS_PER_SEC;

            A6 = generateArrayCopy(A1, n);
            A7 = generateArrayCopy(A1, n);

            start_time = clock();
            normalQuickSort(A2, 0, n-1);
            end_time = clock();
            durationQuick = ((end_time - start_time)*1000) / CLOCKS_PER_SEC;

            start_time = clock();
            randQuickSort(A3, 0, n-1);
            end_time = clock();
            durationRandQuick = ((end_time - start_time)*1000) / CLOCKS_PER_SEC;

            start_time = clock();
            insertionSort(A4, n);
            end_time = clock();
            durationInsert = ((end_time - start_time)*1000) / CLOCKS_PER_SEC;

            start_time = clock();
            normalQuickSort(A6, 0, n-1);
            end_time = clock();
            durationSortedQuick = ((end_time - start_time)*1000) / CLOCKS_PER_SEC;

            start_time = clock();
            randQuickSort(A7, 0, n-1);
            end_time = clock();
            durationSortedRandQuick = ((end_time - start_time)*1000) / CLOCKS_PER_SEC;

            start_time = clock();
            sort(A5, A5 + n);
            end_time = clock();
            durationSTLSort = ((end_time - start_time)*1000) / CLOCKS_PER_SEC;


            time_sum_Merge += durationMerge;
            time_sum_Quick += durationQuick;
            time_sum_RandQuick += durationRandQuick;
            time_sum_Insert += durationInsert;
            time_sum_SortedQuick += durationSortedQuick;
            time_sum_SortedRandQuick += durationSortedRandQuick;
            time_sum_STLSort += durationSTLSort;

            k++;
        }

        time_avg_Merge = time_sum_Merge / k;
        time_avg_Quick = time_sum_Quick / k;
        time_avg_RandQuick = time_sum_RandQuick / k;
        time_avg_Insert = time_sum_Insert / k;
        time_avg_SortedQuick = time_sum_SortedQuick / k;
        time_avg_SortedRandQuick = time_sum_SortedRandQuick / k;
        time_avg_STLSort = time_sum_STLSort / k;


        cout<<"For n = "<<n<<":"<<endl;

        cout<<"# Merge Sort: "<<time_avg_Merge<<" ms"<<endl;
        cout<<"# QuickSort: "<<time_avg_Quick<<" ms"<<endl;
        cout<<"# Randomized QuickSort: "<<time_avg_RandQuick<<" ms"<<endl;
        cout<<"# Insertion Sort: "<<time_avg_Insert<<" ms"<<endl;
        cout<<"# QuickSort with Sorted Input: "<<time_avg_SortedQuick<<" ms"<<endl;
        cout<<"# Randomized QuickSort with Sorted Input: "<<time_avg_SortedRandQuick<<" ms"<<endl;
        cout<<"# STL Sort: "<<time_avg_STLSort<<" ms"<<endl;

        cout<<endl;

        fout << n << "," << time_avg_Merge << ","<< time_avg_Quick << "," << time_avg_RandQuick << ","<< time_avg_Insert << ",";
        fout << time_avg_SortedQuick << "," << time_avg_SortedRandQuick << ","<< time_avg_STLSort;
        fout<<"\n";
        fout.close();
}

int main()
{
    int arr[] = {5,10,100,1000,10000,100000};

    for (int i=0; i<=5; i++)
    {
        calculateAverageRunningTime(arr[i]); /// n = 100000 takes 5 minutes to finish
    }

    return 0;
}



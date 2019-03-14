#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<ctime>
#include<chrono>

using namespace std;
int kth_value;//holds the value of the element at the k-th position.

//merge-sort algorithm(to merge the divided array after sorting)
void mergeArray(int arr[],int FH_Arr[],int SH_Arr[],int fh,int sh,int start,int kth_element)
{

    //joining the separated array into one main array
    int fhs = 0; // start for the first half
    int shs = 0; // start for the second half
    while (fhs < fh && shs < sh)
    {
        if (FH_Arr[fhs] <= SH_Arr[shs])
        {
            arr[start] = FH_Arr[fhs];
            fhs++;
        }
        else if(SH_Arr[shs]<FH_Arr[fhs])
        {
            arr[start] = SH_Arr[shs];
            shs++;
        }
        else {return;}
        if(start==(kth_element))
        {
            kth_value=arr[start];
        }
        start++;
    }

    //to copy if any balance element existed any of the half array
    while (fhs < fh)
    {
        arr[start] = FH_Arr[fhs];
        if(start==(kth_element))
        {
            kth_value=arr[start];
        }
        fhs++;
        start++;
    }
    while (shs < sh)
    {
        arr[start] = SH_Arr[shs];
        if(start==(kth_element))
        {
            kth_value=arr[start];
        }
        shs++;
        start++;
    }
}

//merge-sort algorithm(this part divides the array)
void mergeSort(int arr[], int start, int ending,int kth_element)
{
    if (start < ending)
    {
        //to divide the array into half
        int middle =start+(ending-start)/2;

        //to sort and merge the first and second halves
        mergeSort(arr, start, middle,kth_element);
        mergeSort(arr, middle+1, ending,kth_element);

        int fh = middle - start + 1;//first half size
        int sh = ending - middle;//second half size

        //temporary arrays for first half and second half of the main array
        int* FH_Arr=new int[fh];
        int* SH_Arr=new int[sh];

        //copy the data to the temporary arrays accordingly
        for (int x = 0 ; x < fh ; x++)
        {
            FH_Arr[x] = arr[start + x];
        }
        for (int y = 0;y < sh ; y++)
        {
            SH_Arr[y] = arr[middle + 1 + y];
        }
        mergeArray(arr,FH_Arr,SH_Arr,fh,sh,start,kth_element);
        delete [] FH_Arr;
        delete [] SH_Arr;
    }
}

//to printout the array
void printArray(int arr[], int arr_size)
{
    for (int i=0; i < 7; i++)
    {
        cout<< arr[i]<<";";
    }


}

//to initialize array with values
void setArray(int arr[], int arr_size)
{
    srand(time(NULL));
    int rand_value;
    for(int x = 0 ; x < 7 ; x++)
    {
        rand_value=rand()%arr_size+1;
        arr[x]=rand_value;
    }
}

//the driver program
int main()
{
    int kth_element=5;
    //Testing with a sample array to make sure merge-sort functions correctly
    int testarray[7] = {1,2,3,4,5,6,7};

    setArray(testarray,7);
    cout<<"Testing with an array of size 20(with k=5, for k-th element): "<<endl;
    cout<<"Before sorting:"<<endl;
   // printArray(testarray,20);
    cout<<endl;
    mergeSort(testarray, 0, 19,kth_element-1);
    cout<<"After sorting:"<<endl;
    //printArray(testarray,20);
    cout<<endl;
    cout<<"k-th element ="<<kth_value<<endl;
    cout<<endl;

//the part to test the merge-sort algorithm with various size of array
    int arr_size;
    cout<<"Enter array size:"<<endl;
    cin>>arr_size;
    cin.clear();cin.ignore();


    int* arr=new int[arr_size];

    setArray(arr,arr_size);
    cout<<"Enter k-th element:"<<endl;
    cin>>kth_element;


//recording the time to compute amount of time taken by the merge-sort algorithm to sort
    auto start = chrono::system_clock::now();
    mergeSort(arr, 0, arr_size - 1,kth_element-1);
    auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;

    cout<<"*******************After Sorting****************** : :"<<endl;
    printArray(arr, arr_size);
    cout<<endl;
    cout<<"k-th element ="<<kth_value<<endl;
    cout << "Time taken by the algorithm ="<< duration.count() <<endl;

    delete [] arr;
    return 0;
}




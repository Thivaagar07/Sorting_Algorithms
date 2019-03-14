#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "timer.h"

void home();

void print(int *input, int inputsize)
{
    for ( int i = 0; i < inputsize; i++ )
        cout << input[i] << " ";
    cout << endl;
}



//====================Fixed_Pivot===============================================
int partition_fixed(int* A, int p, int r, int inputsize){
     int pivot = A[p];

    //int pivot_index = p + rand() % (r-p+1);
    //int left = p;
    //int right = r - 1;
    //int size = right - left;
    //int pivot = A[rand() % size + left ];
    cout << "Pivot: " << pivot << endl;
    while ( p < r ) {
        while ( A[p] < pivot ) {
            p++;
        }
        while ( A[r] > pivot ) {
            r--;
        }
        if ( A[p] == A[r] ) {
            p++;
        }
        else if ( p < r ) {
            int tmp = A[p];
            A[p] = A[r];
            A[r] = tmp;
        }
        print(A,inputsize);
    }
    return r;
}




int quick_select_fixed(int* A, int p, int r, int k,int inputsize)
{
    if ( p == r ) {
        return A[p];
    }


    int j = partition_fixed(A, p, r, inputsize);
    print(A,inputsize);
    int length = j - p + 1;

    if ( length == k ) {
        return A[j];
    }
    else if ( k < length ) {
        return quick_select_fixed(A, p, j - 1, k, inputsize);
    }
    else {
        return quick_select_fixed(A, j + 1, r, k - length, inputsize);
    }

}
//==========================================================================




//====================Random_Pivot===============================================
int partition_random(int* A, int p, int r, int pivot, int inputsize){


    //int pivot = A[r];
    //int pivot_index = p + rand() % (r-p+1);
    //int left = p;
    //int right = r - 1;
    //int size = right - left;
    //int pivot = A[rand() % size + left ];
    //cout << "Pivot: " << pivot << endl;
    while ( p < r ) {
        while ( A[p] < pivot ) {
            p++;
        }
        while ( A[r] > pivot ) {
            r--;
        }
        if ( A[p] == A[r] ) {
            p++;
        }
        else if ( p < r ) {
            int tmp = A[p];
            A[p] = A[r];
            A[r] = tmp;
        }
       // print(A,inputsize);
    }
    return r;
}




int quick_select_random(int* A, int p, int r, int k, int inputsize)
{
    if ( p == r ) {
        return A[p];
    }

    //int pivot = A[r];
    //int pivot_index = p + rand() % (r-p+1);
    //int left = p;
    //int right = r - 1;
    //int size = right - left;
    //int pivot = A[rand() % size + left ];
    //cout << "Left" << p << endl;
    //cout << "Right" << r << endl;
    srand(time(0));
    int value = rand() % r + p;
    cout << "Val: " << value << endl;
    int pivot = A[value];
    //int pivot = A[p + rand() % p + r];
    int j = partition_random(A, p, r, pivot, inputsize);
    print(A,inputsize);
    int length = j - p + 1;

    if ( length == k ) {
        return A[j];
    }
    else if ( k < length ) {
        return quick_select_random(A, p, j - 1, k, inputsize);
    }
    else {
        return quick_select_random(A, j + 1, r, k - length, inputsize);
    }

}
//==========================================================================



void algorithm() {

    int inputsize = 9;
   // int* A= new int[inputsize];
    int k;

    //const int n = 10000;
    //int* A = new int[n] {11, 23, 5, 27, 33, 1, 45, 18};
    //int* S = new int[n];

    for(int i=0; i<20; i++) {
        //float B[i], C[i];
        float Random, Fixed;
        do {
            cout << "Algorithm testing" << endl;
            cout << "-----------------" << endl << endl;
            cout << "Input size: ";
           // cin >> inputsize; //input size of array


            srand(time(0));
//            for(int i=0; i<inputsize; i++){
//                A[i] = 1+(rand()%999);
//                //cout<<A[i]<<" ";
//            }

            int A[10] = {14,18,1,10,8,7,13,20,5};
            cout << endl << endl;

            cout << "Input K-th element : ";
            cin >> k;

            cout << endl << endl;

            TICK();
            cout << "The Value of " << k << "-th smallest element in QuickSelect using fixed pivot is : " << quick_select_fixed(A,0,inputsize-1,k, inputsize) << endl;
            TOCK();
            cout<< endl;
            //Show duration
            Fixed = DURATION();
            cout << "\nDuration (QuickSelect): " << DURATION() << " seconds";
            cout << endl;
            cout << endl;
            TICK();
            cout << "The Value of " << k << "-th smallest element in QuickSelect using random pivot is : " << quick_select_random(A,0,inputsize-1,k, inputsize) << endl;
            TOCK();
            cout<< endl;
            //Show duration
            Random = DURATION();
            cout << endl << endl;
            cout << "\nDuration (QuickSelect): " << DURATION() << " seconds";
            cout<< endl << endl;
            cout << "Input Size:   " << inputsize << endl;
            //B[i] = DURATION();
            cout << "Fixed Pivot:  " << Fixed << endl;
            cout << "Random Pivot: " << Random << endl;
        }while(i<20);
    }
}

void home() {

    system("cls");
    int selection;

    cout << "Welcome!" << endl;
    cout << "--------" << endl << endl;
    cout << "Please select one of these option: " << endl;
    cout << "1. Proceed to Algorithm test." << endl;
    cout << "2. Exit." << endl;
    do {
        cout << "Input Selection : ";
        cin >> selection;
        switch(selection) {
            case 1:
                system("cls");
                algorithm();
            break;


            case 2:
                cout << endl << "Thank you and Good bye" << endl << endl;
                system("pause");
                system("exit");
            break;
            default:
                cout << endl << "Invalid input!" << endl << endl;
                system("pause");
                home();
        }
    }while(selection>2);
}

int main()
{
    home();
}


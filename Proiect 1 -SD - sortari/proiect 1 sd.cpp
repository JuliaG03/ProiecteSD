#include <bits/stdc++.h>
#include <iostream>
using namespace std;
///----------------------------------BUBBLE SORT
void bubbleSort(int vector[], int n)
    {
    int i, j;
        for (i=0; i < n-1; i++)    // Ultimele i elemente sunt sortate
            for (j=0; j < n-i-1; j++)
                if (vector[j] > vector[ j+1 ])
                    swap(vector[j], vector[ j+1 ]);
    }

// afisare vector
void printvector(int vector[], int lungime)
{
    int i;
    for (i = 0; i < lungime; i++)
        cout << vector[i] << " ";
    cout << endl;
}

///-------COUNTING SORT



int main()
{}


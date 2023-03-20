#include <bits/stdc++.h>
#include <iostream>
using namespace std;
///----------------------------------BUBBLE SORT

void interschimbare(int *var1, int *var2)
    {int aux = *var1;
    *var1 = *var2;
    *var2 = aux;
    }

void bubbleSort(int vector[], int n)

    {int i, j;
    for (i = 0; i < n-1; i++)
       {bool interschimbat = false;

        for (j = 0; j < n-i-1; j++)
           { if (vector[j] > vector[j+1]){interschimbare(&vector[j], &vector[j+1]);
                                    interschimbat = true;}}
           if(interschimbat == false)
                break;
       }
    }


///-------COUNTING SORT

void CountingSort(int vector[], int n) {
int aux[n];

int max = vector[0];

    for (int i = 1; i < n; i++) { if (vector[i] > max) max = vector[i];}
int frecventa[max];
    for (int i = 0; i <= max; ++i) {frecventa[i] = 0;}
    for (int i = 0; i < n; i++) {frecventa[vector[i]]++;}

    // calculam in i suma totala a frecventei elementelor pana in pozitia i
    for (int i = 1; i <= max; i++) {frecventa[i] += frecventa[i - 1];}

    //in vectorul sortat, fiecarei valoare ii este alocat suma totala a frecventelor pana in acel moment - 1
	for (int i = n - 1; i >= 0; i--)
            {aux[frecventa[vector[i]] - 1] = vector[i];
            frecventa[vector[i]]--;}

    for (int i = 0; i < n; i++) {
        vector[i] = aux[i];}
}



int main()
{}


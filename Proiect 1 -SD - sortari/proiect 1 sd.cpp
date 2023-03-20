#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
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

///---------------------MERGE SORT

void merge(int a[], int stanga, int mij, int dreapta)

{   int i,j,k;
    int n1 = mij-stanga+1;
    int n2 = dreapta-mij;
    int st[n1], dr[n2];

    for (i=0; i < n1; i++)
        st[i] = a[ stanga+i ];
    for (j=0; j < n2; j++)
        dr[j] = a[ mij+1+j ];

    i = 0;
    j = 0;
    k = stanga;

    while ( i<n1 && j<n2 ){
        if (st[i] <= dr[j]) {a[k] = st[i];
                            i++;}
        else {a[k] = dr[j];
            j++;}
        k++;}

    while (i < n1){
        a[k] = st[i];
        i++;
        k++;}

    while (j < n2) {
        a[k] = dr[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int stanga, int dreapta)
        {
    int mij;
    if(stanga < dreapta)
        {mij = (stanga + dreapta)/2;
        mergeSort(a, stanga, mij);
        mergeSort(a, mij + 1, dreapta);
        merge(a, stanga, mij, dreapta);
        }
        }



int main()
{
int v[10] = {8, 4, 5, 1, 3, 9, 0, 2, 7, 6 };



cout<<"merge sort:  \n";

mergeSort(v,0,9);
for(int i=0;i<10;i++) cout<< v[i]<< " ";

cout<<"\n\n bubble sort:  \n";

bubbleSort(v,9);
for(int i=0;i<10;i++) cout<< v[i]<< " ";

cout<<"\n\n counting sort:  \n";

CountingSort(v,9);
for(int i=0;i<10;i++) cout<< v[i]<< " ";

sort(v,v+10);

for(int i=0;i<10;i++) cout<< v[i]<< " ";





}


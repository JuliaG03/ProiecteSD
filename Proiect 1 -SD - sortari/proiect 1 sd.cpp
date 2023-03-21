#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace std::chrono;
///----------------------------------BUBBLE SORT

void interschimbare(long *var1, long *var2) {
    *var1 ^= *var2;
    *var2 ^= *var1;
    *var1 ^= *var2;
}
void bubbleSort(long vector[], int n)

    {int i, j;
    for (i = 0; i < n-i-1; i++)
       {bool interschimbat = false;

        for (j = 0; j < n-i-1; j++)
           { if (vector[j] > vector[j+1])
               {interschimbare(&vector[j], &vector[j+1]);
                interschimbat = true;}}
           if(interschimbat == false)
                break;
       }
    }


///--------------------------------COUNTING SORT

void countingSort(long vector[], int n) {

    int* aux = new int[n];

int max = vector[0];

    for (int i = 1; i < n; i++) { if (vector[i] > max) max = vector[i];}
 int* frecventa = new int[max + 1];
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
    delete[] aux;
    delete[] frecventa;
}

///---------------------MERGE SORT

void merge( long a[], int stanga, int mij, int dreapta)

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

void mergeSort(long a[], int stanga, int dreapta)
        {
    int mij;
    if(stanga < dreapta)
        {mij = (stanga + dreapta)/2;
        mergeSort(a, stanga, mij);
        mergeSort(a, mij + 1, dreapta);
        merge(a, stanga, mij, dreapta);
        }
        }
///------------------------------------Radix Sort

void zero(long v[] , long n){
    for(long i = 0; i < n ; i++)
        v[i] = 0;}

long maxx(long v[] , long n){
    long maxim = 0;
    for(long i = 0; i < n ; i++) if(maxim < v[i]) maxim = v[i];
    return maxim;}

long cifre(long n){
    long counter = 0;
    while(n){counter++;
            n = n/10;}
    return counter;}

void numara(long v[],long n,long exp){
    long cnt[10];
    long *aux = new long[n];
    exp = pow(10,exp);
    zero(cnt,10);
    for(long i=0; i<n ;i++)cnt[(v[i]/exp)%10]++;
    cnt[0]--;
    for(long i=1;i<10;i++) cnt[i] += cnt[i-1];
    for(long i=n-1;i>=0;i--){aux[cnt[(v[i]/exp)%10]] = v[i];
                                    cnt[(v[i]/exp)%10]--;}
    for(long i=0;i<n;i++){v[i] = aux[i];}

    delete[] aux;}

void radixSort(long v[] , long n){
    long *aux = new long[n];
    long nrPasi = cifre(maxx(v,n));
    for(int i = 0 ; i < nrPasi ; i++){
        zero(aux,n);
        numara(v,n,i);}
    delete[] aux;}

///-----------------------------------Shell Sort

void shellSort(long v[], long n)
    {for (int gap = n/2; gap > 0; gap /= 2)
        {for (int i = gap; i < n; i += 1)
            {long aux = v[i];
            long j=i;
            while(j >= gap && v[ j-gap ] > aux){v[j] = v[j - gap];
                                                j = j-gap;}
            v[j] = aux;}}}


//declarare
    int n = 6;      //puterea lui 10 de elemente
    int putereExp = 4;  //cate cifre sa aibe numarul
    long nrElemente = pow(10,n);
    long *v = new long[nrElemente];

int main(){

    long exp = pow(10,putereExp);
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<long long unsigned> distribution(0,0xFFFFFFFFFFFFFFFF);

    for (int i = 0; i < nrElemente; i++)
          v[i] = distribution(generator)%exp;

        auto start = high_resolution_clock::now();
    //mergeSort(v,0,nrElemente-1);
    //bubbleSort(v,nrElemente);
    //radixSort(v,nrElemente);
    //shellSort(v,nrElemente);
    //countingSort(v,nrElemente);
    sort(v,v+nrElemente);
        auto stop = high_resolution_clock::now();
//afisare(v,nrElemente);
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time: "<<duration.count();  //microsec

    delete[] v;

      return 0;


}





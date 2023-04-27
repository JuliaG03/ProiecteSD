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
void merge(long arr[], int l, int mid, int r){


    int i = 0 , j = 0 , k = l;

    //limite superioare pt vectori
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int* arr1 = new int[n1];
    int* arr2 = new int[n2];

    for(int i=0; i<n1; i++) arr1[i] = arr[ l+i ];
    for(int i=0; i<n2; i++) arr2[i] = arr[ mid+i+1 ];

    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){arr[k] = arr1[i];
                                i++;}
        else{arr[k] = arr2[j];
            j++;}
        k++;}

    while(i < n1) arr[k++] = arr1[i++];
    while(j < n2) arr[k++] = arr2[j++];
    delete[] arr1;
    delete[] arr2;}


void mergeSort(long arr[], int l, int r){
    if(l < r){
        int mid = (l + r - 1) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);}}

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
    for(long i=n-1;i>=0;i--){aux[ cnt[(v[i]/exp)%10 ]] = v[i];
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
 //   int n = 6;      //10 la puterea n elemente
 //   int putereExp = 4;  //cate cifre sa aibe numarul
  //  long nrElemente = pow(10,n);
  //  long *v = new long[nrElemente];

int main(){
long  v1[] = {14, 23,10,7,100,39};
long  v2[] =  {14, 23,10,7,100,39};
long  v3[] =  {14, 23,10,7,100,39};
long  v4[] =  {14, 23,10,7,100,39};
long  v5[] =  {14, 23,10,7,100,39};
long  v6[] =  {14, 23,10,7,100,39};

long nrElemente = 5;
  // long exp = pow(10,putereExp);
   // random_device rd;
   // default_random_engine generator(rd());
  //  uniform_int_distribution<long long unsigned> distribution(0,0xFFFFFFFFFFFFFFFF);

  //  for (int i = 0; i < nrElemente; i++)
    //      v[i] = distribution(generator)%exp;

  //      auto start = high_resolution_clock::now();

    cout<<"\nMerge sort : ";
    mergeSort(v1,0,nrElemente-1);
    for(int i=0;i<nrElemente;i++){cout<<v1[i]<<" ";}
    cout<<"\nBubble sort: ";
    bubbleSort(v2,nrElemente);
    for(int i=0;i<nrElemente;i++){cout<<v2[i]<<" ";}
    cout<<"\nRadix sort: ";
    radixSort(v3,nrElemente);
    for(int i=0;i<nrElemente;i++){cout<<v3[i]<<" ";}
    cout<<"\nShell sort: ";
    shellSort(v4,nrElemente);
    for(int i=0;i<nrElemente;i++){cout<<v4[i]<<" ";}
    cout<<"\nCounting sort: ";
    countingSort(v5,nrElemente);
    for(int i=0;i<nrElemente;i++){cout<<v5[i]<<" ";}
    cout<<"\n Sort C++: ";
    sort(v6,v6+nrElemente);
    for(int i=0;i<nrElemente;i++){cout<<v6[i]<<" ";}
       // auto stop = high_resolution_clock::now();

   // auto duration = duration_cast<microseconds>(stop - start);
  //  cout<<"Time: "<<duration.count();  //microsec


      return 0;

}





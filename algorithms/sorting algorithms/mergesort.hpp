#include<iostream>
using namespace std;

template <class T>
void merge (T* arr, size_t mid, size_t n){
    size_t ptr1 = 0, ptr2 = mid, d=0;
    T* merged = new T[n];
    while(ptr1<mid && ptr2<n){
        if(arr[ptr1]<arr[ptr2]) merged[d++]=arr[ptr1++];
        else merged[d++]=arr[ptr2++];
    }
    while(ptr1<=mid-1) merged[d++]=arr[ptr1++];
    while(ptr2<=n  -1) merged[d++]=arr[ptr2++];

    for(size_t i=0;i<n;i++)arr[i]=merged[i];
    delete[] merged;
}

template <class T>
void mergesort (T* arr, size_t n){
    
    if (n<2) return;
    size_t d = n/2;
    mergesort (arr  ,   d);
    mergesort (arr+d, n-d);
    merge (arr, d, n);
}
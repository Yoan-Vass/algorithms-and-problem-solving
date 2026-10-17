#include<iostream>
using namespace std;

template <typename T>
void heapify (T* arr, size_t index, size_t n){
    size_t largest = index;
    if(2*index+1 < n && arr[largest]<arr[2*index+1]) largest=2*index+1;
    if(2*index+2 < n && arr[largest]<arr[2*index+2]) largest=2*index+2;
    if(largest==index)return;
    swap(arr[index],arr[largest]);
    heapify(arr,largest,n);
}

template <typename T>
void heapsort (T* arr, size_t n){
    size_t half = n/2-1;
    for(int i=half;i>=0;i--) heapify(arr,i,n);//step 1) make a heap from the array in place
    for(size_t i=0;i<n;i++){
        swap (arr[0],arr[n-1-i]);//step 2) put max element at the end
        heapify(arr, 0, n-i-1);
    }
}

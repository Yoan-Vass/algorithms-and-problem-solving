#include<iostream>
using namespace std;


template <class T>
size_t HoarePartition (T* arr, int n) {//Hoare's partition scheme
    int left=-1, right = n;
    T pivot = arr[0];
    while(1){        
        do left ++; while (arr[left ] < pivot);
        do right--; while (arr[right] > pivot);
       
        if(right<=left) return right;
        swap(arr[left], arr[right]);
    }
}

template <class T>
size_t HoareBetaPartition (T* arr, int n){
    int left = 0, right = n - 1;
    //!!! not working
    T pivot = arr [0];
    while (left != right) {
        if (arr[left] < pivot) left++;
        else {
            if (arr[right] >= pivot) right--;
            else std::swap(arr[left], arr[right]);
        }
    }
    if (arr[left] < pivot) return left;
    return left - 1;
}

template <class T>
size_t LomutoPartition (T* arr, int n) {//Lomuto partition scheme
    T pivot = arr[n-1];
    size_t i,j=0;
    for (i=0; i<n-1; i++){
        if(arr[i] <= pivot) swap ( arr[j++], arr[i]);
    }
    swap (arr[j], arr[n-1]); //position the pivot
    return j;
}

template <class T>
void quicksort (T* arr, int n) {
    if(n>1){
        // int pindex = LomutoPartition (arr, n);
        int pindex = HoarePartition (arr, n);
        // quicksort(arr, pindex-1); //Lomuto
        quicksort(arr, pindex+1); //Hoare's
        quicksort(arr+pindex+1, n-pindex-1);
    }
}

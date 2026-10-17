#include<iostream>
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "heapsort.hpp"
using namespace std;

int main(){

    //int a[]={4,2,3,5,1,6,4,0};
    int a[]={4,2,3,5,1,3,4,2,2,5,6,7,0};
    heapsort (a,13);
    //mergesort(a,13);
    for(size_t i=0;i<13;i++)cout<<a[i]<<" "; cout<<endl;

    return 0;
}
/*

*/
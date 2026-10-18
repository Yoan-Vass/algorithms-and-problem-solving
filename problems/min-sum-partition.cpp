// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int best[100005], sum = 0, n, arr[100005], m;

// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    // best[i][j] = с елементите на масива с индекси от 0 до i каква е максималната
    // сума ненадващиваща j, която можем да постигнем
    // 0 .... i.  <= j

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    m = sum / 2;

    // първи вариант с двумерен масив:
    // for(int s = 0; s <= m; s++){
    //     if(s < arr[0]) best[0][s]=0;
    //     else best[0][s] = arr[0];
    // }

    // for( int i = 1; i < n; i++) {
    //     for( int s = 0; s <= m; s++){
    //         if (arr[i]>s) best[i][s] = best[i-1][s];
    //         best[i][s] = max(best[i-1][s], best[i-1][s-arr[i]] + arr[i]);
    //     }
    // }

    // втори вариант с едномерен масив:
    for (int s = 0; s <= m; s++)
        best[s] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int s = m; s >= arr[i]; s--)
        {
            best[s] = max(best[s], best[s - arr[i]] + arr[i]);
        }
    }

    cout << (sum - 2 * best[m]) << endl;

    return 0;
}

/*
4
4 4 8 5
*/
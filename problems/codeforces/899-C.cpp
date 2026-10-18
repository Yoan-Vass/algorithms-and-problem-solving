#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int best[100005], sum, n, arr[100005], m, cr = 0, removed, index, counter = 0;

// https://codeforces.com/problemset/problem/899/C
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    sum = n * (n + 1) / 2;
    m = sum / 2;

    for (int i = 1; i <= n; i++)
    {
        cr += i;
        if (cr >= m)
        {
            removed = cr - m; // идеята е, че  0 <= removed <= i-1
            index = i;
            break;
        }
    }

    cout << sum - 2 * (cr - removed) << "\n";

    counter = removed == 0 ? index : index - 1; // if (removed == 0) counter=index; else counter=index-1;
    cout << counter << " ";

    for (int i = 1; i <= index; i++)
    {
        if (i != removed)
            cout << i << " ";
    }
    return 0;
}
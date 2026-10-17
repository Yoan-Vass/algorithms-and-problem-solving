// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long a[1000000], sum = 0, cr = 0, n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i + n];
    }

    sort(a, a + n + m);
    for (int i = 0; i < n + m; i++)
    {
        // cout << "a[" << i << "] = " << a[i] << " " << cr << "\n";
        if (a[i] > cr + 1)
        {
            cout << sum - cr - 1 << "\n";
            return 0;
        }
        cr += a[i];
    }

    cout << 0 << "\n";
}
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#define MOD 1001027
using namespace std;

int a[2001][1001], n, k, d, t, sz;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k >> s;
        sz = s.size();
        for (int d = 1; d < sz; d++)
        {
            for (int i = 0; i < sz - d; i++)
            {
                if (s[i] == s[i + d])
                    if (d == 1)
                        a[i][d] = 0;
                    else
                        a[i][d] = a[i + 1][d - 2];
                else
                    a[i][d] = min(a[i + 1][d - 1], a[i][d - 1]) + 1;
            }
        }
        cout << (a[0][sz - 1] <= k);
    }
}
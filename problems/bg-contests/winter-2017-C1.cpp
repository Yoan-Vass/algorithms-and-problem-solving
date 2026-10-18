// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long n, element, cr = 0, best = -1000000000, l = 1, r, min_preffix, cr_left = 1;

// https://arena.olimpiici.com/api/public/problems/1031/pdf
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> element;
        cr += element;

        // решение 1:
        // best = max(best, max(cr, cr - min_preffix));
        // min_preffix = min(min_preffix, cr);

        // решение 2:
        if (cr >= best)
        {
            best = cr;
            r = i;
            l = cr_left;
        }
        if (cr < 0)
        {
            cr = 0;
            cr_left = i + 1;
        }
    }
    cout << best << " " << l << " " << r << endl;
    return 0;
}

/*
8
-2 0 1 2 -1 1 2 0

4
-1 -2 -3 -4

10
1 2 -4 2 3 -4 2 -1 5 -3
*/
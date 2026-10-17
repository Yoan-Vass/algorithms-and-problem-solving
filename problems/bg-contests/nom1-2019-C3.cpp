// #include <bits/stdc++.h>
#include <iostream>

using namespace std;
long long ans[51][51];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> k >> n;
    ans[0][0] = ans[1][0] = ans[1][1] = 1;

    for (int i = 2; i <= k; i++)
    {
        ans[i][0] = 1;
        for (int j = 1; j <= n; j++)
        {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    cout << ans[k][n] << "\n";
}
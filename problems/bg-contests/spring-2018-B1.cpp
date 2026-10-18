// #include <bits/stdc++.h>
#include <iostream>
#define MOD 1001027
using namespace std;

int ans[2001][1001], n, k, pos, d;
bool flag[2001];

// https://arena.olimpiici.com/api/public/problems/892/pdf
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < k; i++)
    {
        cin >> pos;
        flag[pos] = true;
    }

    // ans[i][j] = броя на последователностите от i скоби, за които започват брой отварящи - брой затварящи скоби = j
    ans[0][0] = 1;

    for (int i = 1; i <= d; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j > 0)
                ans[i][j] = ans[i - 1][j - 1];
            if (j < n && !flag[i])
                ans[i][j] = (ans[i][j] + ans[i - 1][j + 1]) % MOD;
        }
    }
    cout << ans[d][0] << "\n";
}
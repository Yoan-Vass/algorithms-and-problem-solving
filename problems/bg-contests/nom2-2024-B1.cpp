// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long a[1000000], sum = 0, cr = 0, n, m;

// https://arena.olimpiici.com/api/public/problems/2082/pdf
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
        if (a[i] > cr + 1)
        {
            cout << sum - cr - 1 << "\n";
            return 0;
        }
        cr += a[i];
    }

    cout << 0 << "\n";
    return 0;
}
/*
идея: нека a_1+...a_n=sum, ако допуснем, че търсената сума max, то sum-max може да се представи като сума на някои от a_i и b_j;
това свежда задачата до намиране на най-малкото число, което не може да се представи като сума на някои от a_i и b_j;
Лема (нду): ако c_1, ... c_n+m са числата a_i, b_j в сортиран ред, то най-малкото число, което не може да се представи като сума на някои от тях,
    е cr+1, където cr=c_1+...+c_k, k е най-малкото число, за което c_1+...+c_k<c_k+1-1.
*/
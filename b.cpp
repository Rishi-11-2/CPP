#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define int long long int
#define lld long double
#define INF INT_MAX
void solve();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    int flag = 0;
    char arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (k != 1)
                arr[i][j] = '.';
            else
                arr[i][j] = 'X';
        }
    }
    if (k != 1)
    {
        r--;
        c--;

        if (c >= k)
            c = c % k;
        int x = c;
        int y = r;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                x = x % k;
            }
            for (int j = x; j < n; j += k)
            {
                arr[y][j] = 'X';
            }
            x++;
            y++;
            if (y > n - 1)
                y = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << el;
    }
}
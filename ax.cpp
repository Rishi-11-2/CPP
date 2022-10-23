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
    int n;
    cin >> n;
    int arr[2 * n];
    for (int i = 0; i < 2 * n; i++)
        cin >> arr[i];

    int v1[2];
    int v2[2];
    int x = 0;
    int y = 0;
    int z = 0;
    for (int i = 0; i < 2 * n; i++)
    {

        if (z < n - 1)
        {
            if (arr[i] % 2 == 0)
            {
                if (x == 2)
                {
                    z++;
                    cout << v1[0] << " " << v1[1] << el;
                    x = 0;
                    v1[x] = i + 1;
                    x++;
                }
                else
                {
                    v1[x] = i + 1;
                    x++;
                }
            }

            if (arr[i] % 2 != 0)
            {
                if (y == 2)
                {
                    z++;
                    cout << v2[0] << " " << v2[1] << el;
                    y = 0;
                    v2[y] = i + 1;
                    y++;
                }
                else
                {
                    v2[y] = i + 1;
                    y++;
                }
            }
        }
    }

    if (x == 2 and z < n - 1)
    {
        cout << v1[0] << " " << v1[1] << el;
        z++;
    }
    if (y == 2 and z < n - 1)
    {
        cout << v2[0] << " " << v2[1] << el;
        z++;
    }
}

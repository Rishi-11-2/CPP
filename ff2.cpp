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
    int arr[n];
    ht<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
    }
    int c_d = 0;
    int c_s = 0;
    for (int i = 0; i < n; i++)
        c_s = max(c_s, m[arr[i]]);

    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]] == c_s)
        {
            m[arr[i]] = 0;
            break;
        }
    }
    if (n == 1)
    {
        cout << 0 << el;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]] != 0)
        {
            c_d++;
            m[arr[i]] = 0;
        }
    }
    if (c_d == n || c_s == 1)
    {
        cout << 1 << el;
        return;
    }
    if (c_s > c_d + 1)
    {
        c_d++;
    }
    cout << min(c_d, c_s) << el;
}
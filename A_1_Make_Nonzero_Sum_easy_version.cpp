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
    int sign[n];
    vector<pair<int, int>> v1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    int prev = arr[0];
    int preVi = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            if (prev == arr[i + 1])
            {
                v1.pb({preVi + 1, i + 2});
            }
            else
            {
                v1.pb({preVi + 1, i + 1});
                v1.pb({i + 2, i + 2});
            }
            preVi = i + 1;
            i++;
        }
    }
    cout << v1.size() << el;
    for (auto it : v1)
    {
        cout << it.first << " " << it.second << el;
    }
}
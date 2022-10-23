// https://codeforces.com/problemset/problem/1692/E
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
int query(int low, int mid, int p[])
{
    return p[mid] - (low ? p[low - 1] : 0);
}
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
    int n, s;
    cin >> n >> s;
    int arr[n];
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        p[i] = arr[i];
        if (i)
            p[i] += p[i - 1];
    }
    int low = 0;
    int high = n - 1;
    int pos = -1;
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        low = i;
        high = n - 1;
        pos = -1;
        while (low <= high)
        {
            int mid = low + high >> 1;
            if (query(i, mid, p) <= s)
            {
                low = mid + 1;
                pos = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (pos == -1 || query(i, pos, p) != s)
            continue;
        ans = min(ans, n - (pos + 1 - i));
    }
    cout << ((ans == INF) ? -1 : ans) << el;
}
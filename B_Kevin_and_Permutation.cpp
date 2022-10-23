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
    if (n == 2 || n == 3)
    {
        for (int i = 1; i <= n; i++)
            arr[i - 1] = i;
    }
    else
    {
        int k = n;
        if (n % 2 != 0)
            k--;
        int h = k / 2;
        int g = k;
        for (int i = 0; i < k; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] = h;
                h--;
            }
            else
            {
                arr[i] = g;
                g--;
            }
        }
        if (n % 2 != 0)
        {
            int l = arr[n - 2];
            arr[n - 2] = n;
            arr[n - 1] = l;
        }
    }
    for (auto it : arr)
        cout << it << " ";
    cout << el;
}
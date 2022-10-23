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
    int minM = INF;
    int maxM = 0;
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << max(maxM - arr[0], arr[n - 1] - minM) << el
    int maxD = arr[n - 1] - arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        maxD = max(maxD, arr[i] - arr[i + 1]);
        maxD = max(maxD, arr[i] - arr[0]);
        maxD = max(maxD, arr[n - 1] - arr[i]);
    }
    cout << maxD << el;
}
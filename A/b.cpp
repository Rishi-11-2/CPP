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
    int a[n];
    int b[n];
    ht<int, int> m1;
    ht<int, int> m2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m1[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        m2[b[i]] = i;
    }
    int minM = INF;
    if (a[0] < b[0])
        minM = 0;
    int j = 0;
    for (int i = 1; i <= 2 * n; i += 2)
    {
        while (i > b[j])
            j++;
        int ans = m1[i] + m2[b[j]];
        minM = min(minM, ans);
    }
    cout << minM << el;
}
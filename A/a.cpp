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
    int l, r, a;
    cin >> l >> r >> a;
    int a1 = r % a;
    int a2 = l % a;
    if (a1 < a2 || (abs(r - l)) > abs(a2 - a1))
    {
        int k = (r - (a - 1)) / a;
        cout << k + (a - 1) << el;
        return;
    }
    else
    {
        cout << ((r / a) + (r % a)) << el;
        return;
    }
}
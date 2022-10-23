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
    string s;
    cin >> s;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if ((i != n - 1) and (s[i] == '0') and (s[i + 1] == '0'))
            c += 2;
        if ((i < n - 2) and (s[i] == '0') and (s[i + 1] == '1') and (s[i + 2] == '0'))
            c++;
    }
    cout << c << el;
}
// 1010110000100000101
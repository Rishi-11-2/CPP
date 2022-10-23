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
int lowbit(int n)
{
    int h = 0;
    for (int i = 0; i < 31; i++)
    {
        if (n & (1 << i))
        {
            h = 1 << i;
            break;
        }
    }
    return h;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int s, n;
    cin >> s >> n;
    int k = 0;
    vector<int> v;
    while (k < s)
    {
        k += (lowbit(n));
        if (k <= s)
        {
            v.pb(n);
            n--;
        }
        int g = n;
        if (k > s)
            n--;
        while (k > s)
        {
            k -= lowbit(g);
            g++;
        }

        if (n < 0)
        {
            cout << -1 << el;
            return;
        }
    }
    cout << size(v) << el;
    for (auto it : v)
        cout << it << " ";
    cout << el;
}
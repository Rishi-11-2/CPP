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
    string s;
    cin >> s;
    string t;
    cin >> t;

    int nt = t.length();
    int ns = s.length();
    char prev = t[0];
    int i = ns - 1;
    int low = nt - 1;
    int c = ns - 1;
    while (low >= 0 and i >= 0)
    {
        if (s[i] == t[low] and (c == ns - 1 || c + 2 > i))
        {
            if (((c + 1) - i) % 2 == 0 || c == ns - 1)
            {
                low--;
                c = i;
            }
        }

        i--;
    }
    if (low == 0)
        cout << "YES" << el;
    else
        cout << "NO" << el;
}
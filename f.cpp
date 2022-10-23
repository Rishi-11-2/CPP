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
    int d[n];
    string s;
    cin >> s;
    if (s[0] == 'B')
    {
        cout << -1 << el;
        return;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    int maxM = 0;
    int index = 0;
    int c_r = 0;
    int m1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i] > maxM)
        {
            index = i;
            m1 = c_r;
            maxM = d[i];
        }

        if (s[i] == 'R')
            c_r++;

        if (i > index)
        {
            if (s[i] == 'B')
            {
                index += (maxM + 1) - (c_r - m1);
                if (index <= 0)
                {
                    cout << -1 << el;
                    return;
                }
                c_r = 0;
                count++;
                if (index >= n)
                    break;
            }
        }
        if (i < index)
        {
            if (s[i] == 'B')
            {
                if (d[i] > maxM)
                {

                    maxM = d[i];
                    c_r++;
                }
            }
        }
    }
    cout << count << el;
}
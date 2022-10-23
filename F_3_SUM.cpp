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
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] % 10;
        if (m[arr[i]] < 4)
            m[arr[i]] += 1;
    }
    int low = 0;
    int high = n - 1;
    for (int i = 0; i <= 9; i++)
    {
        m[i]--;
        if (m[i] >= 0)
        {
            for (int j = 0; j <= 9; j++)
            {
                m[j]--;
                if (m[j] >= 0)
                {
                    for (int k = 0; k <= 9; k++)
                    {
                        if (m[k] > 0 and (i + j + k) % 10 == 3)
                        {
                            cout << "YES" << el;
                            return;
                        }
                    }
                }
                m[j]++;
            }
        }
        m[i]++;
    }

    cout << "NO" << el;
}
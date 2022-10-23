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
    int k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int h = 0;
    int count = 0;
    bool k1[n];
    for (int i = n - 1; i >= 1; i--)
    {
        if (!(arr[i - 1] >= 2 * arr[i]))
        {
            k1[i] = true;
        }
        else
        {
            k1[i] = false;
        }
    }
    k1[0] = true;
    // for (auto it : k1)
    //     cout << it << " ";
    // cout << el;
    deque<int> dq;
    dq.push_front(0);
    for (int i = 1; i < n; i++)
    {
        if (k1[i] == true)
        {
            dq.push_front(i);
        }
        else
        {
            while (!(dq.empty()))
            {
                dq.pop_back();
            }
            dq.push_front(i);
        }
        if (dq.size() == k + 1)
        {
            count++;
            dq.pop_back();
        }
    }

    cout << count << el;
}
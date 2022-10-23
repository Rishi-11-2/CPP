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
    int n, w;
    cin >> n >> w;
    int arr[n];
    bool b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b[i] = true;
    }
    sort(arr, arr + n);
    int count = 0;
    int low = 0;
    int high = n - 1;
    while (high > -1)
    {
        b[high] = false;
        int s = arr[high];

        auto index = lower_bound(arr, arr + n, w - s) - arr;
        if (s == w)
        {
            count++;
            index = -1;
        }
        if (index == 0 and arr[index] != w - s)
            index = -1;
        if (index == n)
            index = high - 1;
        while ((index > -1) and (s < w))
        {
            if (b[index] == true)
            {
                s += arr[index];
                if (s > w)
                {
                    s -= arr[index];
                }
                if (s == w)
                {
                    b[index] = false;
                    count++;
                    break;
                }
            }
            index--;
            if (index == -1)
                count++;
        }
        while (high > -1 and b[high] != true)
            high--;
    }
    cout << count << el;
}
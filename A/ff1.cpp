
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
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }
    int res = arr[0];
    int maxE = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxE = max(maxE + arr[i], arr[i]);
        res = max(maxE, res);
    }
    if (res > s)
    {
        cout << "YES" << el;
    }
    else
    {
        cout << "NO" << el;
    }
}
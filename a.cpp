
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
    vector<int> v;
    cin >> s;

    int z = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            z += i;
        if (s[i] == 'R')
            z += n - i - 1;
    }
    int low = 0;
    int high = n - 1;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            arr[i] -= i;
            arr[i] += (n - i - 1);
        }
        if (s[i] == 'R')
        {
            arr[i] -= (n - i - 1);
            arr[i] += i;
        }
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            z += arr[i];
        cout << z << " ";
    }
    cout << el;
}
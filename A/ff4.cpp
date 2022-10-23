
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
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ht<int, int> m;
    sort(arr, arr + n);
    int maxM = 0;
    int c = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (m[arr[i]] == 0 || (i != n - 1 and arr[i + 1] == arr[i]))
        {
            m[arr[i]] = c;
        }
        c++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (m[arr[i]] >= arr[i])
        {
            maxM = arr[i];
            break;
        }
    }
    cout << maxM << el;
}
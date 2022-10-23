
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
    int k;
    cin >> k;
    int left[n];
    int right[n];
    left[0] = 0;
    left[n - 1] = 0;
    right[0] = 0;
    right[n - 1] = 0;
    int s = arr[0];
    int count = 1;
    int low1 = 0;
    for (int i = 1; i < n; i++)
    {
        while (s > k)
        {
            s = s - arr[low1];
            low1++;
            count--;
        }
        s += arr[i];
        left[i] = count;
        count++;
    }
    int high1 = n - 1;
    s = arr[n - 1];
    count = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (s > k)
        {
            s = s - arr[high1];
            high1--;
            count--;
        }
        s += arr[i];
        right[i] = count;
        count++;
    }
    int maxM = 0;
    for (int i = 0; i < n; i++)
    {
        maxM = max(maxM, left[i] + right[i]);
    }
    cout << maxM << el;
}
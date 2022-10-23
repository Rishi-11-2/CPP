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
    int minEE = INT_MAX;
    int maxEE = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        minEE = min(minEE, arr[i] * arr[i]);
        maxEE = max(maxEE, arr[i] * arr[i]);
    }
    int max_ending_here = arr[0];

    int min_ending_here = arr[0];

    int max_so_far = arr[0];

    for (int i = 1; i < n; i++)
    {
        int temp = max({arr[i], arr[i] * max_ending_here,
                        arr[i] * min_ending_here});
        min_ending_here = min({arr[i], arr[i] * max_ending_here,
                               arr[i] * min_ending_here});
        max_ending_here = temp;
        max_so_far = max(max_so_far, max_ending_here);
    }
    int minP = INT_MAX;
    int max_neg = INT_MIN, min_pos = INT_MAX, count_neg = 0,
        count_zero = 0, prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count_zero++;
            continue;
        }
        if (arr[i] < 0)
        {
            count_neg++;
            max_neg = max(max_neg, arr[i]);
        }
        // Track minimum positive number of array
        if (arr[i] > 0)
            min_pos = min(min_pos, arr[i]);
        prod = prod * arr[i];
    }
    // If there are all zeros or no negative number present
    if (count_zero == n || (count_neg == 0 && count_zero > 0))
        minP = 0;
    // If there are all positive
    if (count_neg == 0)
        minP = min_pos;

    // If there are even number of negative numbers and
    // count_neg not 0
    if (!(count_neg & 1) && count_neg != 0)
        prod = prod / max_neg;
    minP = prod;
    cout << min(minP, minEE) << " " << max(max_so_far, maxEE) << el;
}
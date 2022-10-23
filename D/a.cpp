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
void solve(int v);
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    int v = 1;
    cin >> t;
    while (t--)
    {
        solve(v);
        v++;
    }
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve(int v = 0)
{
    int r_s, r_h;
    cin >> r_s >> r_h;
    lld r = (r_s + r_h);
    int n;
    cin >> n;
    int arr1[n][2];
    lld a_d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i][0] >> arr1[i][1];
        int x = arr1[i][0];
        int y = arr1[i][1];
        lld z = 0.0;
        x = abs(x);
        y = abs(y);
        z = ((x * x) + (y * y));
        z = sqrt(z);
        a_d[i] = z;
    }
    int m;
    cin >> m;

    int arr2[m][2];
    lld b_d[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i][0] >> arr2[i][1];
        int x = arr2[i][0];
        int y = arr2[i][1];
        lld z = 0.0;
        x = abs(x);
        y = abs(y);
        z = ((x * x) + (y * y));
        z = sqrt(z);
        b_d[i] = z;
    }
    // cout << r << el;
    // for (int i = 0; i < n; i++)
    //     cout << a_d[i] << " ";
    // cout << el;
    // for (int i = 0; i < m; i++)
    //     cout << b_d[i] << " ";
    // cout << el;
    int count1 = 0;
    int count2 = 0;
    int i = 0;
    int j = 0;
    sort(a_d, a_d + n);
    sort(b_d, b_d + m);
    while (i < n and j < m)
    {
        if (a_d[i] < b_d[j])
        {
            if (a_d[i] <= r)
                count1++;
            i++;
            j++;
        }
        else
        {
            if (b_d[j] <= r)
                count2++;
            i++;
            j++;
        }
    }
    if (i != 0 and j != 0)
    {
        i++;
        j++;
    }
    while (i < n)
    {
        if (a_d[i] <= r)
            count1++;
        i++;
    }
    while (j < m)
    {
        if (b_d[j] <= r)
            count2++;
        j++;
    }

    cout << "Case #" << v << ": " << count1 << " " << count2 << el;
}
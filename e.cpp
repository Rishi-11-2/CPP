
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
    unordered_map<int, int> m;
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int z = 0;
    int x1 = 0;
    int k = 0;
    int maxM = 0;
    int l = 0;
    int c_z = 0;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        if (s[i] == '1')
            l++;
        if (s[i] == '0')
            c_z++;
        if (x1 != 0)
        {
            maxM = max(maxM, x1);
            if (x1 != 1)
                m[x1]++;
            k = (2 * x1 + 1);
            z += k;
        }
        if (s[i] == '1')
            x1 = 0;
        if (s[i] == '0')
        {
            x1++;
        }
    }

    maxM = max(maxM, x1);
    if (x1 != 1)
        m[x1]++;
    m[1] = c_z;
    z += k;
    int count = 0;
    int s1 = 2 * maxM + 1;
    if (x % s1 == 0)
    {
        int p = (x / s1);
        count = maxM * (p);
    }
    else
    {
        while (x > 2 and maxM > 0)
        {

            if (m[maxM] != 0)
            {
                s1 = (2 * maxM) + 1;
                if (s1 <= x)
                {
                    int z = (x / s1);
                    if (z > m[maxM])
                        z = m[maxM];
                    count += maxM * (z);
                    m[1] -= (maxM * z);
                    x = x - (s1 * z);
                }
            }
            maxM--;
        }
    }

    cout << l + count << el;
}
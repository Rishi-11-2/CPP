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
void solve(int x);
bool myComparator(pair<string, int> s1, pair<string, int> s2)
{
    if (s1.first == s2.first)
        return s1.second < s2.second;
    return s1.first <= s2.first;
}
bool myComparator1(pair<int, int> s1, pair<int, int> s2)
{
    if (s1.first == s2.first)
        return s1.second < s2.second;
    return s1.first <= s2.first;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int x = 1;
    while (t--)
    {
        solve(x);
        x++;
    }
}
void solve(int x)
{
    int n;
    cin >> n;
    int u[n];
    vector<pair<string, int>> s(n);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].first >> arr[i].first >> u[i];
        s[i].second = u[i];
        arr[i].second = u[i];
    }
    sort(s.begin(), s.end(), myComparator);
    sort(arr.begin(), arr.end(), myComparator1);

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].second == arr[i].second)
        {

            c++;
        }
    }
    cout << "Case #" << x << ": " << c << el;
}
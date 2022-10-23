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
bool visited[2000000 + 1];
#define int long long int
#define lld long double
#define INF INT_MAX
void solve();
int BFS(vector<set<int>> sv, int s)
{
    queue<int> q;
    int h = 0;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        h++;
        int u = q.front();
        q.pop();
        for (auto it : sv[u])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
    return h;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> sv;
    sv.resize(n + 1);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        sv[i] = s;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        sv[u].erase(v);
        sv[v].erase(u);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
        visited[i] = false;
    vector<int> hg;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            count++;
            int c = BFS(sv, i);
            hg.push_back(c);
        }
    }
    cout << count << el;
    sort(all(hg));
    for (auto it : hg)
    {
        cout << it << " ";
    }
    cout << el;
}
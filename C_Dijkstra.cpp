#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vi, greater<ll>>

#define sortv(v) sort(v.begin(), v.end())
#define sortvr(v) sort(v.begin(), v.end(), greater<>())

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define nl cout << endl

#define def1(n) \
    ll n;       \
    cin >> n
#define def2(a, b) \
    ll a, b;       \
    cin >> a >> b
#define def3(a, b, c) \
    ll a, b, c;       \
    cin >> a >> b >> c
#define def4(a, b, c, d) \
    ll a, b, c, d;       \
    cin >> a >> b >> c >> d
#define def5(a, b, c, d, e) \
    ll a, b, c, d, e;       \
    cin >> a >> b >> c >> d >> e

#define out(n) cout << n
#define outs(n) cout << n << " "
#define outl(n) cout << n << endl
#define out2(a, b) cout << a << " " << b << endl
#define out3(a, b, c) cout << a << " " << b << " " << c << endl
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define out5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << endl

#define inv(v, n)              \
    vi v(n);                   \
    for (ll i = 0; i < n; i++) \
        cin >> v[i];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll power(ll x, ll y)
{
    ll res = 1;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}
bool dij(vector<vector<pair<int, int>>> &g, int n, int src, vector<ll> &par)
{
    vector<ll> dist(n + 1, 1e18);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

    dist[src] = 0;
    q.push({0, src});

    while (!q.empty())
    {
        auto it = q.top();
        q.pop();

        ll d = it.first;
        ll node = it.second;

        if (dist[node] < d)
            continue;

        for (auto &edge : g[node])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[node] + w < dist[v])
            {
                dist[v] = dist[node] + w;
                par[v] = node;
                q.push({dist[v], v});
            }
        }
    }

    if (dist[n] == 1e18)
        return false;

    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    vector<ll> par(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    par[1] = 0;

    bool ok = dij(g, n, 1, par);

    if (!ok)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> path;

    int cur = n;

    while (cur != 0)
    {
        path.push_back(cur);
        cur = par[cur];
    }

    reverse(path.begin(), path.end());

    for (auto &x : path)
        cout << x << " ";

    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
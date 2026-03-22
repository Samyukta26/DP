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
void dfs(vector<string> &v, int i, int j, vector<vector<int>> &vis, ll &ct, ll &n, ll &m)
{
    vis[i][j] = 1;
    ct++;
    if (i - 1 >= 0 && v[i - 1][j] != '~' && vis[i - 1][j] == 0)
    {
        dfs(v, i - 1, j, vis, ct, n, m);
    }
    if (i + 1 < n && v[i + 1][j] != '~' && vis[i + 1][j] == 0)
    {
        dfs(v, i + 1, j, vis, ct, n, m);
    }
    if (j - 1 >= 0 && v[i][j - 1] != '~' && vis[i][j - 1] == 0)
    {
        dfs(v, i, j - 1, vis, ct, n, m);
    }
    if (j + 1 < m && v[i][j + 1] != '~' && vis[i][j + 1] == 0)
    {
        dfs(v, i, j + 1, vis, ct, n, m);
    }
}
void solve()
{
    def2(n, m);
    ll ct = 0;
    ll ans = 0;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '#' && vis[i][j] == 0)
            {
                ct = 0;
                dfs(v, i, j, vis, ct, n, m);
                ans += ct * ct;
            }
        }
    }
    ll x = ans;
    ll y = m * n;
    ll z = gcd(x, y);
    x = x / z;
    y = y / z;
    if (y == 1)
    {
        outl(x);
        return;
    }
    cout << x << " " << "/" << " " << y << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
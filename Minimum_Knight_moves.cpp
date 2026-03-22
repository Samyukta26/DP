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
ll bfs(ll a, ll c, ll b, ll d, vector<vector<int>> &p)
{
    int moves[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, -2}, {-1, 2}, {-2, 1}, {-2, -1}};
    p[a][c] = true;
    queue<vector<int>> q;
    q.push({a, c, 0});
    while (!q.empty())
    {
        vector<int> x = q.front();
        q.pop();
        for (auto &mv : moves)
        {
            ll l1 = x[0] + mv[0];
            ll l2 = x[1] + mv[1];
            if (l1 >= 0 && l1 < 8 && l2 >= 0 && l2 < 8 && p[l1][l2] == 0)
            {
                if (l1 == b && l2 == d)
                    return x[2] + 1;
                q.push({l1, l2, x[2] + 1});
                p[l1][l2] = 1;
            }
        }
    }
    return 0;
}
void solve()
{
    string s, s1;
    cin >> s >> s1;
    ll a, b;
    a = s[0] - 'a';
    b = s1[0] - 'a';
    ll c = s[1] - '1';
    ll d = s1[1] - '1';
    vector<vector<int>> p(8, vector<int>(8, 0));
    outl(bfs(a, c, b, d, p));
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
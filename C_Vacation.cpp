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
ll a(int i, int last, vector<vector<ll>> &v, vector<vector<ll>> &dp)
{

    if (i == v.size())
        return 0;

    if (dp[i][last] != -1)
        return dp[i][last];

    ll ans = 0;

    if (last == 0)
    {
        ans = max(
            v[i][1] + a(i + 1, 1, v, dp),
            v[i][2] + a(i + 1, 2, v, dp));
    }
    else if (last == 1)
    {
        ans = max(
            v[i][0] + a(i + 1, 0, v, dp),
            v[i][2] + a(i + 1, 2, v, dp));
    }
    else if (last == 2)
    {
        ans = max(
            v[i][0] + a(i + 1, 0, v, dp),
            v[i][1] + a(i + 1, 1, v, dp));
    }
    else
    {
        ans = max({v[i][0] + a(i + 1, 0, v, dp),
                   v[i][1] + a(i + 1, 1, v, dp),
                   v[i][2] + a(i + 1, 2, v, dp)});
    }

    return dp[i][last] = ans;
}
void solve()
{
    int n;
    cin >> n;

    vector<vector<ll>> v(n, vector<ll>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(4, -1));

    cout << a(0, 3, v, dp);
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
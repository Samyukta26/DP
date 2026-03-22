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

void solve()
{
    def1(n);
    inv(v, n);

    vector<ll> v1, v2;
    for (auto &x : v)
    {
        if (x % 2 == 0)
            v1.push_back(x);
        else
            v2.push_back(x);
    }

    if (v1.size() >= 2)
    {
        cout << v1[0] << " " << v1[1] << "\n";
        return;
    }

    bool found = false;
    ll x = -1, y = -1;

    for (int i = 0; i < v2.size() && !found; i++)
    {
        for (int j = i + 1; j < (int)v2.size() && !found; j++)
        {
            ll rem1 = v2[j] % v2[i];
            ll rem2 = v2[i] % v2[j];
            if ((rem1 % 2 == 0) || (rem2 % 2 == 0))
            {
                x = v2[i];
                y = v2[j];
                found = true;
            }
        }
    }

    if (found)
    {
        cout << x << " " << y << "\n";
        return;
    }

    if (!found && v1.size() == 1)
    {
        ll y_even = v1[0];
        for (auto x_odd : v2)
        {
            if (x_odd < y_even)
            {
                ll rem = y_even % x_odd;
                if (rem % 2 == 0)
                {
                    cout << x_odd << " " << y_even << "\n";
                    return;
                }
            }
        }
    }

    outl(-1);
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
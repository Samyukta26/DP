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

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    if (n == 1)
    {
        if (a[0] < b[0] && b[0] < c[0])
            outl(1);
        else
            outl(0);
        return;
    }

    vector<bitset<5000>> AB(n);
    for (int s = 0; s < n; s++)
    {
        for (int p = 0; p < n; p++)
        {
            if (a[p] < b[(p + s) % n])
                AB[s].set(p);
        }
    }

    vector<bitset<5000>> BC(n);
    for (int u = 0; u < n; u++)
    {
        for (int t2 = 0; t2 < n; t2++)
        {
            if (b[u] < c[(u + t2) % n])
                BC[u].set(t2);
        }
    }

    ll ct = 0;

    for (int s = 0; s < n; s++)
    {
        if ((int)AB[s].count() != n)
            continue;

        bitset<5000> ok_t;
        ok_t.set();

        for (int p = 0; p < n; p++)
        {
            int u = (p + s) % n;
            ok_t &= BC[u];
        }

        ct += ok_t.count();
    }

    outl(ct * n);
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

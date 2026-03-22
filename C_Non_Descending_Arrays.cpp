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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    vector<vector<long long>> dp(n, vector<long long>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i < n; i++)
    {

        if (a[i - 1] <= a[i] && b[i - 1] <= b[i])
            dp[i][0] = (dp[i][0] + dp[i - 1][0]) % 998244353;
        // swap at i, no swap at i-1
        if (a[i - 1] <= b[i] && b[i - 1] <= a[i])
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % 998244353;
        // no swap at i, swap at i-1
        if (b[i - 1] <= a[i] && a[i - 1] <= b[i])
            dp[i][0] = (dp[i][0] + dp[i - 1][1]) % 998244353;
        // swap at i, swap at i-1
        if (b[i - 1] <= b[i] && a[i - 1] <= a[i])
            dp[i][1] = (dp[i][1] + dp[i - 1][1]) % 998244353;
    }

    cout << (dp[n - 1][0] + dp[n - 1][1]) % 998244353 << "\n";
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
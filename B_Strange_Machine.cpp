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
long long computeTime(long long x, const string &s)
{
    int n = s.size();
    bool allA = true, allB = true;
    for (char c : s)
    {
        if (c == 'A')
            allB = false;
        if (c == 'B')
            allA = false;
    }

    // Case 1: all A
    if (allA)
        return x;

    // Case 2: all B
    if (allB)
    {
        return (x == 0 ? 0 : (long long)(log2(x)) + 1);
    }

    // Case 3: mixed
    long long ct = 0;
    int pos = 0;
    while (x > 0)
    {
        if (s[pos] == 'A')
            x -= 1;
        else
            x /= 2;
        ct++;
        pos = (pos + 1) % n;
        if (ct > 2000)
            break; // safety (never actually reached)
    }
    return ct;
}

void solve()
{
    def2(n, q);
    string s;
    cin >> s;
    vi v(q);
    for (int i = 0; i < q; i++)
        cin >> v[i];
        ll a=count(s.begin(),s.end(),'A');
        
    for (int i = 0; i < q; i++)
    {
        ll x = v[i];
        ll ct = 0;
        if(a==s.size()){ outl(v[i]); return;}
        while (x > 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[j] == 'A')
                    x -= 1;
                else
                    x /= 2;
                ct++;
                if (x <= 0)
                    break;
            }
        }
 
        outl(ct);
    }
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
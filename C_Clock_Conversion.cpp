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
    string s;
    cin >> s;
    if (s[0] == '0' && s[1] != '0')
        cout << s << " " << "AM" << endl;
    else if (s[0] == '1' && s[1] == '0')
        cout << s << " " << "AM" << endl;
    else if (s[0] == '1' && s[1] == '1')
        cout << s << " " << "AM" << endl;
    else if (s[0] == '0' && s[1] == '0')
    {
        s[0] = '1';
        s[1] = '2';
        cout << s << " " << "AM" << endl;
    }
    else if (s[0] == '1' && s[1] == '3')
    {
        s[0] = '0';
        s[1] = '1';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '1' && s[1] == '4')
    {
        s[0] = '0';
        s[1] = '2';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '1' && s[1] == '5')
    {
        s[0] = '0';
        s[1] = '3';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '1' && s[1] == '6')
    {
        s[0] = '0';
        s[1] = '4';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '1' && s[1] == '7')
    {
        s[0] = '0';
        s[1] = '5';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '1' && s[1] == '8')
    {
        s[0] = '0';
        s[1] = '6';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '1' && s[1] == '9')
    {
        s[0] = '0';
        s[1] = '7';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '2' && s[1] == '0')
    {
        s[0] = '0';
        s[1] = '8';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '2' && s[1] == '1')
    {
        s[0] = '0';
        s[1] = '9';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '2' && s[1] == '2')
    {
        s[0] = '1';
        s[1] = '0';
        cout << s << " " << "PM" << endl;
    }
    else if (s[0] == '2' && s[1] == '3')
    {
        s[0] = '1';
        s[1] = '1';
        cout << s << " " << "PM" << endl;
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
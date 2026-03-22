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
    ll n;      \
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

#define inv(v, n)             \
    vi v(n);                  \
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

void solve() {
    string r;
    cin >> r;
    int n = r.size();

    // Required assertion
    for (char c : r) {
        assert(c == 's' || c == 'u');
    }

    int total_u = 0;
    for (char c : r) if (c == 'u') total_u++;

    // If there are no 'u', string is already suspicious
    if (total_u == 0) {
        cout << 0 << '\n';
        return;
    }

    int best = 0;   // longest valid u-block between two 's'
    int i = 0;

    while (i < n) {
        if (r[i] == 'u') {
            int j = i;
            while (j < n && r[j] == 'u') j++;

            // check if this u-block is strictly between two 's'
            if (i > 0 && j < n && r[i - 1] == 's' && r[j] == 's') {
                best = max(best, j - i);
            }

            i = j;
        } else {
            i++;
        }
    }

    // Minimum operations = remove all u except the best valid block
    cout << total_u - best << '\n';
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
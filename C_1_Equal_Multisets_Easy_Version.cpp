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
// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> a(n), b(n);
//     for (auto &x : a)
//         cin >> x;
//     for (auto &x : b)
//         cin >> x;

//     // Step 1: build allowed set (last k elements of a)
//     unordered_set<int> allowed;
//     for (int i = n - k; i < n; i++)
//         allowed.insert(a[i]);

//     // Step 2: check edge positions directly
//     for (int i = 0; i < n; i++)
//     {
//         if (b[i] == -1)
//             continue;

//         // edge indices
//         if (i < n - k || i >= k)
//         {
//             if (b[i] != a[i])
//             {
//                 cout << "NO\n";
//                 return;
//             }
//         }
//     }

//     // Step 3: handle middle segment separately
//     unordered_set<int> seen;

//     for (int i = n - k; i < k; i++)
//     {
//         if (b[i] == -1)
//             continue;

//         // must belong to allowed set
//         if (!allowed.count(b[i]))
//         {
//             cout << "NO\n";
//             return;
//         }

//         // must be unique
//         if (seen.count(b[i]))
//         {
//             cout << "NO\n";
//             return;
//         }

//         seen.insert(b[i]);
//     }

//     cout << "YES\n";
// }

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> val(k, -1);

    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1) continue;

        int g = i % k;

        if (val[g] == -1)
            val[g] = b[i];
        else if (val[g] != b[i])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
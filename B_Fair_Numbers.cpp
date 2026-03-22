#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define def1(x) ll x; cin >> x
#define outl(x) cout << x << "\n"

bool fair(ll n)
{
    ll n1 = n;
    while (n > 0)
    {
        ll d = n % 10;
        if (d != 0 && n1 % d != 0)  // ✅ skip zero digits
            return false;
        if (d == 0)                 // ✅ skip division by zero
            ;                       // do nothing, just skip
        n /= 10;
    }
    return true;
}

void solve()
{
    def1(n);
    while (!fair(n)) n++;  // ✅ find next fair number
    outl(n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

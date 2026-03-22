#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vi, greater<ll>>

#define sortv(v) sort(v.begin(), v.end())
#define sortvr(v) sort(v.begin(), v.end(), greater<>())

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << "\n"

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
#define outl(n) cout << n << "\n"
#define out2(a, b) cout << a << " " << b << "\n"
#define out3(a, b, c) cout << a << " " << b << " " << c << "\n"
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << "\n"
#define out5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << "\n"

#define inv(v, n)              \
    vi v(n);                   \
    for (ll i = 0; i < n; i++) \
    cin >> v[i]

using ull = unsigned long long;
const ull INF = (ull)9e18;

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<pair<string, ll>> items(n);
    for (int i = 0; i < n; ++i)
        cin >> items[i].first >> items[i].second;

    ull k;
    cin >> k;

    ll baseCost = 0;
    for (int i = 0; i < n; ++i)
        baseCost += items[i].second * (ll)(i + 1);

    unordered_map<string, ll> totalWeight;
    for (auto &p : items)
        totalWeight[p.first] += p.second;

    map<ll, vector<string>, greater<ll>> groupedByWeight;
    for (auto &kv : totalWeight)
        groupedByWeight[kv.second].push_back(kv.first);

    vector<vector<string>> groups;
    vector<ll> weightList;
    for (auto &kv : groupedByWeight)
    {
        auto &vec = kv.second;
        sort(vec.begin(), vec.end());
        groups.push_back(vec);
        weightList.push_back(kv.first);
    }

    int groupCount = (int)groups.size();

    vector<ll> weights;
    for (auto &kv : totalWeight)
        weights.push_back(kv.second);
    sort(weights.begin(), weights.end(), greater<ll>());

    ll bestCost = 0;
    for (int i = 0; i < (int)weights.size(); ++i)
        bestCost += (ll)(i + 1) * weights[i];

    ll minimumTotal = baseCost + bestCost;

    int maxSize = 0;
    for (auto &g : groups)
        maxSize = max(maxSize, (int)g.size());

    vector<ull> fact(maxSize + 1, 1);
    for (int i = 1; i <= maxSize; ++i)
    {
        __int128 temp = (__int128)fact[i - 1] * i;
        fact[i] = (temp > INF) ? INF : (ull)temp;
    }

    vector<ull> tail(groupCount + 1, 1);
    for (int i = groupCount - 1; i >= 0; --i)
    {
        __int128 temp = (__int128)tail[i + 1] * fact[(int)groups[i].size()];
        tail[i] = (temp > INF) ? INF : (ull)temp;
    }

    vector<string> result;
    for (int gi = 0; gi < groupCount; ++gi)
    {
        ull block = tail[gi + 1];
        ull index = (k - 1) / block;
        k = (k - 1) % block + 1;

        vector<string> pool = groups[gi];
        int m = (int)pool.size();
        vector<int> used(m, 0);
        ull remaining = index;

        for (int p = 0; p < m; ++p)
        {
            ull f = fact[m - 1 - p];
            ull choose = (remaining >= f) ? remaining / f : 0;
            if (choose >= (ull)(m - p))
                choose = m - p - 1;
            remaining = (remaining >= f) ? remaining % f : remaining;

            for (int j = 0; j < m; ++j)
            {
                if (used[j])
                    continue;
                if (choose == 0)
                {
                    result.push_back(pool[j]);
                    used[j] = 1;
                    break;
                }
                --choose;
            }
        }
    }

    outl(minimumTotal);
    for (int i = 0; i < (int)result.size(); ++i)
    {
        if (i)
            cout << ' ';
        cout << result[i];
    }
    nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;  // Uncomment if multiple test cases are given
    while (t--)
        solve();

    return 0;
}

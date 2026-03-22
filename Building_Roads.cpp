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
void bfs(vector<vector<int>>& g, vector<bool>& p, int start) {
    queue<int> q;
    q.push(start);
    p[start] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int child : g[node]) {
            if(!p[child]) {
                p[child] = true;
                q.push(child);
            }
        }
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);

    for(int i=0; i<m; i++){
        int x,y; 
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<bool> p(n+1,false);
    vector<int> v;

    for(int i=1; i<=n; i++){
        if(!p[i]){
            v.push_back(i);
            bfs(g,p,i);
        }
    }

    outl(v.size()-1);

    for(int i=1;i<v.size();i++){
        cout << v[i-1] << " " << v[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
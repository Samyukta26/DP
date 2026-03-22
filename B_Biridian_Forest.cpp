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
ll ct = 0;

void bfs(vector<vector<char>> &grid, vector<vector<bool>> &p, int x, int y)
{
    int n = grid.size(), m = grid[0].size();
    int moves[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    queue<vector<int>> q;
    q.push({x, y, 0});
    p[x][y] = true;
    int s = INT_MAX;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (auto &mv : moves)
        {
            int l1 = cur[0] + mv[0];
            int l2 = cur[1] + mv[1];

            if (l1 >= 0 && l1 < n && l2 >= 0 && l2 < m &&
                grid[l1][l2] != 'T' && !p[l1][l2] && cur[2]+1 <= s)

            {

                p[l1][l2] = true;
                if (grid[l1][l2] == 'S')
                {
                    s = cur[2] + 1;
                    
                }

                else
                {
                    ct += grid[l1][l2] - '0';

                    q.push({l1, l2, cur[2] + 1});
                }
            }
        }
    }
}

void solve()
{
    def2(n, m);

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<vector<bool>> p(n, vector<bool>(m, false));

    int x = -1, y = -1;
    bool found = false;
    for (int i = 0; i < n && !found; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'E')
            {
                x = i;
                y = j;
                found = true;
                break;
            }
        }
    }

    bfs(grid, p, x, y);
    outl(ct);
}

//  ll ct = 0;
// void bfs(vector<vector<char>> &grid,vector<vector<bool>> &p,int x,int y)
// {
//     ll n=grid.size(); ll m=grid[0].size();
//     int moves[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//     queue<vector<int>> q;
//     q.push({x, y});

//     p[l1][l2] = true;
//     while (!q.empty())
//     {
//         auto cur = q.front();
//         q.pop();
//         for (auto &mv : moves)
//         {
//             ll l1 = cur[0] + mv[0];
//             ll l2 = cur[1] + mv[1];
//             if (l1 >= 0 && l1 < n && l2 >= 0 && l2 < m && grid[l1][l2] != 'T' && p[l1][l2] == false)
//             {
//                 if (grid[l1][l2] == 'S')
//                     return;
//                 if (grid[l1][l2] != '0')
//                     ct += grid[l1][l2] - '0';
//                 q.push({l1, l2});
//                 p[l1][l2]=true;
//             }
//         }
//     }
// }
// void solve()
// {
//     def2(n, m);
//     vector<vector<char>> grid(n, vector<int>(m));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }
//     vector<vector<bool>> p(n, vector<bool>(m, false));
//     ll x,y;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if(grid[i][j]=='E'){
//                 x=i; y=j;
//             }
//         }
//     }
//     bfs(grid,p,x,y);
//     outl(ct);
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
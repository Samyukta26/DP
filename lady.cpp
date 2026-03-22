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
bool bfs(vector<string>&v,vector<vector<char>> &br,int a,int b){
    int moves[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; char dir[4] = {'D','U','R','L'};
    v[a][b] = '#';
    queue<vector<int>>q;
    q.push({a,b});
    while(!q.empty()){
        auto cur=q.front(); q.pop();
       for(int k = 0; k < 4; k++){
        ll x = moves[k][0] + cur[0];
ll y = moves[k][1] + cur[1];

if(x>=0 && x<n && y>=0 && y<m && v[x][y]!='#'){

    if(v[x][y] == 'B'){
        br[x][y] = dir[k];
        return true;
    }

    if(v[x][y] == '.'){
        br[x][y] = dir[k];
        v[x][y] = '#';
        q.push({x,y});
    }
}
       }
    }
    return false;
}
void solve()
{
    def2(n,m); ll ax,ay,bx,by=0;
    vector<string>v(n); for(int i=0; i<n; i++) cin>>v[i];
    vector<vector<char>> br(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]=='A'){ ax=i; ay=j;}
            if(v[i][j]=='B'){ bx=i; by=j;}
        }
    }

    bool found=bfs(v,br,ax,ay);
    if(!found){
    cout<<"NO";
    return;
}
cout<<"YES\n";
string path="";
int x = bx;
int y = by;

while(!(x == ax && y == ay)){

    char c = br[x][y];
    path += c;

    if(c == 'L') y++;
    else if(c == 'R') y--;
    else if(c == 'U') x++;
    else if(c == 'D') x--;
}
reverse(path.begin(), path.end());

cout<<path.size()<<"\n";
cout<<path;
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
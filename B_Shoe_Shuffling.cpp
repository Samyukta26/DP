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

void solve(){
	int n;
	cin>>n;
	vi shoe_sz(n);
	for(int i=0; i<n; i++) //non-decreasing order; asc; sorted
		cin>>shoe_sz[i]; 
 
	//create a perm. p[i] = i
	vi shuffling(n);
	for(int i=0; i<n; i++)
		shuffling[i] = i+1;
 
	//'left' rotate same shoe size groups by 1
	//rotate a group of 'k' elements; it takes only O(k) time 
	//Total TC: O(N)
 
	int i=0;
	while(i<n){
		int cur_sz = shoe_sz[i];//shoe size for current group
 
		//find bounds: start, end; cur_sz is in [start, end)
		//start:first occurrence of cur_sz
		int start = i;
		//end: one past the last occurence of cur_sz
		int end = i;
		while(end < n && shoe_sz[end] == cur_sz)end++;
 
		//if you have a unique shoe size: 6 7 7 
		if(start == end - 1){
			//we have a unique shoe size
			outl(-1);
			return;
		}
 
		//rotate this group by left
		//cyclically rotate by 1 in left direction
		rotate(shuffling.begin()+start, shuffling.begin()+start+1, shuffling.begin()+end);
 
		//move to next group
		i=end;
	}	
 
 
	//shuffling has a valid shuffing
	for(auto s:shuffling)cout<<s<<" ";
 
	cout<<endl;
 
}	
 
/*Shoe Shuffling
 f m     e 
 6 6 6 6 7 7 
 
	
 f	 m     e
 1 2 3 4 5 end 
	cyclically rotated left by 2
 rotate(f, m, e)
 3 4 5 1 2
 
*/
 

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
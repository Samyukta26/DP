#include <bits/stdc++.h>
using namespace std;

#define I long long
#define ui unsigned long long
#define S string
#define pi pair<long long, long long>
#define ps pair<string, string>
#define psi pair<string, long long>
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define vs vector<string>
#define vpi vector<pair<long long, long long>>
#define si set<long long>
#define mi map<long long, long long>
#define usi unordered_set<long long>
#define umi unordered_map<long long, long long>
#define uss unordered_set<string>
#define ums unordered_map<string, long long>
#define maxheap priority_queue<long long>
#define minheap priority_queue<long long, vector<long long>, greater<long long>>
#define INF 1000000000000000000

#define sortv(v) sort(v.begin(), v.end())
#define sortvr(v) sort(v.begin(), v.end(), greater<>())
#define maxv(v) max_element(v.begin(), v.end())
#define minv(v) min_element(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define lobo(v, x) lower_bound(v.begin(), v.end(), x)
#define upbo(v, x) upper_bound(v.begin(), v.end(), x)

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define say cout << "-1" << endl
#define qq cout << "q" << " "
#define yess                   \
    {                          \
        cout << "YES" << endl; \
        return;                \
    }
#define noo                   \
    {                         \
        cout << "NO" << endl; \
        return;               \
    }
#define sayy                  \
    {                         \
        cout << "-1" << endl; \
        return;               \
    }
#define nl cout << endl

#define for0(a, c) for (long long a = 0; (a) < (c); (a)++)
#define for1(a, b, c) for (long long a = (b); (a) <= (c); (a)++)
#define for2(a, c) for (long long a = (c); (a) >= (0); (a)--)
#define for3(a, b, c) for (long long a = (b); (a) >= (c); (a)--)

#define debug(x) cerr << #x << " " << x << endl
#define vebug(x)       \
    cerr << #x << " "; \
    vebug_print(x);    \
    cerr << " "
void vebug_print(vi v)
{
    cout << "[ ";
    for0(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "]";
}

#define def(n)   \
    long long n; \
    cin >> n
#define def2(a, b)  \
    long long a, b; \
    cin >> a >> b
#define def3(a, b, c)  \
    long long a, b, c; \
    cin >> a >> b >> c
#define def4(a, b, c, d)  \
    long long a, b, c, d; \
    cin >> a >> b >> c >> d
#define def5(a, b, c, d, e)  \
    long long a, b, c, d, e; \
    cin >> a >> b >> c >> d >> e

#define sin(n) \
    string n;  \
    cin >> n
#define sin2(a, b) \
    string a, b;   \
    cin >> a >> b
#define sin3(a, b, c) \
    string a, b, c;   \
    cin >> a >> b >> c

#define in(n) cin >> n
#define out(n) cout << (n)
#define outs(n) cout << (n) << " "
#define outl(n) cout << (n) << endl
#define out2(a, b) cout << (a) << " " << (b) << endl
#define out3(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define out4(a, b, c, d) cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl
#define out5(a, b, c, d, e) cout << (a) << " " << (b) << " " << (c) << " " << (d) << " " << (e) << endl

#define vin(v, n)                     \
    vector<long long> v(n);           \
    for (long long i = 0; i < n; i++) \
        cin >> v[i];
#define vinn(v, n)                     \
    vector<long long> v(n + 1, 0);     \
    for (long long i = 1; i <= n; i++) \
        cin >> v[i];
#define vinp(v, n)                           \
    vector<pair<long long, long long>> v(n); \
    for (long long i = 0; i < n; i++)        \
        cin >> v[i].first >> v[i].second;
#define vinpp(v, n)                          \
    vector<pair<long long, long long>> v(n); \
    for (long long i = 0; i < n; i++)        \
        cin >> v[i].first;                   \
    for (long long i = 0; i < n; i++)        \
        cin >> v[i].second;
#define vinv(v, n, m)                                     \
    vector<vector<long long>> v(n, vector<long long>(m)); \
    for (long long i = 0; i < n; i++)                     \
    {                                                     \
        for (long long j = 0; j < m; j++)                 \
            cin >> v[i][j];                               \
    }

template <typename Container>
void print(const Container &container)
{
    for (const auto &i : container)
        cout << i << " ";
    cout << endl;
}
template <typename Container>
void printt(const Container &container)
{
    for (const auto &i : container)
        cout << i.first << " " << i.second << endl;
}
template <typename Container>
void printtt(const Container &container)
{
    for (const auto &i : container)
    {
        cout << "*" << " ";
        for (const auto &j : i)
            cout << j << " ";
        cout << endl;
    }
}

I gcd(I a, I b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ui lcm(ui a, ui b)
{
    return (a / gcd(a, b)) * b;
}

I power(I x, I y)
{
    I res = 1;
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

I powmod(I x, I y, I mod)
{
    I res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
}

I binmul(I x, I y, I mod)
{
    I res = 0;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res + x) % mod;
        y = y >> 1;
        x = (x + x) % mod;
    }
    return res;
}

I powbigmod(I x, I y, I mod)
{
    I res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = binmul(res, x, mod);
        y = y >> 1;
        x = binmul(x, x, mod);
    }
    return res % mod;
}

bool sortbyCond1(const pi &a,
                 const pi &b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
        return (a.second > b.second);
}

bool sortbyCond2(const pi &a,
                 const pi &b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
        return (a.second < b.second);
}

I fact(I n)
{
    I result = 1;
    for (I i = 2; i <= n; i++)
        result *= i;
    return result;
}

I phi(I n)
{
    I result = n;
    for (I i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

bool isprime(I n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (I i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

I logg(I a, I b)
{
    if (a <= 0)
        return -1000000000;
    if (b == 0)
        return 1000000000;
    if (b == 1)
    {
        if (a == 1)
            return 1000000000;
        return -1000000000;
    }
    if (a == 1)
        return 0;
    I ans = 0;
    I cur = 1;
    while (cur <= a / b)
    {
        cur *= b;
        ans++;
    }
    return ans;
}

float loggf(float a, float b)
{
    return log(a) / log(b);
}

I modInverse(I a, I m)
{
    return powmod(a, m - 2, m);
}

// vi fact(100040), invfact(100040);
// void NCR(I n, I mod)
// {
//     fact[0] = 1;
//     for (I i = 1; i <= n; i++)
//         fact[i] = fact[i - 1] * i % mod;
//     invfact[n] = powmod(fact[n], mod - 2, mod);
//     for (I i = n; i > 0; i--)
//         invfact[i - 1] = invfact[i] * i % mod;
// }

// I ncrmod(I n, I r, I mod)
// {
//     if (r < 0 || r > n)
//         return 0;
//     return ((((fact[n] * invfact[r]) % mod) * invfact[n - r]) % mod);
// }

// I fac[100050];
// void prefact()
// {
//     fac[0] = 1;
//     for (I i = 1; i <= 100010; i++)
//         fac[i] = (fac[i - 1] * i);
// }

// vi prm(10000001, 0);
// void sieveoferatosthenes(I n)
// {
//     for (I p = 2; p * p <= n + 1; p++)
//     {
//         if (prm[p] == 0)
//         {
//             prm[p] = p;
//             for (I i = p * p; i <= n; i += p)
//                 if (prm[i] == 0)
//                     prm[i] = p;
//         }
//     }
//     for (I p = 2; p <= n; p++)
//     {
//         if (prm[p] == 0)
//             prm[p] = p;
//     }
// }

void solve()
{
    def2(n, k);
    vin(a, n);
    si s;
    for0(i, n)
        s.insert(a[i]);
    for0(i, k - 1)
    {
        if (!s.count(i))
        {
            outl(i);
            return;
        }
    }
    outl(k - 1);
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
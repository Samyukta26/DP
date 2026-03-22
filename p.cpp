#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
unsigned long long lcm(unsigned long long a, unsigned long long b)
{
    return ((a / gcd(a, b)) * b);
}
long long power(long long a, long long b)
{
    if (a == 0)
        return 0;
    long long ans = 1;
    while (b > 0)
    {
        if ((b & 1))
            ans = ans * a;
        b >>= 1;
        a = a * a;
    }
    return ans;
}

long long powmod(long long a, long long b, long long c)
{
    if (a == 0)
        return 0;
    long long ans = 1;
    a = a % c;
    while (b > 0)
    {
        if ((b & 1))
            ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        // cout << __gcd(a, b) << " " << gcd(a, b) << endl;
        // cout << lcm(a, b) << endl;
        cout << power(a, b) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int t = n;
 
    int ct=0; int sum=0;
    while(n>0){
        ct++; n/=10;
    }
    n=t;
    while(t>0){
        int d=t%10;
        sum+=pow(d,ct); t/=10;
    }
    if (sum==n)
    {
        cout << "yes";
    }
    else
        cout << "no";
}

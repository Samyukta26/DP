#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int x, n;
        cin >> x >> n;
        if (n % 2 == 0)
            cout << 0;
        else
            cout << x;
        cout << endl;
    }
}
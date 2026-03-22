#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<long long> a(n + 1); // 1-based indexing
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a.begin() + 1, a.end()); // sort from index 1 to n

        long long sum = 0;
        for (int i = l; i <= r; i++) {
            sum += a[i];
        }

        cout << sum << "\n";
    }
    return 0;
}


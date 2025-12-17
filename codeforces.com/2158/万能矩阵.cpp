#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int l = 2 * n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) cout << 0 << ' ';
        cout << n << ' ';
        for (int j = 0; j < n; j++) cout << 0 << ' ';
        cout << endl;
    }

    for (int j = 0; j < n; j++) cout << 1 << ' ';
    for (int j = 0; j < n; j++) cout << n * n << ' ';
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) cout << 0 << " ";
        cout << n * n * n << ' ';
        for (int j = 0; j < n ; j++) cout <<0 << " ";
        cout << endl;
    }
}

signed main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
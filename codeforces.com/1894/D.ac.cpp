#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int n, m;
int a[200010], b[200010];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(&b[1], &b[m] + 1, greater<int>{});
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        while (cur <= m && b[cur] >= a[i]) {
            cout << b[cur] << ' ';
            cur++;
        }
        cout << a[i] << ' ';
    }
    while (cur <= m) {
        cout << b[cur] << ' ';
        cur++;
    }
    cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}
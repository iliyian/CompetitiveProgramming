#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    long long ans = 1ll * a * b * c * ((d + e) * (d + e - 1) / 2 - e * (e - 1) / 2);
    cout << ans << endl;
}
int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
#include <bits/stdc++.h>
#define N 200005
using namespace std;

int a[N];

void solve() {
  int n;
  cin >> n;
  int sum = 0, mi = 0x3f3f3f3f, mx = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]), mi = min(mi, a[i]);
  }
  int avg = sum / n;
  int maxd = mx - mi;
  if (maxd == 0) {
    cout << 0 << '\n';
    return;
  }
  int ans = log2(maxd) + 1;
  cout << ans << '\n';
  if (ans <= n) {
    for (int i = 0; i < ans; i++)
      cout << mi << ' ';
    // for (int i = ans / 2 + 1; i < ans; i++)
    //   cout << (mx - mi) / 2 + 1 << ' ';
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
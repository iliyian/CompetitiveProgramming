#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int sumb = 0, ansb = 0;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    sumb += b;
    if (a == 1) {
      ansb += b;
    }
  }
  cout << fixed << setprecision(3) << m * double(ansb) / sumb << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
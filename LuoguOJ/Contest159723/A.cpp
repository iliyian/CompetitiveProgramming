#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n, k, p, q;
  cin >> n >> k >> p >> q;
  for (int i = 0;; i++) {
    if (double(k) / (n + i) <= double(p) / q) {
      cout << i << '\n';
      break;
    }
  }

  return 0;
}
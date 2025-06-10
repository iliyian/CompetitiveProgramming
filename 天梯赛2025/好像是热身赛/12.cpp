#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }
  std::sort(p.begin(), p.end());
  std::vector<int> a;
  do {
    int x = 0;
    for (int i = 0; i < n; i++) {
      x = x * 10 + p[i];
    }
    a.push_back(x);
  } while (std::next_permutation(p.begin(), p.end()));
  int mxS = (1 << a.size()) - 1, sum2 = 0;
  for (int i = 0; i < a.size(); i++) {
    sum2 += a[i] * a[i];
    // std::cout << a[i] << ' ';
  }
  // std::cout << '\n' << sum2 << '\n';
  for (int S = mxS - 1; S >= 0; S--) {
    int sum = 0;
    if (__builtin_popcountll(S) == a.size() / 2) {
      for (int i = 0; i < a.size(); i++) {
        if (S >> i & 1) {
          sum += a[i] * a[i];
        }
      }
      if (sum * 2 == sum2) {
        for (int i = 0; i < a.size(); i++) {
          if (S >> i & 1) {
            std::cout << a[i] << '\n';
          }
        }
        break;
      }
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
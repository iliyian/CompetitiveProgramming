#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  int a[17], v[1 << 17] {};
  for (int i = 0; i < 17; i++) {
    std::cin >> a[i];
  }
  int len;
  std::cin >> len;
  if (len % 2) len++;
  int tot = 0;
  for (int l = 0; l + len - 1 < n; l++) {
    int r = l + len - 1, S = 0, f = false;
    for (int i = 0; l + i < r - i; i++) {
      // std::cerr << l + i << ' ' << r - i << '\n';
      if (str[l + i] < str[r - i]) {
        S |= 1 << (str[l + i] - 'a');
      } else if (str[l + i] > str[r - i]) {
        S |= 1 << (str[r - i] - 'a');
      } else {
        f = true;
      }
    }
    if (!f) {
      S ^= (1 << 17) - 1;
      int T = S;
      while (T) {
        v[T] = 1;
        T = (T - 1) & S;
      }
      v[0] = 1;
    }
  }
  // for (int i = 0; i < 17; i++) {
  //   for (int j = 0; j < (1 << 17); j++) {
  //     if (j >> i & 1) {
  //       v[j ^ (1 << i)] |= v[j];
  //     }
  //   }
  // }
  int ans = LLONG_MAX / 3, tot = 0;
  for (int S = 0; S < (1 << 17); S++) {
    if (!v[S]) {
      // std::cerr << S << '\n';
      // tot++;
      int cur = 0;
      for (int i = 0; i < 17; i++) {
        if (S >> i & 1) {
          cur += a[i];
          // std::cerr << i << ' ';
        }
      }
      // std::cerr << '\n';
      ans = std::min(ans, cur);
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
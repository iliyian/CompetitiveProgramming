#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  str += str;
  str = '#' + str;
  int ans = LLONG_MAX / 3;
  auto work = [&](int t) {
    std::vector<int> l(n * 2 + 2), r(n * 2 + 2), s(n * 2 + 2);
    for (int i = 1; i <= n * 2; i++) {
      if (str[i] == (t + i - 1) % 2 + '0') {
        l[i] = i;
      } else {
        l[i] = l[i - 1];
      }
    }
    for (int i = n * 2; i >= 1; i--) {
      if (str[i] == (t + i - 1) % 2 + '0') {
        r[i] = i;
      } else {
        r[i] = r[i + 1];
      }
    }
    int len = 0;
    for (int i = 1; i <= n * 2 + 1; i++) {
      if (i == n * 2 + 1 || str[i] == (t + i - 1) % 2 + '0') {
        s[i] = s[i - 1] + (len + 1) / 2;
        len = 0;
      } else {
        s[i] = s[i - 1];
        len++;
      }
    }
    for (int i = 1; i <= n * 2; i++) {
      s[i] = s[i + 1];
    }
    for (int i = 1; i <= n; i++) {
      int R = r[i], L = l[i + n - 1];
      ans = std::min(ans, (R - i + i + n - 1 - L + 1) / 2 + s[L] - (R ? s[R - 1] : 0));
    }
  };
  work(0);
  work(1);
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
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::array<int, 4> a{0, 0, 0, 0};
  for (int i = 0; i < n; i++) {
    if (str[i] == 'q') {
      a[0]++;
    }
    if (str[i] == 'c') {
      a[1] += a[0];
    }
    if (str[i] == 'j') {
      a[3] += a[2];
      a[2] += a[1];
    }
  }
  int c0 = a[3];
  a = {0, 0, 0, 0};
  for (int i = 0; i < n; i++) {
    if (str[i] == 'q') {
      a[0]++;
    }
    if (str[i] == 'c') {
      a[1] += a[0];
    }
    if (str[i] == 'a') {
      a[2] += a[1];
    }
    if (str[i] == 'y') {
      a[3] += a[2];
    }
  }
  int c1 = a[3];
  std::cout << (c0 < c1 ? "qcay" : "qcjj") << '\n';
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
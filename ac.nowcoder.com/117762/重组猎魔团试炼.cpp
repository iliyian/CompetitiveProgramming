#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, d;
  std::cin >> n >> d;
  std::string s;
  std::cin >> s;
  int cnt[128] {};
  for (char ch : s) {
    cnt[ch]++;
  }
  if (cnt['0']) {
    std::cout << 0 << '\n';
    return;
  }
  for (int i = 1; i <= 1000; i++) {
    int t = d * i;
    std::string st = std::to_string(t);
    int now[128] {};
    for (char ch : st) {
      now[ch]++;
    }
    bool f = true;
    for (int j = 0; j < 128; j++) {
      if (cnt[j] < now[j]) {
        f = false;
        break;
      }
    }
    if (f) {
      std::cout << t << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
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
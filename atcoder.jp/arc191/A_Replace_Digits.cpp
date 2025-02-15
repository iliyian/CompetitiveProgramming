#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string s, t;
  std::cin >> s >> t;
  std::vector<int> cnt(10);
  for (char ch : t) {
    cnt[ch - '0']++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 9; j > s[i] - '0'; j--) {
      if (cnt[j]) {
        s[i] = j + '0';
        --cnt[j];
        break;
      }
    }
  }
  if (s.find(t.back()) == s.npos) {
    s.back() = t.back();
  }
  std::cout << s << '\n';
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
#include <bits/stdc++.h>
#define int long long

int ch[128] {}, now[128] {};

void solve() {
  std::string t = "Kato_Shoko";
  for (auto c : t) {
    ch[c]++;
  }
  int n;
  std::string s;
  std::cin >> n >> s;
  for (auto c : s) {
    now[c]++;
  }
  for (int i = 0; i < 128; i++) {
    if (ch[i] > now[i]) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES " << n - t.size() << '\n';
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
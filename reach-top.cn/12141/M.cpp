#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e4;

std::vector<int> pri, vis(N + 1);

void solve() {
  std::string a, b;
  std::cin >> a >> b;
  for (int i = 0; i < a.size(); i++) {
    bool f = isupper(a[i]);
    char c = b[tolower(a[i]) - 'a'];
    if (f) {
      std::cout << char(toupper(c));
    } else {
      std::cout << char(tolower(c));
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
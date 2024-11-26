#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

std::vector<int> pri, vis(N + 1);

bool ispa(std::string str) {
  std::string rev = str;
  std::reverse(rev.begin(), rev.end());
  return rev == str;
}

void solve() {
  for (int i = 1; i <= 1000; i++) {
    std::string s2;
    int t = i;
    while (t) s2.push_back(t % 2 + '0'), t /= 2;
    // std::cout << t << ' ' << s2 << '\n';
    if (!ispa(s2) || !ispa(std::to_string(i))) continue;
    std::cout << i << '\n';
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
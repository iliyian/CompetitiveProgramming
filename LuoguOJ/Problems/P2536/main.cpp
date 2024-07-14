// date: 2024-07-09 21:10:53
// tag: trie

#include <bits/stdc++.h>
#define int long long
#define N 300000
// using namespace std;

std::string atcg = "ATCG";
std::map<char, int> id = {
  {'A', 0},
  {'T', 1},
  {'C', 2},
  {'G', 3},
  {'?', 4},
  {'*', 5}
};

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::string str;
  std::cin >> str;

  std::vector<std::vector<int>> trie(N, std::vector<int>(4));
  std::vector<int> val(N + 1);

  int tot = 1;
  auto insert = [&](const std::string &rdna) {
    int u = 1;
    for (char ch : rdna) {
      int idx = id[ch];
      if (!trie[u][idx]) trie[u][idx] = ++tot;
      u = trie[u][idx];
    }
    val[u]++;
  };

  int n;
  std::cin >> n;
  std::string rdna;
  for (int i = 1; i <= n; i++) {
    std::cin >> rdna;
    insert(rdna);
  }

  std::vector<std::bitset<N + 1>> vis(str.size());
  int ans = 0;
  auto dfs = [&](auto self, int u, int pos) {
    if (!u) return;
    if (pos == str.size()) {
      ans += val[u];
      val[u] = 0;
      return;
    }
    int idx = id[str[pos]];
    if (vis[pos][u]) return;
    vis[pos][u] = true;
    if (isalpha(str[pos])) {
      self(self, trie[u][idx], pos + 1);
    } else if (str[pos] == '?') {
      for (int i = 0; i < 4; i++) {
        self(self, trie[u][i], pos + 1);
      }
    } else {
      self(self, u, pos + 1);
      for (int i = 0; i < 4; i++) {
        self(self, trie[u][i], pos + 1);
        self(self, trie[u][i], pos);
      }
    }
  };
  dfs(dfs, 1, 0);
  std::cout << n - ans << '\n';

  return 0;
}
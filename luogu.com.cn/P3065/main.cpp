// date: 2024-07-10 11:23:37
// tag: trie，拓扑排序

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 5e5;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::vector<std::vector<int>> trie(N + 1, std::vector<int>(26));
  std::vector<int> val(N + 1);
  int tot = 1;

  auto insert = [&](const std::string &s) {
    int u = 1;
    for (char ch : s) {
      if (!trie[u][ch - 'a']) trie[u][ch - 'a'] = ++tot;
      u = trie[u][ch - 'a'];
    }
    val[u]++;
  };

  int n;
  std::cin >> n;
  std::vector<std::string> s(n + 1);

  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
    insert(s[i]);
  }

  auto check = [&](const std::string &str) -> bool {
    int u = 1;
    std::vector<std::bitset<26>> g(26);
    std::vector<int> in(26);
    for (char ch : str) {
      if (val[u]) return false;
      for (int i = 0; i < 26; i++) {
        if (i != ch - 'a' && trie[u][i] && !g[ch - 'a'][i]) {
          g[ch - 'a'][i] = true;
          in[i]++;
        }
      }
      u = trie[u][ch - 'a'];
    }

    std::queue<int> q;
    for (int i = 0; i < 26; i++) {
      if (!in[i]) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int i = 0; i < 26; i++) {
        if (g[u][i]) {
          if (!--in[i]) {
            q.push(i);
          }
        }
      }
    }
    for (int i = 0; i < 26; i++) {
      if (in[i]) {
        return false;
      }
    }
    return true;
  };

  std::vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (check(s[i])) {
      ans.push_back(i);
    }
  }

  std::cout << ans.size() << '\n';
  for (auto i : ans) {
    std::cout << s[i] << '\n';
  }

  return 0;
}
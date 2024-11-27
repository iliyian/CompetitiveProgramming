#include <bits/stdc++.h>
#define int long long

std::vector<int> vec;
std::vector<std::vector<std::pair<int, int>>> g;

int n;

std::vector<int> cur;

void dfs(int u, int p, int rt) {
  if (!cur.empty() && u > rt) {
    auto tmp = cur;
    std::sort(tmp.begin(), tmp.end());
    vec.push_back(tmp[tmp.size() / 2]);
  }
  for (auto [v, w] : g[u]) {
    if (v != p) {
      cur.push_back(w);
      dfs(v, u, rt);
      cur.pop_back();
    }
  }
}

signed main( ) {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n;
  g.assign(n + 1, {});
  std::vector<int> weights;
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
    weights.push_back(w);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, 0, i);
  }
  std::sort(vec.begin(), vec.end());
  std::sort(weights.begin(), weights.end());
  std::map<int, int> cnt;
  for (auto i : vec) {
    std::cout << i << ' ';
    cnt[i]++;
  }
  // std::cout << '\n';
  // std::cout << vec.size() << '\n';
  std::cout << vec[vec.size() / 2] << '\n';
  std::cout << weights[weights.size() / 2] << '\n';
  return 0;
}
// date: 2024-07-21 10:20:20
// tag: 时间线分治，lca
// 这里疑似倍增lca严重慢于树剖

#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define N ((int)1e5 + 5)
// using namespace std;

std::vector<int> g[N];
std::vector<std::vector<int>> pa(N, std::vector<int>(21));
std::vector<int> dep(N);

void dfs(int x, int p) {
  pa[x][0] = p;
  dep[x] = dep[p] + 1;
  for (int i = 1; i <= 20; i++) {
    pa[x][i] = pa[pa[x][i - 1]][i - 1];
  }
  for (int y : g[x]) {
    if (y != p) {
      dfs(y, x);
    }
  }
}

int lca(int x, int y) {
  if (dep[x] < dep[y]) std::swap(x, y);
  for (int i = 20; i >= 0; i--) {
    if (dep[x] - (1 << i) >= dep[y]) {
      x = pa[x][i];
    }
  }
  if (x == y) return x;
  for (int i = 20; i >= 0; i--) {
    if (pa[x][i] != pa[y][i]) {
      x = pa[x][i], y = pa[y][i];
    }
  }
  return pa[x][0];
}

int dis(int x, int y) {
  return dep[x] + dep[y] - (dep[lca(x, y)] << 1);
}

struct op {
  int l, r, v;
};

std::vector<int> timeline[(N * 5) << 2]; // ！！时间不是n

void update(int l, int r, int s, int t, int p, int x) {
  if (l <= s && t <= r) {
    timeline[p].push_back(x);
    return;
  }
  int mid = (s + t) / 2;
  if (l <= mid) update(l, r, s, mid, lc, x);
  if (r > mid) update(l, r, mid + 1, t, rc, x);
}

int u, v;
std::stack<std::pair<int, int>> st;
std::vector<int> ans(N * 5);
std::bitset<N * 5> isquery;

void solve(int s, int t, int p) {
  auto level = st.size();
  for (auto x : timeline[p]) {
    st.push({u, v});
    if (!u && !v) {
      u = v = x;
    } else {
      std::vector<int> three = {dis(u, v), dis(u, x), dis(v, x)};
      std::sort(three.begin(), three.end(), std::greater<int>());
      if (three.front() == dis(u, x)) {
        v = x;
      } else if (three.front() == dis(v, x)) {
        u = x;
      }
    }
  }

  if (s == t) {
    if (isquery[s]) {
      if (!u && !v) {
        ans[s] = -1;
      } else if (!u || !v) {
        ans[s] = 0;
      } else {
        ans[s] = dis(u, v);
      }
    }
  } else {
    int mid = (s + t) / 2;
    solve(s, mid, lc);
    solve(mid + 1, t, rc);
  }

  while (level < st.size()) {
    u = st.top().first, v = st.top().second;
    st.pop();
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  int m;
  std::cin >> m;
  std::vector<op> ops;
  std::vector<int> lst(n + 1, 1);
  for (int i = 1; i <= m; i++) {
    char op;
    int x;
    std::cin >> op;
    if (op == 'C') {
      std::cin >> x;
      if (lst[x]) {
        ops.push_back({lst[x], i, x});
        lst[x] = 0;
      } else {
        lst[x] = i;
      }
    } else {
      isquery[i] = true;
    }
  }
  ++m;
  for (int i = 1; i <= n; i++) {
    if (lst[i]) {
      ops.push_back({lst[i], m, i});
    }
  }

  for (auto [l, r, x] : ops) {
    // std::cout << l << ' ' << r << ' ' << x << '\n';
    update(l, r, 1, m, 1, x);
  }
  solve(1, m, 1);
  for (int i = 1; i <= m; i++) {
    if (isquery[i]) {
      std::cout << ans[i] << '\n';
    }
  }

  return 0;
}
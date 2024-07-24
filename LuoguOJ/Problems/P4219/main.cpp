// date: 2024-07-21 09:12:13
// tag: 时间线分治，可撤销并查集

#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define N ((int)1e5 + 5)
// using namespace std;

struct UndoObject {
  int x, val;
};
std::stack<UndoObject> undo_pa, undo_siz;

std::vector<int> pa(N), siz(N, 1);

int find(int x) {
  return x == pa[x] ? x : find(pa[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) {
    return;
  }
  if (siz[x] < siz[y]) {
    std::swap(x, y);
  }
  undo_pa.push({y, pa[y]});
  pa[y] = x;
  undo_siz.push({x, siz[x]});
  siz[x] += siz[y];
}

void undo() {
  pa[undo_pa.top().x] = undo_pa.top().val;
  undo_pa.pop();
  siz[undo_siz.top().x] = undo_siz.top().val;
  undo_siz.pop();
}

std::vector<std::pair<int, int>> timeline[N << 3];

void update(int l, int r, int s, int t, int p, std::pair<int, int> &edge) {
  if (l <= s && t <= r) {
    timeline[p].push_back(edge);
    return;
  }
  int mid = (s + t) / 2;
  if (l <= mid) update(l, r, s, mid, lc, edge);
  if (r > mid) update(l, r, mid + 1, t, rc, edge);
}

std::map<int, bool> isquery;
std::map<int, int> ans;
std::map<int, std::pair<int, int>> edges;

int t = 0;

void solve(int s, int t, int p) {
  auto level = undo_pa.size();
  for (auto [x, y] : timeline[p]) {
    merge(x, y);
  }
  if (s == t) {
    if (isquery[s]) {
      auto [x, y] = edges[s];
      ans[s] = siz[find(x)] * siz[find(y)];
    }
  } else {
    int mid = (s + t) / 2;
    solve(s, mid, lc);
    solve(mid + 1, t, rc);
  }
  while (undo_pa.size() > level) {
    undo();
  }
}

struct op {
  int l, r;
  std::pair<int, int> e;
};

std::map<std::pair<int, int>, int> appear;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::iota(pa.begin() + 1, pa.end(), 1);

  int n, m;
  std::cin >> n >> m;

  std::vector<op> ops;
  std::vector<std::tuple<int, int, int>> toend;
  for (int i = 1; i <= m; i++) {
    char op;
    int x, y;
    std::cin >> op >> x >> y;
    if (op == 'A') {
      appear[{x, y}] = ++t;
    } else {
      int l = appear[{x, y}]; // 保证有边
      ops.push_back({l, t, {x, y}});
      isquery[++t] = true;
      edges[t] = {x, y};
      appear[{x, y}] = ++t;
      // toend.push_back({++t, x, y});
    }
  }

  ++t;

  for (auto [xy, tim] : appear) {
    ops.push_back({tim, t, xy});
  }

  // for (auto [r, x, y] : toend) {
  //   ops.push_back({r, t, {x, y}});
  // }

  for (auto &[l, r, e] : ops) {
    // std::cout << l << ' ' << r << ' ' << e.first << ' ' << e.second << '\n';
    update(l, r, 1, t, 1, e);
  }

  solve(1, t, 1);
  for (auto [k, v] : ans) {
    if (isquery[k]) {
      std::cout << v << '\n';
    }
  }

  return 0;
}
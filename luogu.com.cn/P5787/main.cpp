// date: 2024-07-20 15:30:08
// tag: 时间线分治，可撤销并查集，种类并查集

#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define N ((int)1e5 + 5)
using namespace std;

std::vector<int> siz(N << 1, 1), pa(N << 1);

struct UndoObject {
  int x, val;
};

struct Edge {
  int x, y;
};
std::vector<Edge> edges(N << 1);

int n, m, k;

int find(int x) {
  return x == pa[x] ? x : find(pa[x]);
}

std::stack<UndoObject> undo_pa, undo_siz;

void undo() {
  pa[undo_pa.top().x] = undo_pa.top().val;
  undo_pa.pop();
  siz[undo_siz.top().x] = undo_siz.top().val;
  undo_siz.pop();
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (siz[x] < siz[y]) {
    std::swap(x, y);
  }
  undo_siz.push({x, siz[x]});
  siz[x] += siz[y];
  undo_pa.push({y, pa[y]});
  pa[y] = x;
}

std::vector<std::vector<int>> timeline(N << 2);

void update(int l, int r, int s, int t, int p, int idx) {
  if (l <= s && t <= r) {
    timeline[p].push_back(idx);
    return;
  }
  int mid = (s + t) / 2;
  if (l <= mid) update(l, r, s, mid, lc, idx);
  if (r > mid) update(l, r, mid + 1, t, rc, idx);
}

std::vector<bool> ret;

void solve(int s, int t, int p) {
  auto level = undo_pa.size();
  bool f = true;

  for (int u : timeline[p]) {
    auto [x, y] = edges[u];
    if (find(x) == find(y)) {
      f = false;
      for (int i = s; i <= t; i++) {
        ret.push_back(false);
      }
      break;
    }
    merge(x, y + n);
    merge(y, x + n);
  }
  if (f) {
    if (s == t) {
      ret.push_back(true);
    } else {
      int mid = (s + t) / 2;
      solve(s, mid, lc);
      solve(mid + 1, t, rc);
    }
  }
  while (undo_pa.size() > level) {
    undo();
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::iota(pa.begin() + 1, pa.end(), 1);

  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int x, y, l, r;
    std::cin >> x >> y >> l >> r;
    edges[i] = {x, y};
    update(l + 1, r, 1, k, 1, i); // time segments
  }
  solve(1, k, 1);
  for (auto x : ret) {
    std::cout << (x ? "Yes" : "No") << '\n';
  }

  return 0;
}
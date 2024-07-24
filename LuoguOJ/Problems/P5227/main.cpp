// date: 2024-07-21 11:55:49
// tag: 时间线分治，可撤销并查集维护图的连通性

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N ((int)1e5 + 5)
#define M ((int)2e5 + 5)
// using namespace std;

struct UndoObject {
  int x, val;
};

std::stack<UndoObject> undo_pa, undo_siz;
std::vector<int> pa(N), siz(N, 1);

int find(int x) {return x == pa[x] ? x : find(pa[x]);};

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) {
    return;
  }
  if (siz[x] > siz[y]) std::swap(x, y);
  undo_pa.push({x, pa[x]});
  pa[x] = y;
  undo_siz.push({y, siz[y]});
  siz[y] += siz[x];
}

void undo() {
  pa[undo_pa.top().x] = undo_pa.top().val;
  undo_pa.pop();
  siz[undo_siz.top().x] = undo_siz.top().val;
  undo_siz.pop();
}

std::vector<std::pair<int, int>> edges(M);
std::vector<std::pair<int, int>> timeline[M << 2];
std::vector<int> q[M];

int n, m, k;

void update(int l, int r, int s, int t, int p, std::pair<int, int> &xy) {
  if (l > r) return;
  if (l <= s && t <= r) {
    timeline[p].push_back(xy);
    return;
  }
  int mid = (s + t) / 2;
  if (l <= mid) update(l, r, s, mid, lc, xy);
  if (r > mid) update(l, r, mid + 1, t, rc, xy);
}

std::bitset<M> ans;


void solve(int s, int t, int p) {
  auto level = undo_pa.size();;

  for (auto [x, y] : timeline[p]) {
    merge(x, y);
  }

  if (s == t) {
    ans[s] = (siz[find(1)] == n);
  } else {
    int mid = (s + t) / 2;
    solve(s, mid, lc);
    solve(mid + 1, t, rc);
  }

  while (level < undo_pa.size()) {
    undo();
  }
}

struct op {
  int l, r;
  std::pair<int, int> e;
};

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::iota(pa.begin() + 1, pa.end(), 1);

  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    edges[i] = {x, y};
  }

  std::cin >> k;

  std::vector<int> lst(M, 1);
  std::vector<op> ops;
  for (int i = 1; i <= k; i++) {
    int c;
    std::cin >> c;
    for (int j = 1; j <= c; j++) {
      int x;
      std::cin >> x;

      ops.push_back({lst[x], i - 1, edges[x]});

      lst[x] = i + 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    ops.push_back({lst[i], k, edges[i]});
  }

  for (auto &[l, r, e] : ops) {
    if (l > r) continue;
    // std::cout << l << ' ' << r << ' ' << e.first << ' ' << e.second << '\n';
    update(l, r, 1, k, 1, e);
  }

  solve(1, k, 1);

  for (int i = 1; i <= k; i++) {
    std::cout << (ans[i] ? "Connected" : "Disconnected") << '\n';
  }

  return 0;
}
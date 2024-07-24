// date: 2024-07-21 11:15:18
// tag: 时间线分治，可撤销并查集，树

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N ((int)5e5 + 5)
// using namespace std;

struct UndoObject {
  int x, val;
};

std::stack<UndoObject> undo_pa, undo_siz;
std::vector<int> pa(N), siz(N, 1);

int find(int x) {return x == pa[x] ? x : find(pa[x]);};

void undo() {
  pa[undo_pa.top().x] = undo_pa.top().val;
  undo_pa.pop();
  siz[undo_siz.top().x] = undo_siz.top().val;
  undo_siz.pop();
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (siz[x] > siz[y]) std::swap(x, y);
  undo_pa.push({x, pa[x]});
  pa[x] = y;
  undo_siz.push({y, siz[y]});
  siz[y] += siz[x];
}

int n;
std::vector<std::pair<int, int>> timeline[N << 2];
std::vector<std::pair<int, int>> edges[N];

void update(int l, int r, int s, int t, int p, std::pair<int, int> &x) {
  if (l <= s && t <= r) {
    timeline[p].push_back(x);
    return;
  }
  int mid = (s + t) / 2;
  if (l <= mid) update(l, r, s, mid, lc, x);
  if (r > mid) update(l, r, mid + 1, t, rc, x);
}

int ans = 0;

void solve(int s, int t, int p) {
  auto level = undo_pa.size();
  for (auto [x, y] : timeline[p]) {
    merge(x, y);
  }
  if (s == t) {
    for (auto [x, y] : edges[s]) {
      ans += siz[find(x)] * siz[find(y)];
    }
  } else {
    int mid = (s + t) / 2;
    solve(s, mid, lc);
    solve(mid + 1, t, rc);
  }
  while (level < undo_pa.size()) {
    undo();
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  std::iota(pa.begin() + 1, pa.end(), 1);

  std::cin >> n;

  for (int i = 1; i <= n - 1; i++) {
    int x, y, c;
    std::cin >> x >> y >> c;
    std::pair<int, int> xy = {x, y};
    edges[c].push_back({x, y});
    if (c > 1) update(1, c - 1, 1, n, 1, xy);
    // 边对于颜色的不存在性
    // 因为我们只能维护某些数据上另一些数据的存在性
    if (c < n) update(c + 1, n, 1, n, 1, xy);
  }
  solve(1, n, 1);
  std::cout << ans << '\n';

  return 0;
}
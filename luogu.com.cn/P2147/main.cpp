// date: 2024-07-21 12:52:50
// tag: 时间线分治，可撤销并查集，图连通性

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N ((int)1e4 + 5)
#define M ((int)2e5 + 5)
// using namespace std;

struct UndoObject {
  int x, val;
};

std::stack<UndoObject> undo_pa, undo_siz;

std::vector<int> pa(N), siz(N, 1);

int find(int x) {return x == pa[x] ? x : find(pa[x]);}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
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

std::vector<std::pair<int, int>> timeline[M << 2];

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

std::bitset<M> isquery, ans;
std::vector<std::pair<int, int>> edges(M);

void solve(int s, int t, int p) {
  auto level = undo_pa.size();
  for (auto [x, y] : timeline[p]) {
    merge(x, y);
  }
  
  if (s == t) {
    if (isquery[s]) {
      ans[s] = (find(edges[s].first) == find(edges[s].second));
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

int n, m;

struct op {
  int l, r;
  std::pair<int, int> e;
};

std::map<std::pair<int, int>, int> id;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::iota(pa.begin() + 1, pa.end(), 1);

  std::cin >> n >> m;
  std::vector<int> lst(M);
  std::vector<op> ops;
  for (int i = 1; i <= m; i++)  {
    std::string op;
    int x, y;
    std::cin >> op >> x >> y;
    if (x > y) std::swap(x, y);
    edges[i] = {x, y};
    if (op == "Connect") {
      if (!id.count({x, y})) {
        id[{x, y}] = i;
      }
      lst[id[{x, y}]] = i;
    } else if (op == "Destroy") {
      int idx = id[{x, y}];
      ops.push_back({lst[idx], i - 1, {x, y}});
      lst[idx] = 0;
    } else {
      isquery[i] = true;
    }
  }

  for (auto [xy, idx] : id) {
    if (lst[idx]) {
      ops.push_back({lst[idx], m, xy});
    }
  }

  for (auto &[l, r, e] : ops) {
    if (l > r) continue;
    // std::cout << l << ' ' << r << ' ' << e.first << ' ' << e.second << '\n';
    update(l, r, 1, m, 1, e);
  }

  solve(1, m, 1);
  for (int i = 1; i <= m; i++) {
    if (isquery[i]) {
      std::cout << (ans[i] ? "Yes" : "No") << '\n';
    }
  }

  return 0;
}
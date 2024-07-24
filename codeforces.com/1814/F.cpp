// date: 2024-07-21 15:04:02
// tag: 时间线分治传递tag

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N ((int)2e5 + 5)
#define M ((int)4e5 + 5)
// using namespace std;

struct UndoObject {
  int x, val;
};

std::stack<UndoObject> undo_pa, undo_siz, undo_tag, st;

std::vector<int> pa(N), siz(N, 1), tag(N);

int find(int x) {return x == pa[x] ? x : find(pa[x]);};

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) {
    return;
  }
  if (siz[x] > siz[y]) {
    std::swap(x, y);
  }
  st.push({x, y});
  // undo_pa.push({x, pa[x]});
  pa[x] = y;
  // undo_siz.push({y, siz[y]});
  siz[y] += siz[x];
  // undo_tag.push({x, tag[x]});
  tag[x] -= tag[y]; // unindependent
}

void undo() {
  // pa[undo_pa.top().x] = undo_pa.top().val;
  // undo_pa.pop();
  // siz[undo_siz.top().x] = undo_siz.top().val;
  // undo_siz.pop();
  // tag[undo_tag.top().x] = undo_tag.top().val;
  // undo_tag.pop();
  auto [x, y] = st.top(); st.pop();
  pa[x] = x, siz[y] -= siz[x], tag[x] += tag[y];
}

std::vector<std::pair<int, int>> timeline[M << 2];

void solve(int s, int t, int p) {
  auto level = st.size();
  for (auto [x, y] : timeline[p]) {
    merge(x, y);
  }
  if (s == t) {
    tag[find(1)]++;
  } else {
    int mid = (s + t) / 2;
    solve(s, mid, lc), solve(mid + 1, t, rc);
  }
  while (level < st.size()) {
    undo();
  }
}

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

int n, m;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  std::iota(pa.begin() + 1, pa.end(), 1);

  std::cin >> n >> m;
  std::vector<int> l(n + 1), r(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
    // r[i]++, l[i]++;
    mx = std::max(mx, r[i]);
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    std::pair<int, int> xy = {x, y};
    update(std::max(l[x], l[y]), std::min(r[x], r[y]), 1, mx, 1, xy);
  }
  solve(1, mx, 1);
  for (int i = 1; i <= n; i++) {
    if (tag[i]) {
      std::cout << i << ' ';
    }
  }

  return 0;
}
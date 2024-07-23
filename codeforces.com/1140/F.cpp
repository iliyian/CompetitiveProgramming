// date: 2024-07-22 10:14:08
// tag: 线段树分治，二分图siz维护，可撤销冰茶姬

#include <bits/stdc++.h>
#define int long long
#define N ((int)3e5 + 5)
#define M ((int)3e5 + 5)
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
// using namespace std;

std::stack<std::pair<int, int>> st;
std::vector<int> pa(N << 1), l(N << 1), r(N << 1);

int find(int x) {return x == pa[x] ? x : find(pa[x]);};

int res = 0;

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) {
    return;
  }
  if (l[x] + r[x] > l[y] + r[y]) {
    std::swap(x, y);
  }
  st.push({x, y});
  res -= l[x] * r[x] + l[y] * r[y];
  pa[x] = y;
  l[y] += l[x], r[y] += r[x];
  res += l[y] * r[y];
}

void undo() {
  auto [x, y] = st.top(); st.pop();
  pa[x] = x;
  res -= l[y] * r[y];
  l[y] -= l[x], r[y] -= r[x];
  res += l[x] * r[x] + l[y] * r[y];
}

std::map<std::pair<int, int>, int> id;
std::vector<std::pair<int, int>> timeline[M << 2];
std::vector<int> ans(M);

void solve(int s, int t, int p) {
  auto level = st.size();
  for (auto [x, y] : timeline[p]) {
    merge(x, y + N);
  }
  if (s == t) {
    ans[s] = res;
  } else {
    solve(s, mid, lc);
    solve(mid + 1, t, rc);
  }
  while (level < st.size()) {
    undo();
  }
}

std::vector<std::pair<int, int>> xy(M);

void update(int l, int r, int s, int t, int p, int idx) {
  if (l <= s && t <= r) {
    timeline[p].push_back(xy[idx]);
    return;
  }
  if (l <= mid) update(l, r, s, mid, lc, idx);
  if (r > mid) update(l, r, mid + 1, t, rc, idx);
}

int m;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  for (int i = 1; i <= N * 2; i++) {
    pa[i] = i;
    l[i] = i <= N;
    r[i] = l[i] ^ 1;
  }

  std::cin >> m;

  std::vector<int> lst(m + 1);
  std::vector<std::tuple<int, int, int>> ops;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    int &idx = id[{x, y}];
    if (!idx) idx = i, xy[i] = {x, y};
    if (!lst[idx]) {
      lst[idx] = i;
    } else {
      ops.push_back({lst[idx], i - 1, idx});
      lst[idx] = 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (lst[i]) {
      ops.push_back({lst[i], m, i});
    }
  }
  for (auto [l, r, id] : ops) {
    // std::cout << l << ' ' << r << ' ' << xy[id].first << ' ' << xy[id].second << '\n';
    update(l, r, 1, m, 1, id);
  }
  solve(1, m, 1);
  for (int i = 1; i <= m; i++) {
    std::cout << ans[i] << ' ';
  }

  return 0;
}
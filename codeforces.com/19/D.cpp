// date: 2024-05-23 17:00:00
// tag: 线段树二分

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5)
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

int mx[(N + 5) << 3];

void build(int l, int r, int p) {
  if (l == r) {
    mx[p] = 0;
    return;
  };
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  mx[p] = max(mx[lc], mx[rc]);
}

void modify(int x, int s, int t, int p, int c) {
  if (x == s && s == t) {
    mx[p] = c;
    return;
  }
  int mid = (s + t) / 2;
  if (x <= mid) modify(x, s, mid, lc, c);
  else modify(x, mid + 1, t, rc, c);
  mx[p] = max(mx[lc], mx[rc]);
}

int query(int x, int s, int t, int p, int y) {
  if (s == t) {
    return mx[p] > y ? s : -1;
  }
  int mid = (s + t) / 2, ans = -1;
  if (x <= mid && mx[lc] > y) ans = query(x, s, mid, lc, y);
  if (ans != -1) return ans;
  if (mx[rc] > y) ans = query(x, mid + 1, t, rc, y);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  cin >> n;
  vector<tuple<string, int, int>> q;
  vector<int> v;
  v.push_back(-1);
  for (int i = 1; i <= n; i++) {
    string op;
    int x, y;
    cin >> op >> x >> y;
    q.push_back({op, x, y});
    v.push_back(x);
    v.push_back(y);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  auto lo = [&](int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  };

  int len = v.size();
  vector<set<int>> s(v.size());

  for (auto &[op, x, y] : q) {
    x = lo(x), y = lo(y);
    if (op == "add") {
      if (s[x].empty()) {
        s[x].insert(y);
        modify(x, 1, len - 1, 1, y);
        continue;
      }
      int max_ = *s[x].rbegin();
      s[x].insert(y);
      if (y > max_) {
        modify(x, 1, len - 1, 1, y);
      }
    } else if (op == "remove") {
      int max_ = *s[x].rbegin();
      s[x].erase(y);
      if (max_ == y) {
        if (s[x].empty()) {
          modify(x, 1, len - 1, 1, 0);
        } else {
          modify(x, 1, len - 1, 1, *s[x].rbegin());
        }
      }
    } else if (op == "find") {
      int ans = query(x + 1, 1, len - 1, 1, y);
      if (ans == -1) {
        cout << -1 << '\n';
      } else {
        int ansx = ans;
        int ansy = *s[ansx].upper_bound(y);
        cout << v[ansx] << ' ' << v[ansy] << '\n';
      }
    }
  }

  return 0;
}
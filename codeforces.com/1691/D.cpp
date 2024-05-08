// date: 2024-05-06 13:58:49
// tag: 单调栈，线段树

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  vector<int> l(n + 1), r(n + 1);

  stack<int> st;
  for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()] < a[i]) {
      int u = st.top(); st.pop();
      r[u] = i - 1;
    }
    st.push(i);
  }
  while (!st.empty()) {
    int u = st.top(); st.pop();
    r[u] = n;
  }

  for (int i = n; i >= 1; i--) {
    while (!st.empty() && a[st.top()] < a[i]) {
      int u = st.top(); st.pop();
      l[u] = i + 1;
    }
    st.push(i);
  }
  while (!st.empty()) {
    int u = st.top(); st.pop();
    l[u] = 1;
  }

  vector<int> mx((n + 5) << 2), mn((n + 5) << 2);

  auto pushup = [&](int p) {
    mx[p] = max(mx[lc], mx[rc]);
    mn[p] = min(mn[lc], mn[rc]);
  };
  auto build = [&](auto self, int l, int r, int p) {
    if (l == r) {
      mx[p] = mn[p] = s[l];
      return;
    }
    int mid = (l + r) / 2;
    if (l <= mid) self(self, l, mid, lc);
    if (r > mid) self(self, mid + 1, r, rc);
    pushup(p);
  };
  auto querymin = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l <= s && t <= r) return mn[p];
    int mid = (s + t) / 2, ans = LLONG_MAX;
    if (l <= mid) ans = min(ans, self(self, l, r, s, mid, lc));
    if (r > mid) ans = min(ans, self(self, l, r, mid + 1, t, rc));
    return ans;
  };
  auto querymax = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l <= s && t <= r) return mx[p];
    int mid = (s + t) / 2, ans = LLONG_MIN;
    if (l <= mid) ans = max(ans, self(self, l, r, s, mid, lc));
    if (r > mid) ans = max(ans, self(self, l, r, mid + 1, t, rc));
    return ans;
  };

  build(build, 0, n, 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] < querymax(querymax, i, r[i], 0, n, 1)
       - querymin(querymin, l[i] - 1, i - 1, 0, n, 1)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}
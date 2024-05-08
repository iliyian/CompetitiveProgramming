// date: 2024-05-07 15:11:03
// tag: RMQ, dp

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), le(n + 1), ge(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    le[i] = ge[i] = i;
    pos[a[i]] = i;
  }

  stack<int> st;
  for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()] < a[i])  {
      ge[st.top()] = i; st.pop();
    }
    st.push(i);
  }
  while (!st.empty())
  { ge[st.top()] = n + 1; st.pop(); }

  for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()] > a[i])  {
      le[st.top()] = i; st.pop();
    }
    st.push(i);
  }
  while (!st.empty())
  { le[st.top()] = n + 1; st.pop(); }

  int logn = 20;
  vector<vector<int>> mx(n + 1, vector<int>(21)), mn(n + 1, vector<int>(21));
  for (int i = 1; i <= n; i++) {
    mn[i][0] = mx[i][0] = a[i];
  }
  for (int j = 1; j <= logn; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
    }
  }
  auto querymax = [&](int l, int r) {
    int len = __lg(r - l + 1);
    return max(mx[l][len], mx[r - (1 << len) + 1][len]);
  };
  auto querymin = [&](int l, int r) {
    int len = __lg(r - l + 1);
    return min(mn[l][len], mn[r - (1 << len) + 1][len]);
  };

  vector<int> dis(n + 1);
  priority_queue<int> q;
  q.push(1);
  dis[1] = 1;
  while (!q.empty()) {
    int u = q.top(); q.pop();
    if (u == n) {
      cout << dis[u] - 1 << '\n';
      return;
    }
    int max_ = pos[querymax(u, le[u] - 1)];
    if (!dis[max_]) {
      q.push(max_);
      dis[max_] = dis[u] + 1;
    }

    int min_ = pos[querymin(u, ge[u] - 1)];
    if (!dis[min_]) {
      q.push(min_);
      dis[min_] = dis[u] + 1;
    }
  }
  cout << -1 << '\n';
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
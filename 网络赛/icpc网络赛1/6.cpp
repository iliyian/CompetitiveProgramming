#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a = {{}};
  int prv = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (x == prv) {
      a.back().second++;
    } else {
      a.push_back({x, 1});
    }
    prv = x;
  }
  n = a.size() - 1;
  std::vector<int> l(n + 1), r(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i].second;
  }
  std::stack<int> st;
  for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()].first <= a[i].first) {
      r[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    r[st.top()] = n + 1; st.pop();
  }
  
  for (int i = n; i >= 1; i--) {
    while (!st.empty() && a[st.top()].first <= a[i].first) {
      l[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    l[st.top()] = 0; st.pop();
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int L = l[i], R = r[i];
    if (!(R != n + 1 && a[R].first == a[i].first)) {
      ans += s[R - 1] - s[i];
    }
    ans += s[i - 1] - s[L];
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("6.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
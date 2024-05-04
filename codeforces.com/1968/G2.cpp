// date: 2024-05-03 13:31:58
// tag: 根号分治，Z函数

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> z_function(const string &s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0ll, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  string str;
  cin >> str;
  int t = sqrt(n + 0.5);
  vector<int> ans(n + 1);
  vector<int> z = z_function(str);
  z[0] = n;
  auto check = [&](int mid) {
    int cnt = 0, lst = -n;
    for (int i = 0; i < n; i++) {
      if (z[i] >= mid && i - lst >= mid) {
        lst = i;
        cnt++;
      }
    }
    return cnt;
  };
  auto calc = [&](int k) {
    int l = 1, r = n, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid) >= k) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    return ans;
  };
  // auto start = clock();
  for (int i = l; i <= t; i++) {
    ans[i] = calc(i);
  }
  // auto end = clock();
  // cout << double(end - start) / CLOCKS_PER_SEC << '\n';
  for (int len = t + 2; len >= 0; len--) {
    int k = check(len);
    if (!ans[k]) {
      ans[k] = len;
    }
  }
  int lst = 0;
  for (int i = n; i >= 1; i--) {
    if (ans[i]) lst = ans[i];
    else ans[i] = lst;
  }
  for (int i = l; i <= r; i++) {
    cout << ans[i] << " \n"[i == r];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G2.in", "r", stdin);
  freopen("G2.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}
// date: 2024-08-05 11:17:14
// tag: lis

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> s(m + 2);
  for (int i = 1; i <= n; i++) {
    int l, r;
    std::cin >> l >> r;
    s[l]++, s[r + 1]--;
  }
  for (int i = 1; i <= m; i++) {
    s[i] += s[i - 1];
  }
  std::vector<int> a, fl(m + 2), fr(m + 2);
  for (int i = 1; i <= m; i++) {
    if (a.empty() || s[i] >= a.back()) {
      a.push_back(s[i]);
    } else {
      *std::upper_bound(a.begin(), a.end(), s[i]) = s[i];
    }
    fl[i] = a.size();
  }

  a.clear();
  for (int i = m; i >= 1; i--) {
    if (a.empty() || s[i] >= a.back()) {
      a.push_back(s[i]);
    } else {
      *std::upper_bound(a.begin(), a.end(), s[i]) = s[i];
    }
    fr[i] = a.size();
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = std::max(ans, fl[i] + fr[i] - 1);
  }
  std::cout << ans << '\n';

  return 0;
}
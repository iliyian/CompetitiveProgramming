#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  int mx = 0, mx2 = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] > mx) {
      mx2 = mx;
      mx = a[i];
    } else if (a[i] > mx2) {
      mx2 = a[i];
    }
  }
  std::deque<int> q;
  for (int i = 1; i <= n; i++) {
    q.push_back(i);
  }
  std::vector<int> ans(n + 1), pre(n + 1), suf(n + 1), cor(n + 1);
  bool f = false;
  int cnt = 0, r = k % (2 * n - 2), j = 0, rk = k;
  for (int i = 1; i <= n * 10; i++) {
    if (k == 0) break;
    int x = q.front(); q.pop_front();
    int y = q.front(); q.pop_front();
    if (a[x] < a[y]) std::swap(x, y);
    if (a[x] == mx) {
      cnt++;
      if (cnt == 1 && a[y] == mx2) { // loop sign
        if (f == false) {// loop begin
          f = true;
          r = k % (2 * n - 2);
          rk = k;
        } else { // loop end
          break;
        }
      }
      if (cnt == n) {
        std::swap(x, y);
        cnt = 0;
      }
    }
    if (f) {
      j++;
      ans[x]++, ans[y]++;
    } else {
      pre[x]++, pre[y]++;
    }
    q.push_back(y);
    q.push_front(x);
    k--;
    if (j == r) {
      suf = ans;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << pre[i] + suf[i] + ans[i] * (rk / (n * 2 - 2)) << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
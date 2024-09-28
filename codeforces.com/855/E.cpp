#include <bits/stdc++.h>
#define int long long
// using namespace std;

int b;
std::vector<std::vector<std::vector<int>>> f(11, std::vector<std::vector<int>>(65, std::vector<int>(1024, -1)));
std::vector<int> a;

// q->not ceil
int work(int k, int s, bool p, bool q) {
  if (!k) {
    return !s;
  }
  if (!p && !q && f[b][k][s] != -1) {
    return f[b][k][s];
  }
  int t = q ? a[k - 1] : b - 1, ans = 0;
  for (int i = 0; i <= t; i++) {
    ans += work(k - 1, p && !i ? 0 : s ^ (1 << i) , p && !i, q && (i == t));
  }
  if (!p && !q) {
    f[b][k][s] = ans;
  }
  return ans;
}

int solve(int x) {
  a.clear();
  while (x) {
    a.push_back(x % b);
    x /= b;
  }
  return work(a.size(), 0, true, true);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int t;
  std::cin >> t;

  while (t--) {
    int l, r;
    std::cin >> b >> l >> r;
    std::cout << solve(r) - solve(l - 1) << '\n';
  }

  return 0;
}
// date: 2024-08-05 13:00:37
// tag: 模拟

//记忆时常在恶心我

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

std::string WDSA = "WDSA";
int d(char x) { return WDSA.find(x);}

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  int x = 0, y = 0;
  int A = 0, D = 0, W = 0, S = 0;
  int lsta = 0, lstd = 0, lstw = 0, lsts = 0, fsta = 0, fstd = 0, fstw = 0, fsts = 0;
  for (int i = 1; i <= n; i++) {
    x += dx[d(str[i])], y += dy[d(str[i])];
    if (y < A) {
      A = y, fsta = i;
    }
    if (y == A) lsta = i;
    if (y > D) {
      D = y, fstd = i;
    }
    if (y == D) lstd = i;
    if (x > S) {
      S = x, fsts = i;
    }
    if (x == S) lsts = i;
    if (x < W) {
      W = x, fstw = i;
    }
    if (x == W) lstw = i;
  }
  int sum = (S - W + 1) * (D - A + 1);
  int ans = sum;
  if (fsta - lstd > 1) {
    ans = std::min(ans, sum - (S - W + 1));
  }
  if (fstd - lsta > 1) {
    ans = std::min(ans, sum - (S - W + 1));
  }
  if (fsts - lstw > 1) {
    ans = std::min(ans, sum - (D - A + 1));
  }
  if (fstw - lsts > 1) {
    ans = std::min(ans, sum - (D - A + 1));
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}
// 下载了三个数据了

#include <bits/stdc++.h>
using namespace std;

array<int, 1000001> r, b, sum, s, t, d;
int n, m;

void change(int ans, int sig) {
  for (int i = 1; i <= ans; i++) {
    b[s[i]] -= d[i] * sig;
    b[t[i] + 1] += d[i] * sig;
  }
}

bool check(int ans) {
  sum.fill(0);
  change(ans, 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + b[i];
    if (sum[i] < 0) {
      change(ans, -1);
      return false;
    }
  }
  change(ans, -1);
  return true;
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
    b[i] = r[i] - r[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    cin >> d[i] >> s[i] >> t[i];
  }
  int l = 1, r = m, ans = -1;
  bool f = false;
  if (check(r)) {
    cout << 0;
    return 0;
  }
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) ans = mid, f = true, l = mid + 1;
    else r = mid - 1;
  }
  if (!f) cout << "-1\n1";
  else if (ans > 0) {
    cout << -1 << '\n' << ans + 1;
  } else cout << 0;
  return 0;
}
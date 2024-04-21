#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200001];

void solve() {
  int n;
  cin >> n;
  deque<int> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    q.push_back(a[i]);
  }
  sort(q.begin(), q.end());
  int ans = 0, x = 0;
  while (q.size() > 1) {
    if (x + q.front() < q.back()) {
      x += q.front();
      ans += q.front();
      q.pop_front();
    } else if (x + q.front() == q.back()) {
      x = 0;
      ans += q.front() + 1;
      q.pop_front();
      q.pop_back();
    } else {
      q.front() = x + q.front() - q.back();
      // 3 10 9
      ans += q.back() - x + 1;
      x = 0;
      q.pop_back();
    }
  }
  if (!q.empty()) {
    // 8 4 + 1
    // 9 4 + 1 + 1

    // 2 6 5
    // 2 7 6
    // 0 6 4
    // 3 6 5
    ans -= x;
    // 倒退法，神来之笔
    // 顺便 gdb 中间变量输出在熟练后确实更方便
    x += q.back();
    if (x == 1) ans += 1;
    else if (x & 1) {
      ans += x / 2 + 2;
    } else {
      ans += x / 2 + 1;
    }
  }

  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
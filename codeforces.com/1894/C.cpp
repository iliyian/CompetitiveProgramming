#include <bits/stdc++.h>
using namespace std;

int a[200001];
bitset<200001> vis;

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  bool ok = true;
  int cur = n;
  vis.reset();
  // 转移后的数永远在最后一个
  for (int i = 1; i <= k; i++) {
    if (a[cur] <= n) {
      if (vis[cur]) break;
      vis[cur] = true;
      cur = ((cur - a[cur]) % n + n) % n;
      if (cur == 0) cur = n;
    } else {
      ok = false;
      break;
    }
  }
  cout << (ok ? "Yes" : "No") << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}

/*
6
5 3
4 3 3 2 3
3 100
7 2 1
5 5
6 1 1 1 1
1 1000000000
1
8 48
9 10 11 12 13 14 15 8
2 1
1 42

Yes
Yes
No
Yes
Yes
No
*/

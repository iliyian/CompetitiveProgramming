#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n;
  string str;
  cin >> n >> str;
  int x = 0, y = 0;
  vector<int> a(n);
  vector<int> ans(n + 1);

  for (int i = 0; i < n; i++) {
    if (str[i] == 'N') a[i] = 0;
    if (str[i] == 'E') a[i] = 1;
    if (str[i] == 'S') a[i] = 2;
    if (str[i] == 'W') a[i] = 3;
    x += dx[a[i]], y += dy[a[i]];
  }
  if (x % 2 || y % 2) {
    cout << "NO\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if ()
    }
  }

  for (int i = 0; i < n; i++) {
    cout << (ans[i] == 1 ? "R" : "H");
  }
  cout << '\n';
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
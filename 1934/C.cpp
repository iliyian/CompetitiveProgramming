// date: 2024-03-03 12:21:44
// tag: 
// ce: redeclaration
// ILE: 漏一处cout.flush
// ILE: 漏一处cout.flush
// WA: 计算位置的变量用混

#include <bits/stdc++.h>
#define int long long
using namespace std;

int ask(int x, int y) {
  cout << "? " << x << " " << y << '\n';
  cout.flush();
  int ans;
  cin >> ans;
  return ans;
}


void solve() {
  int n, m;
  cin >> n >> m;
  int d1 = ask(1, 1); // x+y-2
  int d2 = ask(1, m); // x-1+m-y=d2,
  int d3 = ask(n, 1); // n-x+y-1=d3
  int x1 = (d1 + d2 + 3 - m) / 2;
  int y1 = d1 + 2 - x1;
  int x2 = (d1 - d3 + 1 + n) / 2;
  int y2 = d1 + 2 - x2;

  if (x1 >= 1 && x1 <= n && y1 >= 1 && y2 <= m && ask(x1, y1) == 0) cout << "! " << x1 << ' ' << y1 << '\n';
  else cout << "! " << x2 << ' ' << y2 << '\n';
  cout.flush();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}
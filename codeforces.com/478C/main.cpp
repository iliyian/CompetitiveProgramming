#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans, c[3];

int dfs(int a, int b) {
  if (a < b) swap(a, b);
  if (b <= 1) return 1;
  return 1 + dfs(a - 2, b - 1);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  // freopen("data.in", "r", stdin);
  cin >> c[0] >> c[1] >> c[2];
  sort(c, c + 3);
  if ((c[0] + c[1]) * 2 <= c[2]) {
    cout << c[1] + c[0];
  } else {
    cout << (c[0] + c[1] + c[2]) / 3;
  }

  return 0;
}
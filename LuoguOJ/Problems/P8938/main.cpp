#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  int n, m;
  cin >> n >> m;

  double l = -1, r = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    // if (a == 1) continue;
    l = max(l, m * 1.0 / i / a);
    r = min(r, m * 1.0 / (a - 1) / i);
  }
  if (r == 0x3f3f3f3f) cout << "xiaogougege";
  else if (r <= l) cout << 0;
  else cout << int(ceil(r) - 1 - ceil(l)) + 1;
  return 0;
}
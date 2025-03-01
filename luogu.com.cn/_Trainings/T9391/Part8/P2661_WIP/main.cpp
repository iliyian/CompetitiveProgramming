#include <bits/stdc++.h>
using namespace std;

array<int, 200010> f{}, d{};

int find(int x) {
  if (f[x] != x) {
    d[x] += d[f[x]];
    f[x] = find(f[x]);
  }
  return f[x];
}

int ans = 1 << 30;

void check(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) f[fx] = fy, d[x] = d[y] + 1;
  else ans = min(ans, d[x] + d[y] + 1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) f[i] = i; // 我是我爸爸
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    check(i, a);
  }
  cout << ans;
  return 0;
}
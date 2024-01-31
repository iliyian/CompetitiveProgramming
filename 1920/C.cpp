// date: 2024/01/30 21:19:25
// tag: 关键在于将同余转化成差值，再转化成因子，再转化成gcd
// 所以在批量同余和gcd间直接构建联系

#include <bits/stdc++.h>
#define N 200005
using namespace std;

vector<vector<int>> fac(N);

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int ans = 0;
  for (int k : fac[n]) {
    int g = 0;
    for (int i = 1; i + k <= n; i++)
      g = gcd(g, abs(a[i + k] - a[i]));
    ans += g != 1;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  for (int i = 1; i < N; i++)
    for (int j = i; j < N; j += i)
      fac[j].push_back(i);

  int _; cin >> _;
  while (_--) solve();
}
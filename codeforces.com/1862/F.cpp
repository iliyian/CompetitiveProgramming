#include <bits/stdc++.h>
#define N 1000001
using namespace std;

void solve() {
  int a, b, n, sum = 0;
  cin >> a >> b >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sum += x;
  }
  bitset<N> vis;
  int ans = 0;
  for (int i = 0; i < N; i++) {

  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}
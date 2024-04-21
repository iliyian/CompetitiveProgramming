#include <bits/stdc++.h>
using namespace std;

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

void solve() {
  int n;
  cin >> n;
  for ()
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
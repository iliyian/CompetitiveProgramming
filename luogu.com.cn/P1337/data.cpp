#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(random_device{}());

int rand(int l, int r) {
  int len = r - l + 1;
  return rnd() % len + l;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "w", stdout);
  int n = 10000;
  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    cout << rand(-10000, 10000) << ' '
      << rand(-10000, 10000) << ' '
      << rand(0, 1000) << '\n';
  }
  return 0;
}
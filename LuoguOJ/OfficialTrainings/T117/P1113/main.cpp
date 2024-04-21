#include <bits/stdc++.h>
using namespace std;

void write(int x, int m) {
  if (x >= m)
    write(x / m, m);
  int rest = x % m;
  if (rest < 10) cout << rest;
  else cout << char(rest - 10 + 'A');
}

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  string raw;
  cin >> n >> raw >> m;
  int t = 1, mid = 0;
  while (!raw.empty()) {
    int num = 0;
    if (n > 10 && raw.back() >= 'A') {
      num += raw.back() - 'A' + 10;
    } else num += raw.back() - '0';
    mid += num * t;
    t *= n;
    raw.pop_back();
  }
  write(mid, m);
  return 0;
}
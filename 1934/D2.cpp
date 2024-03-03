// date: 2024-03-03 14:05:34
// tag: 这题tmd做不了，变成classic了

#include <bits/stdc++.h>
#define int long long
using namespace std;

int count(int n) {
  if (n == 0) return 0;
  return count(n >> 1ll) + (n & 1);
}

int brk(int x) {
  for (int i = 62; i >= 0; i--) {
    if ((x >> i) & 1ll) {
      return 1 << 1ll;
    }
  }
  return -1;
}

void solve() {
  int n;
  cin >> n;
  int c = count(n);
  int s = 0;
  if (c % 2 == 0) {
    cout << "first" << '\n';
    int x = brk(n);
    cout << x << ' ' << (x ^ n) << '\n';
    cout.flush();  
    return;
  } else {
    cout << "second" << '\n';
    cout.flush();
    return;
  }
  while (true) {
    int p1, p2;
    cin >> p1 >> p2;
    if (p1 == 0 && p2 == 0) {
      return;
    }
    if (count(p1) % 2) {
      n = p1;
    } else {
      n = p2;
    }
    int x = brk(n);
    cout << x << ' ' << (x ^ n) << '\n';
    cout.flush();
    return;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D2.in", "r", stdin);
  freopen("D2.out", "w", stdout);

  int _;
  cin >> _;

  string a, b;
  cin >> a >> b;
  while (_--) {
    solve();
  }

  return 0;
}
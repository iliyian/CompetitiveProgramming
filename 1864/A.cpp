#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y, len;
  cin >> x >> y >> len;
  deque<int> a;
  for (int i = 0; i < len; i++)
    a.push_front(y - i * (i + 1) / 2);
  if (a.front() < x) cout << "-1\n";
  else {
    cout << x << ' ';
    for (int i = 1; i < len; i++)
      cout << a[i] << " \n"[i == len - 1];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}
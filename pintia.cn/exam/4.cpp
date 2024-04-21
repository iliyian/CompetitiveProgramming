#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int x;
    if (str == "push") {
      cin >> x, q.push(x);
    } else if (str == "pop") {
      q.pop();
    } else if (str == "empty") {
      cout << (q.empty() ? "YES" : "NO") << '\n';
    } else {
      cout << q.front() << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("4.in", "r", stdin);
  freopen("4.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}
#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  vector<int> a(n), b;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (b.empty() || b.back() < a[i]) b.push_back(a[i]);
    else *upper_bound(b.begin(), b.end(), a[i]) = a[i];
  }
  cout << b.size() << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("3.in", "r", stdin);
  freopen("3.out", "w", stdout);
  while (cin >> n) solve();
}
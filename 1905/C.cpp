#include <bits/stdc++.h>
#define N 100005
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<int> v;
  for (int i = n - 1; i >= 0; i--)
    if (v.empty() || str[i] >= str[v.back()])
      v.push_back(i);
  int j = 0;
  reverse(v.begin(), v.end());
  while (j < v.size() && str[v[0]] == str[v[j]]) {
    j++;
  }
  for (int i = 0; i < v.size() - i - 1; i++) {
    swap(str[v[i]], str[v[v.size() - i - 1]]);
  }
  if (is_sorted(str.begin(), str.end())) {
    cout << v.size() - j << '\n';
  } else {
    cout << -1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}
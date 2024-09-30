#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> ans;
  for (int i = n; i >= n - k + 1; i--)
    ans.push_back(i);
  for (int i = 1; i <= n - k; i++)
    ans.push_back(i);
  reverse(ans.begin(), ans.end());
  for (auto i : ans)
    cout << i << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}
// date: 2023/11/24
// tag: 正难则反

#include <bits/stdc++.h>
#define N 200001
using namespace std;

bitset<N> ans;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int eq = 0, neq = 0;
  for (int i = 0; i < str.size() / 2; i++) {
    int l = i, r = str.size() - i - 1;
    if (str[l] == str[r]) eq++;
    else neq++;
  }
  ans.reset();
  for (int i = 0; i <= eq; i++) {
    ans[neq + i * 2] = 1;
    if (n & 1) ans[neq + i * 2 + 1] = 1;
  }
  for (int i = 0; i <= str.size(); i++)
    cout << ans[i];
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
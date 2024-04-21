#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int cnt[30];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < str.size(); i++)
    cnt[str[i] - 'A' + 1]++;
  int ans = 0;
  for (int i = 1; i <= 26; i++)
    ans += (cnt[i] >= i);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}
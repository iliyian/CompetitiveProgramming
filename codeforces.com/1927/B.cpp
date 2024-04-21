#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  char cur = 'a';
  vector<int> cnt(27);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      cout << char(cur);
      cnt[cur - 'a'] = 1;
      cur++;
    } else {
      for (int i = 0; i < 26; i++) {
        if (cnt[i] == x) {
          cnt[i]++;
          cout << char(i + 'a');
          break;
        }
      }
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}
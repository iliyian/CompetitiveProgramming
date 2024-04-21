#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  int bcnt = 0;
  for (int i = 0; i < n; i++)
    bcnt += str[i] == 'B';
  if (bcnt == k)
    cout << 0 << '\n';
  else if (bcnt > k) {
    bcnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (bcnt == k) {
        cout << "1\n" << i + 1 << " A\n";
        return;
      }
      bcnt += str[i] == 'B';
    }
  } else {
    int acnt = 0;
    for (int i = 0; i < n; i++) {
      acnt += str[i] == 'A';
      if (acnt + bcnt == k) {
        cout << "1\n" << i + 1 << " B\n";
        return;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

vector<bool> ok(N);

bool check(int n) {
  string str = to_string(n);
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != '1' && str[i] != '0') {
      return false;
    }
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  cout << (ok[n] ? "YES" : "NO") << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  for (int i = 1; i <= 100000; i++) {
    if (check(i)) {
      ok[i] = true;
    } else {
      for (int j = 1; j * j <= i; j++) {
        if (i % j == 0) {
          if ((ok[j] || check(j)) && (ok[i / j] || check(i / j))) {
            ok[j] = ok[i / j] = ok[i] = true;
          }
        }
      }
    }
  }

  while (_--) {
    solve();
  }

  return 0;
}
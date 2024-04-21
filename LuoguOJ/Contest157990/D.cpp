#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int k;
  cin >> k;
  vector<int> ans;
  for (int a = 1; a <= 9; a++) {
    for (int b = 0; b <= 9; b++) {
      for (int c = 0; c <= 9; c++) {
        if ((a * 10 + b) % k == 0 && (b * 10 + c) % k == 0 && (a * 100 + b * 10 + c) % k == 0) {
          ans.push_back(a * 100 + b * 10 + c); 
        }
      }
    }
  }
  if (ans.empty()) {
    cout << "None!";
  } else {
    for (auto i : ans) {
      cout << i << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
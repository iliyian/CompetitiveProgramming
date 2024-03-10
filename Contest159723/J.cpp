#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("J.in", "r", stdin);
  freopen("J.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  vector<string> com(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> com[i];
  }
  for (int i = 1; i <= q; i++) {
    string str;
    cin >> str;
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      int p = str.find(com[j]);
      if (p != string::npos) {
        cnt++;
      }
    }
    if (cnt == 1) {
      cout << "Yes, Commander\n";
    } else {
      cout << "No, Commander\n";
    }
  }

  return 0;
}
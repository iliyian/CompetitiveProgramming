#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] == 'B') i += k - 1, ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}
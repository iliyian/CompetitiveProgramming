#include <bits/stdc++.h>
using namespace std;

int cnt[27];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < str.size(); i++) {
      cnt[str[i] - 'a']++;
    }
    int f = 0;
    for (int i = 0; i < 27; i++)
      if (cnt[i] & 1)
        f++;
    if (f > k + 1) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
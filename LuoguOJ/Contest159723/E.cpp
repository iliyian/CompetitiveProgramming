#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  string str;
  cin >> n >> str;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cnt[str[i] - '0']++;
  }
  if (cnt[2] == cnt[0] && 
      cnt[2] == cnt[1] &&
      cnt[2] == cnt[4] && cnt[2] > 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
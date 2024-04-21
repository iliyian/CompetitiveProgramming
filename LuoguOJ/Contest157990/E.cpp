// date: 2024/02/16 20:25:05
// tag: tmd，由于取最高，做到后来做得没意义了，tmd，#10死活不过，
// tmd，为什么没有split啊艹

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  string str;
  cin >> n >> m >> str;
  int pos = str.find('1');
  int len = pos;
  bool f = false;
  while (pos != str.npos) {
    int nxt = str.find('1', pos + 1);
    if (nxt == str.npos) break;
    if (nxt - pos - 1 < len || len > n) {
      cout << "No\n";
      return;
    } else {
      len = nxt - pos - 1;
    }
    pos = nxt;
    f = true;
  }
  int l = str.length() - 1 - pos;
  if (l > n || len > n || f && l > len) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
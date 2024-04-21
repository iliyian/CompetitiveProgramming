#include <bits/stdc++.h>
using namespace std;

int a[101], b[101];
bitset<101> vis;

void solve() {
  int n;
  cin >> n;
  map<int, int> freq;
  int can = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (++freq[a[i]] == 2)
      can++;
  }
  if (can < 2) {
    cout << -1 << '\n';
    return;
  }

  int pos2 = 0, pos3 = 0;
  for (auto [v, f] : freq) {
    if (f >= 2) {
      if (pos2 == 0) pos2 = v;
      else {pos3 = v; break;}
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == pos2) {
      cout << 2 << ' ';
      pos2 = 0;
    } else if (a[i] == pos3) {
      cout << 3 << ' ';
      pos3 = 0;
    } else cout << 1 << ' ';
  }
  cout << '\n';

  // memset(b, 0, sizeof(b));
  // vis.reset();
  // for (int i = 0; i < n; i++)
  //   cin >> a[i], b[i] = 1;
  // int cnt = 0;
  // for (int i = 0; i < n; i++) {
  //   if (vis[i]) continue;
  //   for (int j = 0; j < n; j++) {
  //     if (a[i] == a[j] && i != j) {
  //       vis[i] = vis[j] = true;
  //       if (cnt == 0) {
  //         b[i] = 2;
  //       } else if (cnt == 1) {
  //         b[i] = 3;
  //       } else if (cnt == 2) {
  //         b[i] = 2;
  //       }
  //     }
  //   }
  //   if (b[i] > 1) cnt++;
  // }
  // if (cnt == 1 || cnt == 0) {
  //   cout << "-1\n";
  //   return;
  // }
  // for (int i = 0; i < n; i++)
  //   cout << b[i] << ' ';
  // cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
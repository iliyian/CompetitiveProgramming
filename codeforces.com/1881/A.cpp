#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int _; cin >> _;
  while (_--) {
    int n, m;
    string x, s;
    cin >> n >> m >> x >> s;
    int t = 0, pos = 0;
    while ((pos = x.find(s)) == string::npos && x.size() < 200) {
      x.append(x);
      t++;
    }
    if (pos == string::npos) cout << -1 <<'\n';
    else cout << t << '\n';
  }
}
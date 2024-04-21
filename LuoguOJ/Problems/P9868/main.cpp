#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  vector<string> v(n), w(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sort(v[i].begin(), v[i].end());
    for (auto it = v[i].rbegin(); it != v[i].rend(); it++)
      w[i].push_back(*it);
  }
  sort(w.begin(), w.end());
  for (int i = 0; i < n; i++) {
    bool f = true;
    if (v[i] <= w.front()) {
      cout << 1;
    } else cout << 0;
    // for (int j = 0; j < n; j++) {
    //   if (j == i) continue;
    //   reverse(v[j].begin(), v[j].end());
    //   if (v[i] > v[j]) f = false;
    //   reverse(g[j])
    // }
    // cout << int(f);
  }
  return 0;
}
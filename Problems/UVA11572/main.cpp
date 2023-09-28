#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  queue<int> q;
  unordered_set<int> s;
  int ans = -1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    while (s.count(a)) {
      s.erase(q.front());
      q.pop();
    }
    s.insert(a);
    q.push(a);
    ans = max(ans, int(q.size()));
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
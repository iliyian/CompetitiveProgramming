#include <bits/stdc++.h>
using namespace std;

set<int, greater<int>> s;
int cnt[601];

int main() {
  freopen("data.in", "r", stdin);
  int n, w;
  memset(cnt, 0, sizeof(cnt));
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    s.insert(x);
    cnt[x]++;
    int tgt = max(1, int(i * w / 100.0)), now = 0, ans;
    for (auto it = s.begin(); it != s.end(); it++) {
      now += cnt[*it];
      if (now >= tgt) {
        ans = *it;
        break;
      }
    }
    cout << ans << ' ';
  }
  return 0;
}
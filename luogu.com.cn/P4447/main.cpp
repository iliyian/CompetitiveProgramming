// 鬼知道我调了多久

#include <bits/stdc++.h>
using namespace std;

int a[100000], n;

struct Node {
  int len, tail;
  bool operator < (const Node &b) const {
    if (tail != b.tail) return tail < b.tail;
    return len < b.len;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  multiset<Node> s;

  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    auto it = s.lower_bound({-1, a[i] - 1});
    if (s.empty() || it == s.end()) {
      s.insert({1, a[i]});
      continue;
    }
    if (it->tail != a[i] - 1) {
      s.insert({1, a[i]});
      continue;
    }
    
    int len = it->len, tail = it->tail;
    s.erase(it);
    s.insert({len + 1, tail + 1});
  }
  for (auto &i : s)
    ans = min(ans, i.len);

  cout << ans;

  return 0;
}
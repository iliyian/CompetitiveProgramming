// 开心，一次过

#include <bits/stdc++.h>
using namespace std;

struct Ship {
  int t;
  vector<int> v;
};

queue<Ship> q;

map<int, int> m;

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t, k;
    cin >> t >> k;
    Ship s = {t};
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      m[x]++;
      s.v.push_back(x);
    }
    q.push(s);

    while (q.front().t <= t - 86400) {
      for (auto x : q.front().v) {
        --m[x];
        if (!m[x]) m.erase(x);
      }
      q.pop();
    }

    cout << m.size() << '\n';
  }
  return 0;
}
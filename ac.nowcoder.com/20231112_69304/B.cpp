#include <bits/stdc++.h>
using namespace std;

struct Stu {
  int id, v;
  bool operator < (const Stu &b) const {
    if (v == b.v) return id < b.id;
    return v > b.v;
  }
} stus[1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<Stu>> gens(m + 1);
  for (int i = 1; i <= n; i++) {
    int num, v;
    cin >> num >> v;
    gens[num].push_back({i, v});
  }
  for (int i = 1; i <= m; i++) {
    if (!gens[i].size())
      cout << -1 << '\n';
    else {
      sort(gens[i].begin(), gens[i].end());
      for (auto &stu : gens[i])
        cout << stu.id << ' ';
      cout << '\n';
    }
  }
  return 0;
}
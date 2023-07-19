#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> farmers;

int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  farmers.reserve(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    farmers.push_back(make_pair(a, b));
  }
  sort(farmers.begin(), farmers.end());
  for (int i = 0; i < m && n; i++) {
    int need = min(farmers[i].second, n);
    ans += need * farmers[i].first;
    n -= need;
  }
  cout << ans;
  return 0;
}
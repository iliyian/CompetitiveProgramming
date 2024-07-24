#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;

  std::string a, b;
  std::cin >> a >> b;

  std::vector<std::vector<int>> ca(26), cb(26);

  for (int i = 0; i < n; i++) {
    ca[a[i] - 'a'].push_back(i);
    cb[b[i] - 'a'].push_back(i);
  }

  for (int i = 0; i < 26; i++) {
    for ()
  }

  return 0;
}
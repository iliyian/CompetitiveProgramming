#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n;
  std::cin >> n;
  std::map<std::string, int> score;
  std::vector<std::pair<std::string, int>> story(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> story[i].first >> story[i].second;
    score[story[i].first] += story[i].second;
  }
  int mx = 0;
  for (auto &[k, v] : score) {
    mx = std::max(mx, v);
  }
  std::set<std::string> cand;
  for (auto &[k, v] : score) {
    if (v == mx) {
      cand.insert(k);
    }
  }
  if (cand.size() == 1) {
    std::cout << *cand.begin() << '\n';
    return 0;
  }
  score.clear();
  for (int i = 1; i <= n; i++) {
    auto &[name, ach] = story[i];
    score[name] += ach;
    if (cand.contains(name) && score[name] >= mx) {
      std::cout << name << '\n';
      return 0;
    }
  }

  return 0;
}
#include <bits/stdc++.h>
#define ac "accepted"
#define re "rejected"
using namespace std;

struct Sub {
  std::string team, result;
  char problem;
  int t, id;
};

void solve() {
  int m;
  std::cin >> m;
  std::map<std::string, int> board;
  std::set<std::string> ans;
  std::vector<Sub> subs(m + 1);
  std::vector<std::map<std::string, std::vector<int>>> trys(26);
  std::set<std::string> solved;
  for (int i = 1; i <= m; i++) {
    std::cin >> subs[i].team >> subs[i].problem >>
        subs[i].t >> subs[i].result;
    subs[i].id = i;
    trys[subs[i].problem - 'A'][subs[i].team].push_back(i);
    if (subs[i].result == ac) {
      solved.insert(subs[i].team);
    }
  }
  int n = std::min<int>((solved.size() + 9) / 10, 35);
  for (auto &m : trys) {
    // for (auto ) {

    // }
  }
  for (int i = 1; i <= m; i++) {
    auto &sub = subs[i];
    if (sub.result == ac) {
      
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
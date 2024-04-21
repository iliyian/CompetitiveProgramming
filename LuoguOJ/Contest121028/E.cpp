#include <bits/stdc++.h>
using namespace std;

map<int, int> scores;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    scores[e] = -1;
  }
  for (int i = 0; i < m; i++) {
    int p, s;
    cin >> p >> s;
    if (scores.find(p) != scores.end()) {
      scores[p] = s;
    }
  }
  int disq = 0, empty = 0;
  for (auto &score : scores) {
    if (score.second == -1) empty++;
    if (score.second < 60) disq++;
  }
  cout << empty << '\n' << disq;
  return 0;
}
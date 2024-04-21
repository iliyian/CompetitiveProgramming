#include <bits/stdc++.h>
using namespace std;

map<string, int> results;
map<int, string> names;
map<int, int> scores;

int main() {
  freopen("data.in", "r", stdin);
  int n, maxs = -1;
  string winner;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name;
    int s;
    cin >> name >> s;
    results[name] += s;
    names[i] = name, scores[i] = s;
  }
  string owner;
  for (auto p : results) {
    if (p.second > maxs) owner = p.first, maxs = p.second;
  }
  results.clear();
  for (int i = 0; i < n; i++) {
    results[names[i]] += scores[i];
    if (results[names[i]] == maxs && owner == names[i]) {
      cout << names[i];
      return 0;
    }
  }
  return 0;
}
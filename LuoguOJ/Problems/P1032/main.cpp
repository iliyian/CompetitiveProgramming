#include <bits/stdc++.h>
using namespace std;

struct Node {
  string str;
  int step;
};

queue<Node> q;
vector<pair<string, string>> v;
set<string> found;

int main() {
  freopen("data.in", "r", stdin);
  string S, T;
  cin >> S >> T;
  string a, b;
  while (cin >> a >> b) {
    v.push_back({a, b});
  }
  q.push({S, 0});
  while (!q.empty()) {
    string str = q.front().str;
    int step = q.front().step; q.pop();
    if (step > 10 || found.count(str)) continue;
    found.insert(str);
    
    if (str == T) {
      cout << step;
      return 0;
    }

    string raw = str;
    for (int i = 0; i < v.size(); i++) {
      int pos = str.find(v[i].first, 0);
      while (pos != str.npos) {
        string temp = str.replace(pos, v[i].first.size(), v[i].second);
        q.push({temp, step + 1});
        str = raw;
        pos = str.find(v[i].first, pos + v[i].first.size());
      }
    }

  }
  cout << "NO ANSWER!";
  return 0;
}
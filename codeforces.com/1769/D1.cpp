#include <bits/stdc++.h>
#define int long long
using namespace std;

string num = "06789TJQKA0";
// CDSH

map<char, int> pos = {
    {'6', 1}, {'7', 2}, {'8', 3}, {'9', 4}, {'T', 5},
    {'J', 6}, {'Q', 7}, {'K', 8}, {'A', 9},
};

pair<char, char> req(pair<char, char> card) {
  int idx = pos[card.first];
  if (idx <= 3) {
    return {num[idx + 1], card.second};
  } else if (idx == 4) {
    return {'0', '0'};
  } else {
    return {num[idx - 1], card.second};
  }
};

hash<string> h;

map<int, map<int, int>> vis;

bool dfs(const string &a, const string &b) {
  int &res = vis[h(a)][h(b)];
  if (res) {
    return res == -1 ? false : true;
  }

  bool f = false;
  for (int i = 0; i < a.size(); i += 2) {
    auto card = pair{a[i], a[i + 1]};
    auto p = req(card);
    string ps = {p.first, p.second};
    if (a[i] == '9' ||
        b.find(ps) == string::npos && a.find(ps) == string::npos) {
      if (a.size() == 2) {
        res = 1;
        return true;
      }
      f = true;
      auto tmp = a;
      tmp.erase(i, 2);
      if (!dfs(b, tmp)) {
        res = 1;
        return true;
      }
    }
  }
  if (!f) {
    res = -1;
    return false;
  }
  res = (!dfs(b, a) ? 1 : -1);
  return res == 1 ? true : false;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string a, b;

  for (int i = 1; i <= 18; i++) {
    string card;
    cin >> card;
    a += card;
  }

  for (int i = 1; i <= 18; i++) {
    string card;
    cin >> card;
    b += card;
  }

  cout << (dfs(a, b) ? "Alice" : "Bob") << '\n';

  return 0;
}
// date: 2024-09-13 22:06:26
// tag: 集合论，逻辑，不一定诚实的交互

#include <bits/stdc++.h>
#define int long long

bool ask(std::vector<int> &v) {
  std::cout << "? " << v.size() << ' ';
  for (int i : v) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  std::string ans;
  std::cin >> ans;
  return ans == "YES";
}

bool ask(int x) {
  std::vector<int> tmp = {x};
  return ask(tmp);
}

bool answer(int x) {
  std::cout << "! " << x << std::endl;
  std::string ans;
  std::cin >> ans;
  return ans == ":)";
}

signed main() {
  int n;
  std::cin >> n;
  std::vector<int> cur(n);
  if (n == 1) {
    answer(1);
    return 0;
  }
  if (n == 2) {
    answer(1) || answer(2);
    return 0;
  }
  std::iota(cur.begin(), cur.end(), 1);
  for (int i = 0; i < 82; i += 2) {
    if (cur.size() <= 3) break;
    std::vector<int> s, t, nxt;
    for (int j = 0; j < cur.size() / 4 * 4; j++) {
      if (j % 4 == 0) s.push_back(cur[j]);
      if (j % 4 == 1) s.push_back(cur[j]), t.push_back(cur[j]);
      if (j % 4 == 2) t.push_back(cur[j]);
    }
    bool x = ask(s), y = ask(t);
    std::vector<int> ok = {0, 0, 0, 0};
    if (x && y) {
      ok = {1, 1, 1, 0};
    } else if (x && !y) {
      ok = {1, 1, 0, 1};
    } else if (!x && y) {
      ok = {0, 1, 1, 1};
    } else {
      ok = {1, 0, 1, 1};
    }
    for (int j = 0; j < cur.size(); j++) {
      int pos = j % 4;
      if (j >= cur.size() / 4 * 4) pos = 3;
      if (ok[pos]) nxt.push_back(cur[j]);
    }
    cur = nxt;
  }
  std::pair<int, int> lst;
  if (!ask(cur[0]) && !ask(cur[0])) {
    lst = {cur[1], cur[2]};
  } else if (ask(cur[1])) { // 至少有一个是对的
    lst = {cur[0], cur[1]};
  } else {
    lst = {cur[0], cur[2]};
  }
  answer(lst.first) || answer(lst.second);
  return 0;
}
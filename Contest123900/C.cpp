#include <bits/stdc++.h>
using namespace std;

deque<string> wating, playing;
set<string> inwating, inplaying;

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, cnt = 0;
  string op, name;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> op;
    if (op == "start") {
      bool f = true;
      string p;
      if (cnt) {
        while (!playing.empty()) {
          p = playing.front(); playing.pop_front();
          wating.push_back(p);
        }
      }
      for (int i = 0; i < 2 && !wating.empty(); i++) {
        f = false;
        p = wating.front();
        cout << p << ' ';
        wating.pop_front();
        playing.push_back(p);
      }
      if (f && playing.empty()) {
        cout << "Error";
      }
      cnt++;
    } else if (op == "arrive") {
      cin >> name;
      if (find(wating.begin(), wating.end(), name) != wating.end() || find(playing.begin(), playing.end(), name) != playing.end()) {
        cout << "Error";
      } else {
        wating.push_back(name);
        cout << "OK";
      }
    } else {
      cin >> name;
      auto wtit = find(wating.begin(), wating.end(), name);
      if (wtit != wating.end() && find(playing.begin(), playing.end(), name) == playing.end()) {
        wating.erase(wtit);
        cout << "OK";
      } else {
        cout << "Error";
      }
    }
    cout << '\n';
  }
  return 0;
}
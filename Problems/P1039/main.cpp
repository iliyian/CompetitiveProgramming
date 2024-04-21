#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int m, n, p;
  cin >> m >> n >> p;
  map<string, int> id;
  vector<string> names(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> names[i];
    id[names[i]] = i;
  }
  vector sue(2, vector<vector<int>>(m + 1, vector<int>()));
  vector<string> day(m + 1);
  vector<string> convday = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  cin.get();
  for (int i = 1; i <= p; i++) {
    string pres;
    getline(cin, pres);
    if (pres == 'I am guilty.') {
      sue[1][i].push_back(i);
    } else if (pres == "I am not guilty.") {
      sue[0][i].push_back(i);
    } else {
      int pos = pres.find(' ');
      string name = pres.substr(0, pos);
      string after = pres.substr(pos, pres.size() - pos);

      pos2 = after.find(' ');
    }
  }

  vector<string> guilts;

  for (int g = 1; g <= m; g++) {
    for (int today = 1; today <= 7; today++) {
      bool f = true;
      vector<int> cfm;
      vector<int> status(m + 1, -1);

      chk:
      if (!f) {
        continue;
      }

      for (auto i : sue[1][g]) {
        if (status[i] == -1) {
          status[i] = 0;
          cfm.push_back(i);
        } else if (status[i] == 1) {
          f = false;
          goto chk;
        }
      }

      for (auto i : sue[0][g]) {
        if (status[i] == -1) {
          status[i] = 1; // liar
          cfm.push_back(i);
        } else if (status[i] == 0) { // innocent
          f = false;
          goto chk;
        }
      }

      for (int i = 1; i <= m; i++) {
        if (i != g) {
          for (auto j : sue[1][i]) {
            if (status[j] == -1) {
              status[j] = 1;
              cfm.push_back(j);
            } else if (status[j] == 0) {
              f = false;
              goto chk;
            }
          }
        }
      }
    
      for (int i = 1; i <= m; i++) {
        if (!day[i].empty()) {
          bool sta = convday[today] != day[i];
          if (status[i] == -1) {
            status[i] = sta;
            cfm.push_back(i);
          } else if (status[i] == sta ^ 1) {
            f = false;
            goto chk;
          }
        }
      }

      int cntz, cnt1 = 0;
      for (int i = 1; i <= m; i++) {
        cnt1 += status[i] == 1;
        cntz += status[i] == -1;
      }

      if (cnt1 > n) {
        f = false;
        goto chk;
      }

      guilts.push_back(names[g]);
      break;
    }
  }
  if (guilts.size() >= 2) {
    cout << "Cannot Determine" << '\n';
  } else if (guilts.empty()) {
    cout << "Impossible" << '\n';
  } else {
    cout << guilts.front() << '\n';
  }

  return 0;
}
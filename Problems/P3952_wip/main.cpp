#include <bits/stdc++.h>
#define N 10000
using namespace std;

void solve() {
  int n, loop = 0;
  string O;
  cin >> n >> O;
  map<char, bool> vis;
  bool err = false;
  int maxloop = 0;
  while (n--) {
    char word;
    cin >> word;
    if (word == 'E') {
      loop--;
      continue;
    } else {
      loop++;
      char i;
      string x, y;
      cin >> i >> x;
      if (vis[i]) err = true;
      vis[i] = true;
      if (x == "n") {
        
      }      
    }
    maxloop = max(maxloop, loop);
  }
  if (loop || err) cout << "ERR" << '\n';
  
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
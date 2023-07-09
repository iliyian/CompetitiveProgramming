#include <iostream>
#include <string>
using namespace std;
string res;
int len, w, l;

bool endContest(int w, int l, int n) {
  // cout << "w=" << w << ",l=" << l << ",n=" << n << endl;
  if (w < l) {
    int t = w;
    w = l;
    l = t;
  }

  if (w < n) return false;
  if (w == n && l <= n-2) return true;
  if (w > n && w - l >= 2) return true;

  return false;
}

void gameWithin(int n) {
  w = l = 0;
  for (int i = 0; i < len; i++) {
      // cout << w << ":" << l << endl;
    // cout << "len=" << len << endl;

    w += res[i] == 'W';
    l += res[i] == 'L';
    if (endContest(w, l, n)) {
      // cout << "i=" << i << endl;
      cout << w << ":" << l << endl;
      w = l = 0;
    }
  }
  cout << w << ":" << l << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  bool endline = false;
  while (!endline && cin >> line) {
    endline = false;
    int len = line.size();
    for (int i = 0; i < len; i++) {
      if (line[i] == 'E') {
        endline = true;
        // cout << "line" << i << "=" << line[i] << endl;
        break;
      } else res += line[i];
    }
  }
  // cout << "res=" << res << endl;

  len = res.size();

  gameWithin(11);
  cout << endl;
  gameWithin(21);

  return 0;
}
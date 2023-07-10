#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
  string encrypted, raw;
  cin >> encrypted >> raw;
  int len = raw.size();
  char e2r[27], r2e[27];
  memset(e2r, 0, sizeof(e2r));
  memset(r2e, 0, sizeof(r2e));
  for (int i = 0; i < len; i++) {
    char e = encrypted[i], r = raw[i];
    if (e2r[e - 'A'] && e2r[e - 'A'] != r) {
      cout << "Failed";
      return 0;
    }
    if (r2e[r - 'A'] && r2e[r - 'A'] != e) {
      cout << "Failed";
      return 0;
    }
    e2r[e - 'A'] = r;
    r2e[r - 'A'] = e;
  }
  // bool allSame = true;
  for (int i = 0; i < 26; i++) {
    // if (e2r[i] != char(i+'A')) {
    //   allSame = false;
    //   cout << e2r[i] << ":" << char(i+'A') << endl;
    // }
    if (!e2r[i] || !r2e[i]) {
      cout << "Failed";
      return 0;
    }
  }
  // if (allSame) {
  //   cout << "Failed";
  //   return 0;
  // }

  string q;
  cin >> q;
  len = q.size();
  for (int i = 0; i < len; i++) {
    cout << e2r[q[i] - 'A'];
  }
  return 0;
}

/*
QWERTYUIOPLKJHGFDSAZXCVBNM
QWERTYUIOPLKJHGFDSAZXCVBNN
HIJACK
*/
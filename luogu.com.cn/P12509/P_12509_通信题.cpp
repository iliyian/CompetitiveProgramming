#include <iostream>
#include <string>
using namespace std;

int Alice(string S) {
  int x = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '1') {
      x ^= i + 1;
    }
  }
  return x;
}

int Bob(string T, int X) {
  int y = 0;
  for (int i = 0; i < T.size(); i++) {
    if (T[i] == '1') {
      y ^= i + 1;
    }
  }
  return X ^ y;
}

// int main() {
//     string s_str, t_str;
//     cin >> s_str >> t_str;
// 
//     int alice_val_x = Alice(s_str);
//     if (alice_val_x < 0 || alice_val_x >= (1 << 20)) {
//         cout << "Wrong Answer" << endl;
//         return 0;
//     }
// 
//     int bob_val_p = Bob(t_str, alice_val_x);
//     if (bob_val_p < 0 || bob_val_p > (int)s_str.size()) {
//         cout << "Wrong Answer" << endl;
//         return 0;
//     }
// 
//     if ((s_str == t_str && bob_val_p != 0) || (s_str != t_str && s_str[bob_val_p - 1] == t_str[bob_val_p - 1])) {
//         cout << "Wrong Answer" << endl;
//         return 0;
//     }
// 
//     cout << "Accepted" << endl;
//     return 0;
// }

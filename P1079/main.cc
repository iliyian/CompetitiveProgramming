#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// 这题怪感动的

char getBase(char ch) {
  return isupper(ch) ? 'A' : 'a';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string K, C;
  cin >> K >> C;

  int klen = K.size(), clen = C.size();
  for (int i = 0; i < clen; i++) {
    char k = K[i % klen], c = C[i];
    k -= getBase(k);
    c -= getBase(c);
    
    char m = c - k;
    if (m < 0) m += 26;

    m += getBase(C[i]);
    cout << m;
  }
  return 0;
}

/*
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm
*/
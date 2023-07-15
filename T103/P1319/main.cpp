#include <iostream>
using namespace std;

int main() {
  int N, count = 0;
  char c = '0';
  cin >> N;
  while (count < N * N) {
    int a;
    cin >> a;
    for (int i = 0; i < a; i++, count++) {
      if (count % N == 0 && count) cout << endl;
      cout << c;
    }
    c = c == '0' ? '1' : '0';
  }
  
  return 0;
}
/*
7 3 1 6 1 6 4 3 1 6 1 6 1 3 7
*/
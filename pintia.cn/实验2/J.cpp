#include <bits/stdc++.h>
using namespace std;

int cnt = 1, N;

void hanoi(char a, char b, char c, int n) {
  if (n > 0) {
    hanoi(a, c, b, n - 1);
    cout << n << ':' << a << "->" << c;
    if (++cnt != 1 << N)
      cout << "\n";
    hanoi(b, a, c, n - 1);
  }
}

int main() {
  cin >> N;
  if (N <= 0) cout << "Wrong Input.";
  else hanoi('X', 'Y', 'Z', N);
}
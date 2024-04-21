// 迫真找规律

#include <bits/stdc++.h>
using namespace std;

int n;

string a[] = {
  "ooo*o**--*",
  "o--*o**oo*",
  "o*o*o*--o*",
  "--o*o*o*o*"
};

void solve(int len) {
  if (len <= 3) {
    for (int i = 0; i < 4; i++) {
      cout << a[i];

      for (int j = 0; j < n - len - 1; j++)
        cout << "o*";
      cout << '\n';
    }
  } else {
    for (int i = 0; i < len; i++)
      cout << 'o';
    for (int i = 0; i < len; i++)
      cout << '*';
    cout << "--";
    for (int i = 0; i < n - len; i++)
      cout << "o*";
    cout << '\n';

    for (int i = 0; i < len - 1; i++)
      cout << 'o';
    cout << "--";
    for (int i = 0; i < len - 1; i++)
      cout << '*';
    for (int i = 0; i < n - len + 1; i++)
      cout << "o*";
    cout << '\n';

    solve(len - 1);
  }
}

int main() {
  cin >> n;
  solve(n);
  return 0;
}
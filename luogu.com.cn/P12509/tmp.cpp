#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int x = 0;
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == '1') {
        x ^= i + 1;
      }
    }
    std::cout << x << '\n';
    return 0;
}


/* ATTENTION!!! THIS IS THE BARRIER!!! */

#include <bits/stdc++.h>
using namespace std;
int main()
{
  string T;
  int X;
  int y = 0;
  for (int i = 0; i < T.size(); i++) {
    if (T[i] == '1') {
      y ^= i + 1;
    }
  }
  std::cout << (X ^ y) << '\n';
}

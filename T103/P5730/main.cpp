#include <string>
#include <iostream>
#include <array>
using namespace std;

array<string, 5> map{
  string("XXX..XXXXXXXX.XXXXXXXXXXXXXXXX"),
  string("X.X..X..X..XX.XX..X....XX.XX.X"),  
  string("X.X..XXXXXXXXXXXXXXXX..XXXXXXX"),
  string("X.X..XX....X..X..XX.X..XX.X..X"),
  string("XXX..XXXXXXX..XXXXXXX..XXXXXXX")
};

int main() {
  ios::sync_with_stdio(0);

  int n;
  string str;
  cin >> n >> str;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < str.size(); j++) {
      int num = str[j] - '0';
      cout << map[i].substr(3 * num, 3);
      if (j != str.size() - 1) cout << ".";
    }
    cout << endl;
  }
  return 0;
}
// array不能开十万个string

#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

bitset<100000> dir;
vector<string> people;

int n, m;

int advance(int idx, int way, int step) {
  int d = (dir[idx] != way ? 1 : -1);
  int t = idx + step * d;
  if (t < 0) t += n;
  if (t >= n) t -= n;
  return t;
}

int main() {
  cin >> n >> m;
  int d;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> d >> s;
    dir[i] = d ? true : false;
    people.push_back(s);
  }
  int idx = 0;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> d >> a;
    idx = advance(idx, d, a);
  }
  cout << people[idx];
  return 0;
}
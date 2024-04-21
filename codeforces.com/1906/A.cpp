#include <bits/stdc++.h>
using namespace std;

// int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
// int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
string a[3];

struct Node {
  char c;
  int x, y;
  bool operator < (const Node &b) {
    return c < b.c;
  }
};

vector<Node> v;

bool check(int x, int y) {
  if (abs(v[x].x - v[y].x) <= 1 && abs(v[x].y - v[y].y) <= 1)
    return true;
  return false;
}

int main() {
  // map<char, vector<pair<int, int>>> m;
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
      v.push_back({a[i][j], i, j});
    }
  }

  sort(v.begin(), v.end());
  vector<string> ans;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      for (int k = 0; k < 9; k++)
        if (i != j && i != k && j != k && check(i, j) && check(j, k)) {
          string temp;
          temp.push_back(v[i].c);
          temp.push_back(v[j].c);
          temp.push_back(v[k].c);
          ans.push_back(temp);
        }
  cout << *min_element(ans.begin(), ans.end());
}
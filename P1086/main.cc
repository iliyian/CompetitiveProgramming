#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int m, n, k, field[21][21];

struct Field {
  int x, y, n;
};
vector<Field> fields;

int cmp(const Field &a, const Field &b) {
  return a.n > b.n;
}

int getTime(const Field &a, const Field &b) {
  return abs(a.x - b.x) + abs(a.y - b.y) + 1;
}

int main() {
  scanf("%d %d %d", &m, &n, &k);
  if (!k) {
    printf("0");
    return 0;
  }
  
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++){
      Field f;
      scanf("%d", &f.n);
      f.x = i, f.y = j;
      fields.push_back(f);
    }
  
  sort(fields.begin(), fields.end(), cmp);

  int time = 1 + fields.front().x, sum = 0;

  if (fields.size() == 1) {
    if (time + fields.front().x + 2 <= k) 
      printf("%d", fields.front().n);
    else printf("0");
    return 0;
  }

  for (int i = 0; i < fields.size()-1; i++) {
    Field &f = fields[i];
    if (time + f.x + 2 > k) break;
    sum += f.n;
    time += getTime(fields[i], fields[i+1]);
    // time += abs(f.x-fields[i-1].x) + abs(f.y-fields[i-1].y) + 1;
  }

  printf("%d", sum);
  return 0;
}
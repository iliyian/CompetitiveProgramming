#include <cstdio>
#include <map>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (m.find(a) != m.end()) {
      m[a]++;
    } else {
      m[a] = 1;
    }
  }
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
    printf("%d %d\n", it->first, it->second);
  }
  return 0;
}
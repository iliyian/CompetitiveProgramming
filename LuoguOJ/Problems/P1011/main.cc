// 边界处理

#include <cstdio>

int fib(int n) {
  if (n == 1 || n == 2) return 1;
  return fib(n-1) + fib(n-2);
}

struct Count {
  int a, ucount;
  void print() {
    printf("a=%d, ucount=%d\n", a, ucount);
  }
};

void operator += (Count a, Count b){
  a.a += b.a;
  a.ucount += b.ucount;
}

Count operator + (Count a, Count b) {
  return Count{a.a + b.a, a.ucount + b.ucount};
}

Count operator - (Count a, Count b) {
  return Count{a.a - b.a, a.ucount - b.ucount};
}

int main() {
  int a, n, m, x;
  Count people[21], up[21], down[21];
  scanf("%d %d %d %d", &a, &n, &m, &x);

  // up[1] = a; down[1] = 0; p[1] = a;
  // up[2] = u; down[2] = u; p[2] = a;
  // up[3] = a+u; down[3] = u; p[3] = 2a;
  // up[4] = a+2u; down[4] = a+u; p[4] = 2a + u;
  // up[5] = 2a+3u; down[5] = a+2u; p[5] = 3a + 2u;
  // up[6] = 3a+5u; down[6] = 2a+3u; p[6] = 4a + 4u;

  people[1] = people[2] = {a, 0};
  up[1] = {a, 0}; up[2] = {0, 1};
  down[1] = {0, 0}; down[2] = {0, 1}; 

  for (int i = 3; i < n; i++) {
    up[i] = up[i-2] + up[i-1];
    down[i] = up[i-1];
    people[i] = people[i-1] + up[i] - down[i];
    // printf("people[%d]:", i);
    // people[i].print();
  }
  // printf("people[%d].a=\n", n, people[n].a);
  int u = (m - people[n-1].a) / people[n-1].ucount;
  // printf("u=%d\n", u);
  printf("%d", u * people[x].ucount + people[x].a);
  return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 注意，迭代器遍历可能慢于索引

struct Person {
  int k, s;
};

bool operator < (const Person &a, const Person &b) {
  if (a.s == b.s) return a.k < b.k;
  return a.s > b.s;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<Person> people;
  for (int i = 0; i < n; i++) {
    Person p;
    scanf("%d %d", &p.k, &p.s);
    people.push_back(p);
  }
  sort(people.begin(), people.end());
  int s = people[(int)(m * 1.5) - 1].s;
  int len = people.size();
  for (int i = len-1; i >= 0; i--) {
    if (people[i].s < s) people.pop_back();
  }
  printf("%d %d\n", s, people.size());
  for (int i = 0; i < people.size(); i++) {
    printf("%d %d\n", people[i].k, people[i].s);
  }
  return 0;
}

/*
6 3 
1000 90 
3239 88 
2390 95 
7231 84 
1005 95 
1001 88
*/
#include <bits/stdc++.h>
// using namespace std;

/*

note that sd differs greaterly between each tests

g++ file.cpp -o file.exe -g -std=c++20
std::sort average uses 2850.9ms, with sd of 23.2717
std::stable_sort average uses 2911.25ms, with sd of 21.5962
qsort average uses 1241.48ms, with sd of 10.3891

g++ file.cpp -o file.exe -g -std=c++20 -O2
std::sort average uses 518.94ms, with sd of 7.90373
std::stable_sort average uses 615.929ms, with sd of 8.72538
qsort average uses 898.068ms, with sd of 5.99048

g++ file.cpp -o file.exe -g -std=c++20 -O3
std::sort average uses 532.136ms, with sd of 9.15972
std::stable_sort average uses 648.953ms, with sd of 14.4061
qsort average uses 927.435ms, with sd of 13.9184

*/

typedef std::chrono::duration<double, std::milli> Dur;

std::mt19937 rd(std::random_device{}());

int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

std::pair<Dur, double> calc(const std::vector<Dur> &vec) {
  Dur mean = std::accumulate(vec.begin(), vec.end(), Dur(0)) / vec.size();
  auto sum = [&](const Dur &acc, const Dur &val) {
    return acc + Dur((mean - val).count() * (mean - val).count());
  };
  auto d = (std::accumulate(vec.begin(), vec.end(), Dur(0), sum) / vec.size()).count();
  return {mean, std::sqrt(d)};
};

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::vector<Dur> cnta, cntb, cntc;
  int n = 1e7, maxt = 10;

  std::vector<int> a(n), b(n), c(n);

  for (int t = 0; t < maxt; t++) {
    for (int i = 1; i <= n; i++) {
      a[i] = rd();
    }
    b = a, c = a;

    auto begin = std::chrono::high_resolution_clock::now();
    std::sort(a.begin(), a.end());
    auto end = std::chrono::high_resolution_clock::now();
    cnta.push_back(end - begin);

    begin = std::chrono::high_resolution_clock::now();
    std::stable_sort(b.begin(), b.end());
    end = std::chrono::high_resolution_clock::now();
    cntb.push_back(end - begin);

    begin = std::chrono::high_resolution_clock::now();
    qsort(&(*c.begin()), std::distance(c.begin(), c.end()), sizeof(int),
          cmpfunc);
    end = std::chrono::high_resolution_clock::now();
    cntc.push_back(end - begin);
  }

  std::cout << "std::sort average uses "
            << calc(cnta).first
            << ", with sd of "
            << calc(cnta).second << '\n';

  std::cout << "std::stable_sort average uses "
            << calc(cntb).first
            << ", with sd of "
            << calc(cntb).second << '\n';

  std::cout << "qsort average uses "
            << calc(cntc).first
            << ", with sd of "
            << calc(cntc).second << '\n';

  return 0;
}
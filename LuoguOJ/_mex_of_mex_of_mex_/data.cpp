#include <bits/stdc++.h>
#include <random>

std::mt19937 rd(std::random_device{}());

constexpr int N = 2e3;

int main(int argc, char **argv) {
  int n = N;
  if (argc > 1) {
    if (std::string(argv[1]) == "small") {
      if (argc > 2) n = atoi(argv[2]);
      for (int t = 1; t <= 2000; t++) {
        std::string filename = std::format("small/{:05}_{}.in", t, "small_bf");
        std::fstream fs(filename, std::ios::out);
        fs << n << '\n';
        for (int i = 1; i <= n; i++) {
          fs << std::max(0, std::min<int>(n, std::round(std::exponential_distribution<>{std::uniform_real_distribution<>{0,1}(rd)}(rd)))) << ' ';
        }
        fs << '\n';
      }
      return 0;
    }

    freopen("main.in", "w", stdout);
    n = atoi(argv[1]);
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << std::uniform_int_distribution<>{0, n}(rd) << ' ';
    }
    std::cout << '\n';
    return 0;
  }
  for (int t = 3; t <= 50; t++) {
    std::stringstream ss;
    std::string suf;

    if (t <= 5) {
      suf = "handmade";
    } else if (t <= 30) {
      suf = "uniform";
    } else if (t <= 40) {
      suf = "normal";
    } else {
      suf = "expo";
    }

    std::string filename = std::format("data/{:05}_{}.in", t, suf);
    std::fstream fs(filename, std::ios::out);

    if (t <= 5) {
      if (t == 3) {
        n = N;
        fs << n << '\n';
        for (int i = 1; i <= n; i++) {
          fs << i - 1 << ' ';
        }
      } else if (t == 4) {
        n = N;
        fs << n << '\n';
        for (int i = 1; i <= n; i++) {
          if (i != n) {
            fs << i - 1 << ' ';
          } else {
            fs << 0 << ' ';
          }
        }
      } else if (t == 5) {
        n = N;
        fs << n << '\n';
        for (int i = 1; i <= n; i++) {
          fs << std::min(n, (int)std::round(std::exponential_distribution<>{1}(rd))) << ' ';
        }
      }
      fs << '\n';
      continue;
    } else if (t == 6) {
      n = 1;
    } else if (t == 7) {
      n = 10;
    } else if (t == 8) {
      n = 100;
    } else if (t == 9) {
      n = 1000;
    } else {
      n = N;
    }
    fs << n << '\n';
    for (int i = 1; i <= n; i++) {
      int data;
      if (t <= 30) {
        data = std::uniform_int_distribution<>{0, n}(rd);
      } else if (t <= 40) {
        data = std::round(std::abs(std::normal_distribution<>{0, std::uniform_real_distribution<>{1, 50}(rd)}(rd)));
        data = std::max(0, std::min(n, data));
      } else {
        double lambda = std::uniform_real_distribution<>{0, 1}(rd);
        data = std::max(0, std::min(n, (int)std::round(std::exponential_distribution<>{lambda}(rd))));
      }
      fs << data << ' ';
    }
    fs << '\n';
  }
  return 0;
}
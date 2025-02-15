#include <bits/stdc++.h>
#define int long long

struct Stu {
  std::string id;
  int score, cnt;
  char sex;
  bool operator < (const Stu &b) const {
    return std::tie(id, score) < std::tie(b.id, b.score);
  }
};

std::string getLevel(int score) {
  if (score < 60) return "F";
  if (score < 63) return "D";
  if (score < 67) return "D+";
  if (score < 70) return "C-";
  if (score < 73) return "C";
  if (score < 77) return "C+";
  if (score < 80) return "B-";
  if (score < 85) return "B";
  if (score < 90) return "B+";
  if (score < 95) return "A";
  return "A";
}

int getTime(std::string str) {
  auto x = str.find('\'');
  return 60 * std::stoll(str.substr(0, x)) + std::stoll(str.substr(x + 1, str.size() - x - 2));
}

int getScore(std::string str, char sex) {
  int t = getTime(str);
  if (sex == 'M') {
    if (t <= 12 * 60 + 30) return 20;
    if (t <= 13 * 60) return 18;
    if (t <= 13 * 60 + 30) return 16;
    if (t <= 14 * 60) return 14;
    if (t <= 14 * 60 + 30) return 12;
    if (t <= 15 * 60 + 10) return 10;
    if (t <= 15 * 60 + 50) return 8;
    if (t <= 16 * 60 + 30) return 6;
    if (t <= 17 * 60 + 10) return 4;
    if (t <= 18 * 60) return 2;
    return 0;
  } else {
    if (t <= 6 * 60 + 40) return 20;
    if (t <= 6 * 60 + 57) return 18;
    if (t <= 7 * 60 + 14) return 16;
    if (t <= 7 * 60 + 31) return 14;
    if (t <= 7 * 60 + 50) return 12;
    if (t <= 8 * 60 + 5) return 10;
    if (t <= 8 * 60 + 20) return 8;
    if (t <= 8 * 60 + 35) return 6;
    if (t <= 8 * 60 + 50) return 4;
    if (t <= 9 * 60) return 2;
    return 0;
  }
}

int getScore(int t) {
  if (t >= 18) return 5;
  if (t >= 15) return 4;
  if (t >= 12) return 3;
  if (t >= 9) return 2;
  if (t >= 6) return 1;
  return 0;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<Stu> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].id >> a[i].sex >> a[i].score;
    std::string t;
    std::cin >> t;
    a[i].score += getScore(t, a[i].sex);
    char ispass;
    std::cin >> ispass;
    a[i].score += (ispass == 'P') * 10;
    int f;
    std::cin >> f >> a[i].cnt;
    a[i].score += f;
  }
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    std::string 
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    std::cout << a[i].id << ' ' << a[i].score + getScore(a[i].cnt) << ' ' << getLevel(a[i].score) << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
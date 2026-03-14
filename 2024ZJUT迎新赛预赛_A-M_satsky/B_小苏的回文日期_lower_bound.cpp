#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int cc[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string res[N], s(8, ' '), r;
int v[2];
vector<string> xS;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < N; i++) {
    v[0] = v[1] = 0;
    for (int j = 0, x = i; j < 4; j++, x /= 10)
      s[3 - j] = s[4 + j] = char('0' + x % 10),
            v[j / 2] = v[j / 2] * 10 + x % 10;
    if (v[0] < 1 || v[0] > 12)
      continue;
    if (v[1] < 1 || v[1] > cc[v[0]])
      continue;
    xS.push_back(s);
  }
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    cout << *(lower_bound(xS.begin(), xS.end(), s)) << '\n';
  }
  // lower_bound������set/map/�������vector...���ҵ���һ�����ڵ�������Ԫ�ص�Ԫ��
  // upper_bound�����ϸ����,�����÷���������
}
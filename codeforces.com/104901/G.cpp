#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = (long long)1e9 + 7;
string s[1000010];
string base,ls;
int add[1000010];
string rev(string s)
{
  std::reverse(s.begin(), s.end());
  return s;
}
int r, c;
void solve() {
  cin >> r >> c;
  base = "";
  for(int i = 1; i <= c; i++) base += "0";
  for(int i = 1; i <= r; i++)
    cin >> s[i];
  bool flag;
  memset(add,0, sizeof(add));
  for(int i = 1; i <= r; i++)
  {
    flag = 0;
    for(int j = 0; j < c; j++) 
      if(s[i][j] == '1')
      {
        add[j]++;
      }
  }
  for(int j = 0; j < c; j++) 
  if (add[j] + add[c - j - 1] > 2) 
  {
    std::cout<<"0\n";
    return;
  }

  int cnt = 0, ans = 1;
  bool flag2;
  int pos;
  std::queue <int> q;
  for(int i = 1; i <= r; i++)q.push(i);
  while(!q.empty())
  {
    base = s[q.front()];
    q.pop();
    flag = 0;//conflict exists or not
    cnt = 0;
    while(!q.empty() && cnt < q.size())
      {
        //cout << q.size()<<"*"<<ans<<"*"<<rev(s[q.front()])<<'*'<<base<<endl;
        flag2 = 1;
        ls = s[q.front()];
        pos = q.front();
        q.pop();
        for(int j = 0; j < c; j++) 
          if(base[j] == '1' && (ls[j] == '1' || ls[c - j - 1] == '1'))
            {
             flag = 0;
             flag2 = 0;
             break;
            }
        if(flag2 == 1)
        {
          q.push(pos);
          cnt++;
          continue;
        }

        cnt = 0;
        for(int j = 0; j < c; j++) //conflict->add
          if(s[pos][j] == '1')
            base[j] = '1';
      }
    ans = ans * 2 % mod;
    //cout << ans<< " " << q.size() << endl;
  }
  cout << ans << endl;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
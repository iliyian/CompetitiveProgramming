#include <bits/stdc++.h>
#define int long long
using namespace std;

std::vector<int> pri;
char op[25];
int a[25];
char ans[25];
void solve() 
{
  int n;
  cin>>n;
  int m=2*n-1;
  for(int i=1;i<=n;i++)
  {
    cin>>op[i]>>a[i];
    if(i>=2)
    {
      if(op[i-1]=='S')
      {
        if(op[i]=='E')
        ans[i-1]='L';
        if(op[i]=='W')
        ans[i-1]='R';
      }
      if(op[i-1]=='N')
      {
        if(op[i]=='E')
        ans[i-1]='R';
        if(op[i]=='W')
        ans[i-1]='L';
      }
      if(op[i-1]=='E')
      {
        if(op[i]=='N')
        ans[i-1]='L';
        if(op[i]=='S')
        ans[i-1]='R';
      }
      if(op[i-1]=='W')
      {
        if(op[i]=='N')
        ans[i-1]='R';
        if(op[i]=='S')
        ans[i-1]='L';
      }
    }
  }
  cout<<m<<' '<<op[1]<<endl;
  cout<<'Z'<<' '<<a[1]<<endl;
  for(int i=2;i<=n;i++)
  {
    cout<<ans[i-1]<<endl;
    cout<<'Z'<<' '<<a[i]<<endl;
  }
}
signed main() 
{
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) 
  {
    solve();
  }
  return 0;
}
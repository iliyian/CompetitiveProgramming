#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> a[1000005],b[1000005];
string work(string s,int n)
{
  string st="";
	int c=0;
  for (int i=0;i<=n-1;i++)
  {
	  if (i==0&&s[i]=='0')
	  {
		  st+='0';
		  while(s[i+1]=='0'&&i+1<=n-1)st+='0',i++;
	  }
	  else if (s[i]=='0'&&i+1<=n-1&&s[i+1]=='0')
    {
      while(s[i]=='0'&&i<=n-1)st+='0',i++;
      for (int j=1;j<=c;j++)st+='0';
      c=0;
    }
    else if (s[i]=='1')st+='1';
    else if (s[i]=='0')c++;
  }
	for (int i=1;i<=c;i++)st+='0';
//	cout<<st<<endl;
  int cnt=0,cnt1=0;
  for (int i=0;i<st.size();i++)
  {
    if (i==0||st[i]!=st[i-1])
    {
      a[++cnt].first=st[i]-'0';
      a[cnt].second=1;
    }
    else a[cnt].second++;
  }
  for (int i=1;i<=cnt;i++)
  {
    if (i+3<=cnt&&a[i].first==1&&a[i+1].first==0&&a[i].second>=a[i+1].second)
    {
      a[i+2].second+=a[i].second;
      a[i+3].second+=a[i+1].second;
    }
    else {
      b[++cnt1]=a[i];
    }
  }
//	for (int i=1;i<=cnt1;i++)cout<<b[i].first<<' '<<b[i].second<<endl;
  string res="";
  for (int i=1;i<=cnt1;i++)
  {
    if (b[i].first==0)
    {
      for (int j=1;j<=b[i].second;j++)res+='0';
    }
    else {
      if (i==cnt1)
      {
        for (int j=1;j<=b[i].second;j++)res+='1';
      }
      else{
        if (b[i].second>=b[i+1].second)
        {
          int g=b[i].second-b[i+1].second;
          for (int j=1;j<=b[i+1].second;j++)res+="10";
          for (int j=1;j<=g;j++)res+='1';
        }
        else {
          int g=b[i+1].second-b[i].second;
          for (int j=1;j<=b[i].second;j++)res+="10";
          for (int j=1;j<=g;j++)res+='0';
        }
      }
      i++;
    }
  }
//  cout<<res<<endl;
//  for (int i=n-2;i<n;i++)res+=s[i];
//  cout<<res<<endl;
  return res;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
	 s = work(s,n);
	cout << s << '\n';
   for(int i = 0; i <= n - 5; i++) 
     if(s[i] == '1' && s[i+1] == '1') swap(s[i+1],s[i+2]); 
   
  if(n == 3) {
    if(s[1] == '1' || s[2] == '1') {
      cout << "No\n";
      return;
    }
    cout << "Yes\n";
    return;
  }

  // n = 4
  if(n == 4) {
    if(s[0] == '1' && s[1] == '1') { //11
      cout << "Yes\n";
      return;
    }

    if(s[0] == '1' && s[1] == '0') { //10
      if(s[2] == '0' && s[3] == '1') {
        cout << "No\n";
        return;
      }
      cout << "Yes\n";
      return;
    }

    if(s[0] == '0' && s[1] == '1') {
      if(s[2] == '0' && s[3] == '0') {
        cout << "Yes\n";
        return;
      }
      cout << "No\n";
      return;
    }

    if(s[0] == '0' && s[1] == '0') { //00
      if(s[2] == '0' && s[3] == '0') {
        cout << "Yes\n";
        return;
      }
      cout << "No\n";
      return;
    }
  }

  // n > 4;
  string ss = s.substr(n - 5,5);
  // std::cerr << ss << '\n';
  if(n > 4) {
    if(ss[1] == '1' && ss[2] == '1') { //11
      cout << "Yes\n";
      return;
    }

    if(ss[0] == '1' && ss[1] == '1' && ss[2] == '0') {cout << "Yes\n";return;}
    if(ss[0] == '1' && ss[1] == '0' && ss[2] == '1') {cout << "Yes\n";return;}
    
    if((ss[1] == '1' && ss[2] == '0')) { //10
      if(ss[3] == '0' && ss[4] == '1') {
        cout << "No\n";
        return;
      }
      cout << "Yes\n";
      return;
    }

    if(ss[1] == '0' && ss[2] == '1') {
      if(ss[3] == '0' && ss[4] == '0') {
        cout << "Yes\n";
        return;
      }
      cout << "No\n";
      return;
    }

    if(ss[1] == '0' && ss[2] == '0') { //00
      if(ss[3] == '0' && ss[4] == '0') {
        cout << "Yes\n";
        return;
      }
      cout << "No\n";
      return;
    }
  }
  
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

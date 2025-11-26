#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct node{
	int l,r;
}c[N];
int n,s1,s2;
char a[8][N];
void solve()
{
	s1=s2=0;
	cin>>n;
	for (int i=1;i<=7;i++)
	{
		for (int j=1;j<=n;j++)a[i][j]='.';
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[1][i];
		if (a[1][i]=='.')a[2][i]='#',s1=i;
		else a[2][i]='.'; 
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[7][i];
		if (a[7][i]=='.')a[6][i]='#',s2=i;
		else a[6][i]='.'; 
	}
	if (s1==0&&s2==0)
	{
		cout<<"Yes\n";
		for (int i=1;i<=7;i++)
		{
			for (int j=1;j<=n;j++)cout<<'#';
			cout<<'\n';
		}
	}
	else if (s1==0||s2==0)cout<<"No\n";
	else {
		cout<<"Yes\n";
		for (int i=1;i<=n;i++)
		{
			if (i>1&&a[2][i]=='.'&&a[2][i-1]=='#')
			{
				s1=i;
				a[3][i]='#';
				break;
			}
			else if (i<n&&a[2][i]=='.'&&a[2][i+1]=='#')
			{
				s1=i;
				a[3][i]='#';
				break;
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (i>1&&a[6][i]=='.'&&a[6][i-1]=='#')
			{
				s2=i;
				a[5][i]='#';
				break;
			}
			else if (i<n&&a[6][i]=='.'&&a[6][i+1]=='#')
			{
				s2=i;
				a[5][i]='#';
				break;
			}
		}
//		cout<<s1<<' '<<s2<<endl;
		if (abs(s1-s2)<=1)a[4][s2]='#';
		else {
			if (s1>s2)swap(s1,s2);
			for (int i=s1+1;i<=s2-1;i++)a[4][i]='#';
		}
		for (int i=1;i<=7;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (a[i][j])cout<<a[i][j];
				else cout<<'.';	
			}
			cout<<'\n';
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}

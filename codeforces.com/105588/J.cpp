#include<bits/stdc++.h>
#define ll long long
#define N 200011
using namespace std;
int n,a[N],c;
string s;
void solve()
{
	c=0;
	cin>>n>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=i)c++;
	}
	if (n==3&&s=="Bob")
	{
		if (a[1]==3&&a[2]==1&&a[3]==2)cout<<"Alice\n";
		else if (a[1]==2&&a[2]==3&&a[3]==1)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	else if (n==2)cout<<"Alice\n";
	else if (c==0&&s=="Bob")cout<<"Alice\n";
	else if (c==2&&s=="Alice")cout<<"Alice\n";
	else cout<<"Bob\n";
}
int main()
{
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;const int N=301;
struct S
{
	int n,res=0;
	void solve()
	{
		cin>>n;vector<vector<int>>mat(N+1,vector<int>(n,0));
		//mat[j][i]:����x=j�ĵ��Ƿ��ڼ���i�� ȡ301���б�Ҫ��,��������Ҳ���"�������⼯����"�ĵ�
		for(int i=0,l,r;i<n;i++){cin>>l>>r;for(int j=l;j<=r;j++)mat[j][i]=1;}
		for(int i=0;i<=N;i++)
		{
			bool ok=1;
			for(int j=0;j<i;j++)
			{
				bool diff=0;
				for(int k=0;k<n;k++)diff|=(mat[i][k]^mat[j][k]);
				if(!diff){ok=0;break;}
			}
			res+=ok;
		}
		cout<<res<<'\n';
	}
};
int main(){ios::sync_with_stdio(0);cin.tie(0);S SS;SS.solve();}
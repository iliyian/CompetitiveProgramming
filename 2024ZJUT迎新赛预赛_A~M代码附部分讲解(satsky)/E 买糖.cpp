#include<bits/stdc++.h>
using namespace std;using ll=long long;
struct S
{
	int n;
	void solve()
	{
		cin>>n;vector<ll>v{0};ll res=0;
		for(int i=1;i<=n;i++)
		{
			ll x,y,c=0;cin>>x;y=x;
			while(1)
			{
				int p=upper_bound(v.begin(),v.end(),y)-v.begin()-1;
				//�ڵ���ջ�϶������һ�����ۡ�ʣ��Ǯ���ĵ���,��������һ�����ǵĵ���
				if(!p)break;c+=y/v[p],y%=v[p];
			}
			res=max(res,c);
			while(v.back()>=x)v.pop_back();v.push_back(x);
			//��ÿ�㿪ʼֻ��Ҫ��ע��ǰ�ĵ���ջ,���ڵ���ջ�ϵĵ����޷�����
		}
		cout<<res<<'\n';
	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--){S SS;SS.solve();}
}
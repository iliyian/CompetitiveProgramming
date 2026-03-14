#include<bits/stdc++.h>
using namespace std;
int T,f[2605];
string S,K;
int main(){
	freopen("dp.in","r",stdin);
	freopen("dp.out","wb",stdout);
	for(cin>>T;T;T--){
		cin>>S>>K;
		int k=0;
		switch (K.size()) {
		case 1:
			k=K[0]-'0';
			break;
		case 2:
			k=(K[0]-'0')*10+K[1]-'0';
			break;
		default:
			k=114514;
			break;
		}
		if(k>26){
			sort(S.begin(),S.end());
			printf("%d\n",unique(S.begin(),S.end())-S.begin());
		}
		else{
			string S1="";
			for(int i=0;i<k;i++)
				S1+=S;
			int maxans=0;
			for(int i=0;i<S1.size();i++){
				f[i]=1;
				for(int j=0;j<i;j++)
					if(S1[j]<S1[i])
						f[i]=max(f[i],f[j]+1);
				maxans=max(maxans,f[i]);
			}
			printf("%d\n",maxans);
		}
	}
}

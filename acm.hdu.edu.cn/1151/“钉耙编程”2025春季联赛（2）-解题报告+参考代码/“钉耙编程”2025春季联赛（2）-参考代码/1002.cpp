#include<bits/stdc++.h>
using namespace std;
map<string,int> yr;
string tian[10]={"jia","yi","bing","ding","wu","ji","geng","xin","ren","gui"};
string di[12]={"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};
int main(){
	freopen("history.in","r",stdin);
	freopen("history.out","wb",stdout);
	for(int i=0;i<60;i++)
		yr[tian[i%10]+di[i%12]]=i+1984;
	int T;
	for(scanf("%d",&T);T;T--){
		string s;
		cin>>s;
		cout<<yr[s]<<endl;
	}
	return 0;
}

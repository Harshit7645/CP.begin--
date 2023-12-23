#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,f[300500],l[300500],r[300500],res,cur,fa[300500];
string s;

void dfs(ll node){
	if(!l[node]&&!r[node]){
		f[node]=0; return;
	}
	f[node]=1e9;
	if(l[node])dfs(l[node]);
	if(r[node])dfs(r[node]);
	
	if(s[node]=='U'){
		f[node]=min(f[l[node]]+1,f[r[node]]+1);
	}
	else if(s[node]=='L'){
		f[node]=min(f[l[node]],f[r[node]]+1);
	}
	else if(s[node]=='R'){
		f[node]=min(f[l[node]]+1,f[r[node]]);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s;
        s="$"+s; 
        f[0]=1e9;
		for(i=1;i<=n;i++){
			cin>>l[i]>>r[i];
			fa[l[i]]=fa[r[i]]=i;
		}
		dfs(1);
		cout<<f[1]<<'\n';
	}
}
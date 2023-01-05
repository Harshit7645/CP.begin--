#include<bits/stdc++.h>
using namespace std;
int t;
int n,q;
map<int,int> mp;
const int N=1e5+5;
int a[N];
int x=1;
int main(){
	cin>>t;
	while(t--){
		mp.clear();
		cin>>n>>q;
		x=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			if(a[i]>a[x]){
				x=i;
			}
			mp[x]++;
		}
		mp[x]=2e9;
		for(int i=0;i<q;i++){
			int y,z;
			cin>>y>>z;
			z-=max(y-2,0);
			cout<<max(min(mp[y],z),0)<<endl;
		}
	}
    // for(auto x:mp)
    // cout<<x.first<<" "<<x.second<<endl;
	return 0;
}

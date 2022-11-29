#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
set<int>s;
int main()
{
    int n;
	cin>>n;
	vector<pair<int,int>>a;
	rep(i,0,n)
	{
		int x,y;
		cin>>x>>y;
		a.push_back({x,y});
	}
	sort(a.begin(),a.end());
	set<int>s;
	s.insert({a[0].second});
    int c=0;
    rep(i,0,n-1)
    {
        if(a[i].first==a[i+1].first && a[i].second==a[i+1].second)
        c++;
    }
	for(int i=1;i<n;i++)
	{
		auto it=upper_bound(s.begin(),s.end(),a[i].first);
		if(it!=s.begin())
		{
			it--;
			s.erase(it);
		}
		s.insert(a[i].second);
	}
	cout<<s.size()+c<<endl;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        long long int n,i,j,c=0;
        cin>>n;
        vector<pair<int,int>>v;
        vector<int>val(n);
        for(i=0;i<n;i++)
        {
            cin>>val[i];
            if(i+1>val[i])
                v.push_back({i+1,val[i]});
        }
        sort(v.begin(),v.end());
        val.clear();
        for(i=0;i<v.size();i++)
        {
            val.push_back(v[i].second);
        }
        sort(val.begin(),val.end());
        c=0;
        for(i=0;i<v.size();i++)
        {
            auto it=lower_bound(val.begin(),val.end(),v[i].first+1);
            c=c+(val.end()-it);
        }
        cout<<c<<endl;
    }
    return 0;
}
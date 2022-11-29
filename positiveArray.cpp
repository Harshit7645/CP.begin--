#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    for(long long int l=0;l<t;l++)
    {
        long long int n,i,j,ans=0;
        cin>>n;
        vector<long long int>v(n),lafda;
        for(i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]<i+1){
            lafda.push_back(v[i]);
            }
        }
        if(lafda.size()!=0)
        {
            ans=1;
        sort(lafda.begin(),lafda.end());
        for(i=0;i<lafda.size();i++)
        {            
            auto it=v.begin()+i;
            if(lafda[i]>=i+1)
            continue;
            else
            {
                lafda.erase(lafda.begin(),it);
                ans++;
            }
        }
        }
        cout<<ans<<endl;        
    }
    return 0;
}
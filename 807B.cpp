//coded by HarshitSPakhariya
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    long long int i,j,k;
    for(k=0;k<t;k++)
    {
        long long int n,flag=0,ans=0;
        cin>>n;
        vector<long long int>v(n);
        for(i=0;i<n;i++)
        {
            long long int x;
            cin>>x;
            v[i]=x;   
        }
        ans=0;flag=0;
        for(i=0;i<v.size()-1;i++)
        {
            if(v[i]>0)
            flag=1;
            if(v[i]==0 && flag==1)
            ans++;
            else
            ans+=v[i];
        }
        cout<<ans<<endl;
    }

}
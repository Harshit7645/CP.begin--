#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,i,j,ans=0;
    cin>>n>>x;
    vector<int> v(n);
    for(i=0;i<n;i++)
    {
        cin>>v[i];   
    }
    long long int sum=0;
    ans=0;
    j=0;
    for(i=0;i<n;i++)
    {
        sum+=v[i];
        while(sum>=x)
        {
            if(sum==x)
            ans++;
            sum-=v[j];
            j++;
        }
    }
    cout<<ans<<"\n";

}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    for(long long int l=0;l<t;l++)
    {
        long long int n,k,m,cn,ans=0;
        cin>>n>>k>>m;
        cn=k*m;
        if(n%cn==0)
        ans=n/cn;
        else
        ans=(n/cn)+1;
        cout<<ans<<"\n";
    }
    return 0;
}
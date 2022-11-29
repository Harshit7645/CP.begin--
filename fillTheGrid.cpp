#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    for(long long int l=0;l<t;l++)
    {
        int n,m,ans=0;
        cin>>n>>m;
        ans=m*n-((n/2)*(m/2)*4);
        cout<<ans<<"\n";
    }
    return 0;
}
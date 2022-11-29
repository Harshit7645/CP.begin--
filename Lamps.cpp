#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
       int x,y,n,cost=0,k; 
       cin>>n>>k>>x>>y;
       cost=k*x;
       if(x>y)
       cost+=(n-k)*y;
       else
       cost+=(n-k)*x;
       cout<<cost<<endl;
    }
}
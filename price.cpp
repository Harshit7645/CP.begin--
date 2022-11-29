#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,i,j,k;
    cin>>t;
    for(k=0;k<t;k++)
    {
        int n,max=1;
        cin>>n;
        int c=0;
        for(i=n;i>0;i=i/10)
        c++;
        for(i=1;i<c;i++)
        {
            max=max*10;
        }
        cout<<n-max<<endl;
    }
}
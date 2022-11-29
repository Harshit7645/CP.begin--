#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    for(long long int l=0;l<t;l++)
    {
        long long int n,nz=0,no=0,i,flag=0;
        string s;
        cin>>n;
        cin>>s;
        for(i=0;i<n;i++)
        {
            if(s[i]=='0')
            nz++;
        }
        no=n-nz;
        if(no>nz)
        {
            for(i=0;i<no;i++)
            {
                cout<<1;
            }
        }
        else
        {
            for(i=0;i<nz;i++)
            {
                cout<<0;
            }
        }
        cout<<endl;
    }
}
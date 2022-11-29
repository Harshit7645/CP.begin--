#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n,i,j,a,d,flag=0,nt;
        cin>>n;
        vector <int>v(n);
        for(i=0;i<n;i++)
        {
            cin>>v[i];
        }
        flag=0;
        for(i=1;i<n;i++)
        {
            if(v[i]%v[0]!=0)
            flag=1;     
        }
        if(flag==1)
        cout<<"NO"<<endl;
        else 
        cout<<"YES"<<endl;
    }
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n,i,j,u=0,d=0;
        cin>>n;
        int arr[n],ori[n];
        string x;
        for (i = 0; i < n; i++)
        {
            cin>>arr[i];
            ori[i]=0;
        }
        int m;
        for(i=0;i<n;i++)
        {
            cin>>m;
            cin>>x;
            if((arr[i]+count(x.begin(),x.end(),'D')-count(x.begin(),x.end(),'U'))>0)
            ori[i]=(arr[i]+count(x.begin(),x.end(),'D')-count(x.begin(),x.end(),'U'))%10;
            else if((arr[i]+count(x.begin(),x.end(),'D')-count(x.begin(),x.end(),'U')<0))
            ori[i]=(arr[i]+count(x.begin(),x.end(),'D')-count(x.begin(),x.end(),'U'))+10;
            else 
            ori[i]=0;
        }
        for(i=0;i<n;i++)
        cout<<ori[i]<<" ";
        cout<<endl;
    }
}
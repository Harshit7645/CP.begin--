#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int i,j,n;
        cin>>n;
        vector<bool>v(n+1,false);
        cout<<2<<endl;
        for(i=1;i<=n;i+=2)
        {
            for(j=i;j<=n;j=j*2)
            {
                cout<<j<<" ";
                v[j]=true;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(v[i]==false)
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}
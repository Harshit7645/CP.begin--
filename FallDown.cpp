#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    for(ll k=0;k<t;k++)
    {
        ll i,j,n,m,flag=0;
        cin>>n>>m;
        char ch[n][m];
        vector<vector<ll>>vec;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>ch[i][j];
            }
        }
        cout<<"\n";
        for(j=0;j<m;j++)
        {
            for(i=n-2;i>=0;i--)
            {
                if(ch[i][j]=='*')
                {
                    int k=i+1;
                    while(ch[k][j]=='.' && k<=n-1)
                        k++;
                    swap(ch[k-1][j],ch[i][j]);    
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<ch[i][j];
            }
            cout<<endl;
        }
    }
}
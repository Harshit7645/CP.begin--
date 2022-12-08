#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

void dfs(int x,int n ,int*a,bool*b)
{
    if(b[x]==false)
    {
        b[x]=true;
        for (int i = 0; i < n; i++)
        {
            if(*(a+x*n+i)==1 && b[i]==false)
            {
                dfs(i,n,a,b);
            }
        }
    } 
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        ll n,m;
        cin>>n>>m;
        ll k;
        //cin>>k;
        int arr[n][m];
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                arr[i][j]=0;
            }
        }
        ll temp;
        rep(i,0,n)
        {
            cin>>k;
            rep(j,0,k)
            {
                cin>>temp;
                if(i==temp)
                continue;
                arr[i][temp-1]=1;
                arr[temp-1][i]=1;
            }
        }   
        ll j=0,sum=0; 
        bool b[n];
        rep(i,0,n)
        {
            b[i]=false;
        }
        while (j<n)
        {
            if(b[j]==false)
            {
                dfs(j,n,&arr[0][0],b); 
                sum++;
            }
            j++;
        }
        cout<<(sum-1)<<endl;
}
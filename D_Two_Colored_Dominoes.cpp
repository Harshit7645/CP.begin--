#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
using namespace std;

int main()
{
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<string>grid(n);
        rep(i,0,n)
        {
            cin>>grid[i];
        }
        vector<string>ans(n);
        rep(i,0,n)
        {
            rep(j,0,m)  
            {
                ans[i]+='.';
            }
        }
        // rep(i,0,n)
        // {
        //     rep(j,0,m)
        //     {
        //         cout<<ans[i][j];
        //     }
        //     cout<<"\n";
        // }
        string dam="BW";
        //ll p=0;
        rep(j,0,m)
        {
            ll p=0;
            rep(i,0,n)
            {
                if(grid[i][j]=='L')
                {
                    ans[i][j]=dam[p];
                    p=(p+1)%2;
                    ans[i][j+1]=dam[p];
                }
            }
        }
        rep(i,0,n)
        {
            ll p=0;
            rep(j,0,m)
            {
                if(grid[i][j]=='U')
                {
                    ans[i][j]=dam[p];
                    p=(p+1)%2;
                    ans[i+1][j]=dam[p];
                }
            }
        }
        ll f=0;
        rep(i,0,n)
        {
            ll b=0,w=0;
            rep(j,0,m)
            {
                b+=(ans[i][j]=='B');
                w+=(ans[i][j]=='W');
            }
            if(b!=w)
            {
                f=1;
                break;
            }
            //cout<<b<<" "<<w<<"\n";
        }
        rep(j,0,m)
        {
            ll b=0,w=0;
            rep(i,0,n)
            {
                b+=(ans[i][j]=='B');
                w+=(ans[i][j]=='W');
            }
            if(b!=w)
            {
                f=1;
                break;
            }
            //cout<<b<<" "<<w<<"\n";
        }
        if(f)
        {
            cout<<"-1\n";
            continue;
        }
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
}
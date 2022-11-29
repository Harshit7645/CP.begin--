#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        char arr[8][8];
        rep(i,0,8)
        {
            rep(j,0,8)
            {
                cin>>arr[i][j];
            }
        }
        ll f=0,r=0,c=0;
        rep(i,1,7){
            rep(j,1,7)
            {
                if(arr[i][j]=='#')
                {
                    if(arr[i-1][j-1]=='#' && arr[i-1][j+1]=='#' && arr[i+1][j-1]=='#' && arr[i-1][j+1]=='#')
                    {
                        r=i;
                        c=j;
                        f++;
                    break;
                    }
                }
            }
            if(f==1)
            break;
        }
        if(f==1)
        cout<<r+1<<" "<<c+1<<"\n";
    }
}
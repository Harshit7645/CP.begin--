#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll x,y;
    cin>>x>>y;ll tot=(x*100) +(y*10);
    ll flag=0;
    while(1)
    {
        if(flag%2==0)
        {
            if(x>=2 && y>=2)
            x-=2,y-=2;
            else if(x>=1 && y>=12)
            x-=1,y-=12;
            else if(x>=0 && y>=22)
            y-=22;
            else
            {
                cout<<"Hanako\n";
                break;
            }
        }
        else{
            if(y>=22 && x>=0)
            y-=22;
            else if(y>=12 && x>=1)
            y-=12,x-=1;
            else if(y>=2 && x>=2)
            y-=2,x-=2;
            else
            {
                cout<<"Ciel\n";
                break;
            }
        }
        flag++;
    }

}
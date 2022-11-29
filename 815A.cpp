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
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        // if((a>b && a%b==0))
        // a=a/b,b;
        // if((a==0 && b==0) || (a==c && b==d))
        // cout<<"0\n";
        // else {
        //     if((d>c && d%c==0) || (c>d && c%d==0))
        //     cout<<"1\n";
        //     else if(c==d)
        //     {
        //         if((a>b && a%b==0)|| (a<b && b%a==0))
        //         cout<<"1\n";
        //         else
        //         cout<<"2\n";
        //     }
        //     else if(a==b)
        //     {
        //         if((c>d && c%d==0)|| (c<d && d%c==0))
        //         cout<<"1\n";
        //         else
        //         cout<<"2\n";
        //     }
        //     else if((c>d && c%d!=0) || (d>c && d%c!=0))
        //     {
        //         if((a>b && a%b!=0) || (b>a && b%a!=0))
        //         cout<<"4\n";
        //         else
        //         cout<<"3\n";
        //     }
        //     else if((a>b && a%b!=0) || (b>a && b%a!=0))
        //     {
        //         if((c>d && c%d!=0) || (d>c && d%c!=0))
        //         cout<<"4\n";
        //         else
        //         cout<<"3\n";
        //     }
        // }
        if(a*d==b*c)
        cout<<"0\n";
        else if((a*d==0 || b*c==0))
        cout<<"1\n";
        else if((b*c)%(d*a)==0 || (a*d)%(b*c)==0)
        cout<<1<<endl;
        else
        cout<<"2\n";
    }
}
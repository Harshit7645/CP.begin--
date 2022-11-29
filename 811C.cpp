#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main() 
{
    ll t,x;
    cin>>t;
    rep(x,0,t)
    {
        ll s,i,j;
        cin>>s;
        string str="\0";
        for(i=9;s-i>0;i--)
        {
            str+=(char)(i+48);
            if(i==0)
            break;
            s-=i;
        }
        //cout<<s<<endl;
        if(s!=0)
        str+=(char)(s+48);
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
}
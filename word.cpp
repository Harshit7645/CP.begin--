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
    string str;
    cin>>str;
    ll n=str.length();
    ll s=0,b=0;
    rep(i,0,n)
    {
        ll temp=(int)str[i];
        if(temp>=65 && temp<=90)
        b++;
        else
        s++;
   }
   if(b>s)
   transform(str.begin(),str.end(),str.begin(),::toupper);
   else
   transform(str.begin(),str.end(),str.begin(),::tolower);
   cout<<str<<endl;
}
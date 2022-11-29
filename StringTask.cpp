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
    string s,str;
    cin>>s;
    str=s;
    ll n=s.length(),c=0;
    transform(s.begin(),s.end(),s.begin(),::tolower);
      transform(str.begin(),str.end(),str.begin(),::tolower);
    rep(i,0,n)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'|| s[i]=='y')
        {
            str.erase(i-c,1);
            c++;
        }
    }
    // ll i=0;
    // n=s.length();
    // while(i<=n-1)
    // {
    //     str=s.substr(i,1)+".";
    //     i++;
    // }
    s.clear();
    n=str.length();
    rep(i,0,n)
    {
        s=s+"."+str[i];
    }
    cout<<s<<endl;
}
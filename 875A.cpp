#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
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
        string s;
        cin>>s;
        ll n=s.length();
        if(n%2==0)
        {
            cout<<"Alice ";
            ll sum=0;
            rep(i,0,n)
            {
                sum+=s[i]-'a'+1;
            }   
            cout<<sum<<endl;
            continue;
        }
        else 
        {
            ll sum1=0,sum2=0;
            rep(i,0,n)
            {
                sum1+=s[i]-'a'+1;
            } 
            //if(s[0]>s[n-1])
            if(s[0]<s[n-1])
            sum2=(s[0]-'a')+1;
            else
            sum2=(s[n-1]-'a')+1;
            if(sum1>sum2)
            cout<<"Alice ";
            else
            cout<<"Bob ";
            cout<<abs(sum1-2*sum2)<<endl;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"

bool isPalindrome(string s)
{
    rep(i,0,s.length()/2)
    {
        if(s[i]!=s[s.length()-i-1])
        return false;
    }
    return true;
}


int main()
{
    ll n;
    cin>>n;
    string s;
    vector<string>v;
    rep(i,0,n)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }
    ll f=0;
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            if(j==i)
            continue;
            string temp=v[i]+v[j];
            if(isPalindrome(temp))
            {
                f=1;
                break;
            }
        }
        if(f)
        break;
    }
    if(f)
    PYES;
    else
    PNO;
}   
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

string solve(string s,string t)
{
    int n=s.length(),m=t.length();
    if(n<m)
    return "";
    else if(s==t)
    return s;
    vector<ll>v(128);
    rep(i,0,m)
    {
        v[t[i]]++;
    }
    int cnt=m;
    ll left=0,minlen=INT_MAX,leftind=0;
    rep(right,0,n)
    {
        if(v[s[right]]>0)
        cnt--;
        v[s[right]]--;
        while(cnt==0)
        {
            if(minlen>right-left+1)
            {
                minlen=right-left+1;
                leftind=left;
            }
            v[s[left]]++;
            if(v[s[left]]>0)
            cnt++;
            left++;
        }
    }
    return minlen==INT_MAX?"":s.substr(leftind,minlen);
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<solve(s,t);
}   
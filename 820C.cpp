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
        string s;ll x=0;
        map<char,vector<int>>req;
        cin >> s;
        for(int i=1;i<s.size()-1;++i)
        req[s[i]].push_back(i+1);
        if(s[0]<s[s.size()-1]) 
        {
        for(char i=s[0];i<=s[s.size()-1];i++)
            x+=req[i].size();
            cout<<s[s.size()-1]-s[0]<<" "<<x+2<<endl;
            cout<<"1 ";
            for(char i=s[0];i<=s[s.size()-1];++i)
            {
                for(int x:req[i])
                    cout<<x<<" ";
            }
        cout<<s.size()<<endl;
        } 
        else 
        {
            for(char i=s[0];i>=s[s.size()-1];--i)
            x+=req[i].size();
            cout << s[0]-s[s.size()-1] <<" "<<x+2<< endl;
            cout << 1 <<" ";
            for(char i=s[0];i>=s[s.size()-1];i--)
                {
                    for(int x:req[i])
                    cout<<x<<" ";
                }
            cout<<s.size()<<endl;
        }
    }
}
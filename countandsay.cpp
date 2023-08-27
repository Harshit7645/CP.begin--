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

string solve(int n)
{
    string s="1";
    //v.push_back("1");
    n--;
    while(n--)
    {
        string temp="";//int cnt=0;
        rep(i,0,s.length())
        {
            char ch=s[i];
            int cnt=0;
            while(s[i]==ch && i<s.length())
            {
                cnt++;
                i++;
            }
            i--;
            temp+=to_string(cnt);
            temp+=ch;
        }
        s=temp;
        //cout<<s<<" ";
    }
    // rep(i,0,n)
    // {
    //     cout<<v[i]<<" ";
    // }
    return s;
}

int main()
{
    cout<<solve(5);
}   
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
        string s1,s2;
        cin>>s1>>s2;
        ll n1=s1.length(),n2=s2.length();
        if(s1[n1-1]<s2[n2-1])
        {
            cout<<">\n";
            continue;
        }
        else if(s1[n1-1]>s2[n2-1])
        {
            cout<<"<\n";
            continue;
        }
        else
        {
            if(s1[n1-1]=='S'){
            if(n1>n2)
            cout<<"<\n";
            else if(n1==n2)
            cout<<"=\n";
            else
            cout<<">\n";
            }
            else if(s1[n1-1]=='L')
            {
                if(n1>n2)
            cout<<">\n";
            else if(n1==n2)
            cout<<"=\n";
            else
            cout<<"<\n";
            }
            else    
            cout<<"=\n";
        }
    } 
}
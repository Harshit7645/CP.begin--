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

string solve(int A)
{
    queue<pair<string,int>>q;
    q.push({"1",1%A});
    map<int,int>m;
    string ans="";
    while(!q.empty())
    {
        pair<string,int>node=q.front();
        q.pop();
        if(node.second==0)
        {
            ans=node.first;
            break;
        }
        rep(i,0,2)
        {
            int newrem=(node.second*10+i)%A;
            if(m[newrem])
            continue;
            string temp=node.first;
            if(i==0)
            temp+="0";
            else
            temp+="1";
            q.push({temp,newrem});
            m[newrem]++;
        }
    }
    return ans;
}
int main()
{
    cout<<solve(91377);
}   
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
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
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int f=0;
        rep(i,0,n-1)
        {
            if((s[i]=='B' && s[i+1]=='W' && t[i]=='W' && t[i+1]=='B')||(s[i]=='W' && s[i+1]=='B' && t[i]=='B' && t[i+1]=='W'))
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            PNO;
            continue;
        }
        int control=-1;
        f=0;
        int count=0;
        rep(i,0,n)
        {
            if(s[i]=='B' && t[i]=='B')
            {
                if(control!=-1)
                control=1-control;
            }
            else if(s[i]=='B' && t[i]=='W')
            { 
                if(control==0 || control==-1)
                {
                    control=0;
                }
                else
                {
                    f=-1;
                    break;
                }
            }
            else if(s[i]=='W' && t[i]=='B')
            {
                if(control==1 || control==-1)
                {
                    control=1;
                }
                else
                {
                    f=-1;
                    break;
                }
            }
            else if(s[i]=='W' && t[i]=='W')
            {
                f=-1;
                break;
            }
        }
        if(f==0 or f==1)
        PYES;
        else
        PNO;
    }    
}
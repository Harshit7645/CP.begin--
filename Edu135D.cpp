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
        string s;
        cin>>s;
        ll n=s.length();
        ll x=n;
        string al="\0",bob="\0";
        ll f=0;
        ll i=0;
        while(1)
        {
            if(i>=n)
            break;
            if(f%2==0)
            {
                if((int)s[i]<=(int)s[n-1])
                {
                    al+=s[i];
                    i++;
                }
                else
                {
                    al+=s[n-1];
                    n--;
                }
                f++;
            }
            else
            {               
                if((int)s[i]<=(int)s[n-1])
                {
                    bob+=s[i];
                    i++;
                }
                else
                {
                    bob+=s[n-1];
                    n--;
                }    
                f++;        
            }
        }
        if(al==bob)
        cout<<"Draw";
        else{
        rep(i,0,x)
        {
            if((int)al[i]<(int)bob[i])
            {
                cout<<"Alice";
                break;
            }
            else if((int)al[i]>bob[i])
            {
                cout<<"Bob";
                break;
            }
        }
        }
        cout<<"\n";
        // cout<<al<<" "<<bob;
    }
}
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
        ll n;
        cin>>n;
        vector<string>p1,p2,p3;
         map<string,ll>m1,m2,m3;
        rep(i,0,n)
        {
            string s;
            cin>>s;
            p1.push_back(s);
            m1[s]++;
        }
        rep(i,0,n)
        {
            string s;
            cin>>s;
            p2.push_back(s);
            m2[s]++;
        }
        rep(i,0,n)
        {
            string s;
            cin>>s;
            p3.push_back(s);
            m3[s]++;
        }
        ll ans1=0,ans2=0,ans3=0;
        rep(i,0,n)
        {
            if(m1[p1[i]] && m2[p1[i]] && m3[p1[i]])
            continue;
            else if(m1[p1[i]] && m2[p1[i]])
            ans1++;
            else if(m1[p1[i]] && m3[p1[i]])
            ans1++;
            else
            ans1+=3;
        }
        rep(i,0,n)
        {
            if(m1[p2[i]] && m2[p2[i]] && m3[p2[i]])
            continue;
            else if(m1[p2[i]] && m2[p2[i]])
            ans2++;
            else if(m3[p2[i]] && m2[p2[i]])
            ans2++;
            else
            ans2+=3;
        }
        rep(i,0,n)
        {
            if(m1[p3[i]] && m2[p3[i]] && m3[p3[i]])
            continue;
            else if(m1[p3[i]] && m3[p3[i]])
            ans3++;
            else if(m3[p3[i]] && m2[p3[i]])
            ans3++;
            else
            ans3+=3;
        }
        cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }
}
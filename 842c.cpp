#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact (r))*(fact(n-r))));
}
bool isPrime(ll n)
{
    if(n<=1)
    return false;
    if(n<=3)
    return true;

    if(n%2==0 || n%3==0 || n%5==0)
    return false;
    for(ll i=6;i<=sqrt(n);i+=5)
    {
        //for (ll i=5;i*i<=n;i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;//return true;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        //map<ll,vector<ll>>m;
        rep(i,0,n)
        {
            cin>>arr[i];
            //m[arr[i]].push_back(i);
        }  
        if(n==1)
        {
            PYES;
            cout<<"1\n1\n";
            continue;
        }
        //map<ll,ll>m;
        // rep(i,0,n)
        // {
        //     m[arr[i]].push_back(i);
        // }
       // vector<ll>p(n),q(n);
        //ll lar=n;
        // while(lar>=1)
        // {
        //     if(m[lar].size()==2)
        //     {
        //         p[m[lar][0]]=arr[m[lar][0]];
        //         q[m[lar][1]]=arr[m[lar][1]];
        //     }
        //     if(m[lar].size()==1)
        //     {
        //         p[m[lar][0]]=arr[m[lar][0]];
        //         q[m[lar+1][0]]=arr[m[lar][0]];
        //     }
        //     lar--;
        // }
        // rep(i,0,n)
        // {
        //     cout<<p[i]<<" ";
        // }
        // cout<<"\n";
        // rep(i,0,n)
        // {
        //     cout<<q[i]<<" ";
        // }
        map<ll,ll>novis,part;
        vector<ll>p,q;
        rep(i,0,n)
        {
            novis[arr[i]]++;
        }
        ll f=1;
        rep(i,1,n+1)
        {
            if(novis[i]==1)
            part[i]=i;
            else if(novis[i]==2)
            q.push_back(i);
            else if(novis[i]==0)
            p.push_back(i);
            else
            {
                f=0;
                break;
            } 
        }
        if(f==0)
        {
            PNO;
            continue;
        }
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        rep(i,0,p.size())
        {
            ll p1=p[i],p2=q[i];
            if(p1>p2)
            {
                f=0;
                break;
            }
            else
            {
                part[p2]=p1;
            }
        }
        map<ll,ll>m;
        if(f){
        PYES;
        rep(i,0,n)
        {
            if(!m[arr[i]])
            {
                m[arr[i]]++;
                cout<<arr[i]<<" ";
            }
            else
            {
                cout<<part[arr[i]]<<" ";
            }
        }
        cout<<"\n";
        m.clear();
        rep(i,0,n)
        {
            if(!m[arr[i]])
            {
                m[arr[i]]++;
                cout<<part[arr[i]]<<" ";
            }
            else
            {
                cout<<arr[i]<<" ";
            }
        }
        cout<<"\n";
        continue;
        }
        PNO;
    }
}
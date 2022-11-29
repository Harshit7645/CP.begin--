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
        ll n,i;
        cin>>n;
        ll sum=0,x;
        //ll arr[n];
        rep(i,0,n)
        {
            cin>>x;
            while(x%2==0)
            {
                x/=2;
                sum++;
            }
            //temp[i]=arr[i];
        }
        ll j,init=0;
        vector<ll>req;
        for(i=0;i<n;i++)
        {
            init=0;
            j=i+1;
            while((j)%2==0)
            {
                init++;
                j/=2;
            }
            //sum+=init;
            req.push_back(init);
        }
        if(sum>=n)
        {
            cout<<"0\n";
            continue;
        }
        // else if(sum==0)
        // {
        //     cout<<"-1\n";
        //     continue;
        // }
        sort(req.begin(),req.end());
        reverse(req.begin(),req.end());
        ll ans=sum,f=0;
        rep(i,0,n)
        {
            ans+=req[i];
            if(ans>=n)
            {
                cout<<i+1<<"\n";
                f=1;
                break;
            }
        }
        if(!f)
        cout<<"-1\n";
        continue;
        // vector<ll>powi;
        // i=1;
        // while(i<200000)
        // {
        //     powi.push_back(i);
        //     i*=2;
        // }
        // ll last=powi.size()-1,next=0,req=init,ans=0,y=0;
        // rep(i,0,powi.size())
        // {
        //     if(powi[i]>n)
        //     break;
        //     //if(arr[i]%2==0)
        //     y=i;
        // }
        // //cout<<init<<" "<<y;
        // // while(req<n)
        // {
        //     ans++;
        //     req+=last-1;
        // }
        //if(arr[y]%2==0)
        //ans+=ceil((double)(n-init)/(double)(y));
        //cout<<init;
        // for(auto x:powi)
        //  cout<<x<<" ";
        //cout<<ans<<endl;
    } 
}
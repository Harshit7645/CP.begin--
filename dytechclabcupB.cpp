#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll Sqrt(ll x){
    ll low = 1, high = 3e9, ans = 1;
 
    while(low<=high){
        ll mid = (low+high)/2;
 
        if(mid*mid<=x){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
 
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,r,x,i,j,lt=0,rt=0,ans=0,m=0,n=0;
        cin>>l>>r;
        // lt=ceil(sqrt(l));
        // rt=floor(sqrt(r));
        lt=Sqrt(l);
        rt=Sqrt(r);
        ans=max(0ll,(rt-lt-1)*3);
            if(lt*lt>=l && lt*lt<=r)
            ans++;
            if((lt+1)*lt>=l && (lt+1)*lt<=r)
            ans++;
            if((lt+2)*lt>=l && (lt+2)*lt<=r)
            ans++;
        
        if(rt!=lt)
        {
            if(rt*rt>=l && rt*rt<=r)
            ans++;
            if((rt+1)*rt>=l && (rt+1)*rt<=r)
            ans++;
            if((rt+2)*rt>=l && (rt+2)*rt<=r)
            ans++;
        }
        cout<<ans<<endl;
    }
}
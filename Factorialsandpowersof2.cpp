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
    ll i, j, n, t, k, count, ans, total, sum, p_j, rem; 
    vector<ll> a;
    j=1;    
    a.push_back(j);   
    for(i=1; i<=14; i++)
    {
        j=j*i;
        a.push_back(j);
    }
    k=a.size();   
    total=(1<<k);   
    cin>>t;    
    while(t--)
    {
        cin>>n;       
        ans=-1;        
        for(i=0; i<total; i++)
        {
            sum=count=0;
            
            p_j=1;
            for(j=0; j<k; j++)
            {
                if((i&p_j)){
                    sum=sum+a[j];
                    count++;
                }
                p_j*=2;
            }            
            if(sum>n){
                continue;
            }            
            rem=n-sum;            
            while(rem>0){
                count++;
                rem=(rem&(rem-1));
            }            
            if(ans==-1)
            ans=count;
            else
            ans=min(ans, count);
        }        
        cout<<ans<<"\n";
    }
}
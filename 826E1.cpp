#include <bits/stdc++.h>
    using namespace std;
    #define pb push_back
    #define vi vector<ll>
    #define ll long long int
  
    vi divisors(ll n){vi div;for(ll i=1;i*i<=n;i++){ if(n%i==0) { div.pb(i); if(n/i!=i) div.pb(n/i); }} return div;}
     
     
    void solve(){
        ll n;
        cin>>n; 
        ll a[n];
     
        ll sum = 0;
        
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            sum+=a[i];
        }
     
        vi div = divisors(sum);
     
        ll ans= n;
     
        if(div.size()<=2){
            cout<<n<<endl;
            return;
        }
     
     
        for(auto x : div){
     
            ll req = sum/x;
            bool b = false;
     
            ll s = 0;
            ll thick = 0;
     
            ll mx = 0;
     
            for (int i = 0; i < n; ++i)
            {   
                s+=a[i];
                thick++;
     
                if(s==req){
                    mx = max(thick,mx);
                    s= 0;
                    thick=0;
                }else if(s>req){
                    b=true;
                    break;
                }
            }
     
            if(!b){
                ans = min(ans,mx);
            }
     
        }
        cout<<ans<<endl;
    }   
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        clock_t t1=clock();
        int t=1;
        cin>>t;
     
        while(t--){
            solve();
        }
       
    }
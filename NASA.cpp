    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define rep(i,a,b) for(ll i=a;i<b;i++)
    #define repr(i,a,b) for(ll i=a;i>=b;i--)
    #define PNO cout<<"NO\n"
    #define PYES cout<<"YES\n"
    #define vll vector<ll>;

    bool isPalindrome(int n) {
        string str = to_string(n);
        int len = str.length();
        for(int i = 0; i < len/2; i++) {
            if(str[i] != str[len-1-i])
                return false;
        }
        return true;
    }
    
    vector<int> generatePalindromes(int n) {
        vector<int>ans;
        for(int i = 0; i < n; i++) {
            if(isPalindrome(i))
                ans.push_back(i);
        }
        return ans;
    }
    int main()
    {
        //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        ll tt=1;
        cin>>tt;
        vector<int>pal=generatePalindromes(pow(2,15));
        while(tt--)
        {
            ll n;
            cin>>n;
            ll arr[n];
            unordered_map<ll,ll>m;
            rep(i,0,n)
            {
                cin>>arr[i];
                m[arr[i]]++;
            }
            ll ans=n;
            rep(i,0,n)
            {
                rep(j,0,pal.size())
                {
                    ll num=(arr[i]^pal[j]);
                    ans+=m[num];
                }
            }
            cout<<ans/2<<"\n";
        }
    }   
    
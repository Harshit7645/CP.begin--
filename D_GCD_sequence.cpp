#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
using namespace std;

int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll>arr(n);
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        vector<ll>gcdarr(n - 1);
        rep(i,0,n-1)
        {
            gcdarr[i] = __gcd(arr[i], arr[i + 1]);
        }
        ll ind = -2;
        rep(i,0,n-2) 
        {
            if (gcdarr[i]>gcdarr[i + 1]) 
            {
                ind = i;
                break;
            }
        }
        if (ind==-2) {
            PYES;
            continue;
        }
        vector<int> a1, a2, a3;
        rep(i,0,n) 
        {
            if (i != ind + 1) a1.push_back(arr[i]);
            if (i != ind + 2) a2.push_back(arr[i]);
            if (i != ind) a3.push_back(arr[i]);
        }
        vector<ll>b1(a1.size()-1),b2(a2.size()-1),b3(a3.size()-1);
        rep(i,0,a1.size()-1) 
        {
            b1[i] = __gcd(a1[i], a1[i + 1]);
        }
        rep(i,0,a2.size()-1) 
        {
            b2[i] = __gcd(a2[i], a2[i + 1]);
        }
        rep(i,0,a3.size()-1)
        {
            b3[i] = __gcd(a3[i], a3[i + 1]);
        }
        bool flag1 = is_sorted(b1.begin(),b1.end());
        bool flag2 = is_sorted(b2.begin(),b2.end());
        bool flag3 = is_sorted(b3.begin(),b3.end());
        if (!flag1 && !flag2 && !flag3) {
            PNO;
        } else {
            PYES;
        }
    }
    return 0;
}

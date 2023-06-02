#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define sz(C) ((int) C.size())
#define show(C) for (auto J: C) cout << J << " "; cout << endl;
#define enl "\n"
#define LL long long
#define ll long long
#define rep(I, S, E) for(LL I = S; I < E; I++)
#define all(C) C.begin(), C.end()
#define present(container, element)(container.find(element) != container.end())
#define cpresent(container, element)(find(all(container), element) != container.end())
#define MP(X, Y) make_pair(X, Y)
#define PYES cout << "YES\n"
#define PNO cout << "NO\n"
#define int long long
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define seea(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n,q;
        cin>>n>>q;
        vector<int>arr(n+1);
        rep(i,1,n+1)
        {
            cin>>arr[i];
        }
        vector<ll>precnt(n+2);
        rep(i,0,q)
        {
            ll x,y;
            cin>>x>>y;
            precnt[x]++;
            precnt[y+1]--;
        }   
        rep(i,1,n+1)
        {
            precnt[i]=precnt[i]+precnt[i-1];
        }
        // rep(i,1,n+1)
        // {
        //     cout<<precnt[i]<<" ";
        // }
        // cout<<"\n";
        vc<pii> v(n);
    rep(i, 0, n) {
        v[i] = {precnt[i+1], i};
    }
    // show(aux);
    sort(all(v));
    reverse(all(v));
    sort(all(arr));
    reverse(all(arr));
    vi res(n);
    int ans = 0;
    rep(i, 0, n) {
        res[v[i].S] = arr[i];
        ans += v[i].F * arr[i];
    }
    cout << ans << enl;
    show(res);
    }
    return 0;
}   
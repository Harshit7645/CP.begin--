#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define pb push_back
#define MAX 100005
#define vll vector<ll>;
int n, m, k, x, y;
long long c[200100];
vector <int> a, b;
vector <int> :: iterator k1, k2;
long long res, sa[100100], sb[100100], w;
 
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    FOR(i,1,n) {
        cin >> x;
        a.pb(x);
    }
    FOR(i,1,m) {
        cin >> x;
        b.pb(x);
    }
    FOR(i,1,n) c[i] = a[i-1];
    FOR(i,1,m) c[i + n] = b[i-1];
    k = n + m;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c+1, c+k+1);
 
    FOR(i,1,n) sa[i] = sa[i-1] + a[i-1];
    FOR(i,1,m) sb[i] = sb[i-1] + b[i-1];
 
    res = 1000000000000000000LL;
    FOR(i,1,k){
        k1 = lower_bound(a.begin(), a.end(), c[i]);
        k2 = upper_bound(b.begin(), b.end(), c[i]);
 
        x = k1 - a.begin(); x--;
        y = k2 - b.begin();
        x++; y++;
 
        w = c[i] * x - sa[x] + sb[m] - sb[y - 1] - c[i] * (m - y + 1);
        res = min(res, w);
    }
 
    cout << res;
 
    return 0;
}
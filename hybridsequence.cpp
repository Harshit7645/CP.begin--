#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int&x: a)cin >> x;
        for(int&x: b)cin >> x;
        vector<pair<int, int>>mna(n+1, {0, 1e9});
        vector<pair<int, int>>mnb(m+1, {0, 1e9});

        for(int i = 1; i <= n; i++){
            mna[i].first = max(mna[i-1].first, a[i-1]);
            mna[i].second = min(mna[i-1].second, a[i-1]);
        }

        for(int i = 1; i <= m; i++){
            mnb[i].first = max(mnb[i-1].first, b[i-1]);
            mnb[i].second = min(mnb[i-1].second, b[i-1]);
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
            if (i!=n)
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + max(mna[i+1].first, mnb[j].first) - min(mna[i+1].second, mnb[j].second));
            if (j!=m)
                dp[i][j+1] = max(dp[i][j+1], dp[i][j] + max(mna[i].first, mnb[j+1].first) - min(mna[i].second, mnb[j+1].second));
            }
        }
        cout << dp[n][m];
    }
}   
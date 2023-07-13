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

//below code is taken from geeksforgeeks
int lcs(string X, string Y)
{
    int m=X.length();
    int n=Y.length();
    // Initializing a matrix of size (m+1)*(n+1)
    int L[m + 1][n + 1];
    // Following steps build L[m+1][n+1] in bottom up
    // fashion. Note that L[i][j] contains length of LCS of
    // X[0..i-1] and Y[0..j-1]
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // L[m][n] contains length of LCS for X[0..n-1]
    // and Y[0..m-1]
    return L[m][n];
}
bool backtrack(string l,string r,int ind,vector<string>&ans,string row,string s)
{
    if(row.length()==l.length())
    {
        ans.push_back(row);
        if(lcs(row,s)<row.length())
        return true;
        return false;
    }
    for(char ch=l[ind];ch<=r[ind];ch++)
    {
        row.push_back(ch);
        if(lcs(row,s)<row.length())
        return true;
        backtrack(l,r,ind+1,ans,row,s);
        row.pop_back();
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        ll m;
        cin>>m;
        string l,r;
        cin>>l>>r;
        vector<string>ans;
        string row="";
        ll n=s.length();
        vector<vector<int>>pos(10);
        rep(i,0,n)
        {
            pos[(s[i]-'0')].push_back(i);
        }
        ll maxm=0;
        vector<int>cnt(10,0);
        rep(i,0,m)
        {
            rep(j,0,10)
            {
                for(;cnt[j]<pos[j].size() && pos[j][cnt[j]]<maxm;cnt[j]++)
                {
                    ll def=1;
                }
            }
            int val=0,f=0;
            val=maxm;
            rep(j,l[i]-'0',r[i]-'0'+1)
            {
                if(cnt[j]<pos[j].size())
                {
                    f=1;
                    val=max(val,pos[j][cnt[j]]);
                }
                else
                val=s.length();
            }
            maxm=val+1;
        }
        ll f=0;
        if(maxm>=s.length()+1)
        PYES;
        else
        PNO;
    }
}   
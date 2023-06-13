#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

int solve(vector<string>A)
{
    rep(i,0,9)
    {
        vector<int>count(10);
        rep(j,0,9)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }   
        rep(i,1,10)
        {
            if(count[i]>1)
            return 0;
        }
    }
    rep(j,0,9)
    {
        vector<int>count(10);
        rep(i,0,9)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }   
        rep(i,1,10)
        {
            if(count[i]>1)
            return 0;
        }
    }
    vector<int>count(10);
    rep(i,0,3)
    {
        rep(j,0,3)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }
    }
    rep(i,1,10)
    {
        //cout<<count[i]<<" ";
        if(count[i]>1)
        return 0;
    }
    rep(i,0,10)
    count[i]=0;
    rep(i,0,3)
    {
        rep(j,3,6)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }
    }
    rep(i,1,10)
    {
        //cout<<count[i]<<" ";
        if(count[i]>1)
        return 0;
    }
    rep(i,0,10)
    count[i]=0;
    rep(i,0,3)
    {
        rep(j,6,9)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }
    }
    rep(i,1,10)
    {
        //cout<<count[i]<<" ";
        if(count[i]>1)
        return 0;
    }
    rep(i,0,10)
    count[i]=0;
    rep(i,3,6)
    {
        rep(j,0,3)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }
    }
    rep(i,1,10)
    {
        //cout<<count[i]<<" ";
        if(count[i]>1)
        return 0;
    }
    rep(i,0,10)
    count[i]=0;
    rep(i,3,6)
    {
        rep(j,3,6)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }
    }
    rep(i,1,10)
    {
        //cout<<count[i]<<" ";
        if(count[i]>1)
        return 0;
    }
    rep(i,0,10)
    count[i]=0;
    rep(i,3,6)
    {
        rep(j,6,9)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }
    }
    rep(i,1,10)
    {
        //cout<<count[i]<<" ";
        if(count[i]>1)
        return 0;
    }
    rep(i,0,10)
    count[i]=0;
    rep(i,6,9)
    {
        rep(j,0,3)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }
    }
    rep(i,1,10)
    {
        //cout<<count[i]<<" ";
        if(count[i]>1)
        return 0;
    }
    rep(i,0,10)
    count[i]=0;
    rep(i,6,9)
    {
        rep(j,3,6)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }
    }
    rep(i,1,10)
    {
        //cout<<count[i]<<" ";
        if(count[i]>1)
        return 0;
    }
    rep(i,0,10)
    count[i]=0;
    rep(i,6,9)
    {
        rep(j,6,9)
        {
            if(A[i][j]!='.')
            count[A[i][j]-'0']++;
        }
    }
    rep(i,1,10)
    {
        //cout<<count[i]<<" ";
        if(count[i]>1)
        return 0;
    }
    return 1;
}
int main()
{
    vector<string>x={"53..7....", "..6195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
    cout<<solve(x);
}   
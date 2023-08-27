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

int solve(vector<vector<int>>A)
{
    int n=A.size();
    int left=-1,top=-1,right=-1,bottom=-1;
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            if(A[i][j]==1)
            {
                top=i;
                break;
            }
        }
    }
    rep(j,0,n)
    {
        rep(i,0,n)
        {
            if(A[i][j]==1)
            {
                left=j;
                break;
            }
        }
    }
    repr(i,n-1,0)
    {
        rep(j,0,n)
        {
            if(A[i][j]==1)
            {
                bottom=i;
                break;
            }
        }
    }
    repr(j,n-1,0)
    {
        rep(i,0,n)
        {
            if(A[i][j]==1)
            {
                right=j;
                break;
            }
        }
    }
    //cout<<left<<" "<<right<<" "<<top<<" "<<bottom<<"\n";
    return (abs(right-left)+1)*(abs(top-bottom)+1);
}

int main()
{
    cout<<solve({{0,1,0},
                 {0,1,0},
                 {0,1,0}});
}   
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

void solve(vector<vector<int>>matrix)
{
        int n=matrix.size();
        rep(i,0,n)
        {
            rep(j,0,i)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        rep(i,0,n)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    // rep(i,0,n)
    // {
    //     rep(j,0,n)
    //     {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}

int main()
{
    solve({{1,2,3},{4,5,6},{7,8,9}});
}   
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

int findMin(vector<int>denomination,int V)
{
    int n=denomination.size();
    // Initialize result
    vector<int> ans;
 
    // Traverse through all denomination
    for (int i = n - 1; i >= 0; i--) {
 
        // Find denominations
        while (V >= denomination[i]) {
            V -= denomination[i];
            ans.push_back(denomination[i]);
        }
    }
    return ans.size();
}

int fibsum(int A)
{
    vector<int>F;
    F.push_back(1);
    F.push_back(2);
    ll num=0;
    while(num<=1e9)
    {
        num=F[F.size()-1]+F[F.size()-2];
        F.push_back(num);
    }
    F.pop_back();
    return findMin(F,A);
}
int main()
{
    cout<<fibsum(11);
}   
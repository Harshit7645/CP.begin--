#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
bool isPalindrome(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        return false;
    }
    return true;
}
void backtrack(int start,string &A,vector<vector<string>>&ans,int n,vector<string>&row)
{
    if(start==n)
    {
        ans.push_back(row);
    }
    rep(i,start,n)
    {
        if(isPalindrome(A,start,i))
        {
            row.push_back(A.substr(start,i-start+1));
            backtrack(i+1,A,ans,n,row);
            row.pop_back();
        }
    }
}
vector<vector<string>>solve(string &A)
{
    int n=A.length();
    vector<string>row;
    vector<vector<string>>ans;
    backtrack(0,A,ans,n,row);
    return ans;
}
int main()
{
    string x="aab";
    vector<vector<string>>ans=solve(x);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}   
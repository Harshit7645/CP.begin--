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

vector<vector<string>> solve(string A,string target,vector<string>C)
{
    set<string>st;
    for(auto x : C)
    {
        st.insert(x);
    }
    st.insert(target);
    vector<vector<string>>ans;
    queue<vector<string>>q;
    q.push({A});
    vector<string>row;
    row.push_back(A);
    int lvl=0;
    while(!q.empty())
    {
        vector<string>vec=q.front();
        q.pop();
        if(vec.size()>lvl)
        {
            for(auto it:row)
            st.erase(it);
        }
        string word=vec.back();
        if(word==target)
        {
            if(ans.size()==0)
            ans.push_back(vec);
            else if(ans[0].size()==vec.size())
            ans.push_back(vec);
        }
        rep(i,0,word.length())
        {
            char og=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.count(word)>0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    row.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=og;
        }
    }
    return ans;
}
int main()
{
    vector<vector<string>>ans=solve("hit","cog",{"hot","dot","dog","lot","log"});
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}   
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int histarea(vector<int>hts)
{
    int n=hts.size();
    stack<int>st;
    int maxarea=0;
    for(int i=0;i<n;i++)
    {
        maxarea=max(maxarea,hts[i]);
        if(st.empty() || hts[st.top()]<=hts[i])
        {
            st.push(i);
        }
        else
        {

            while()
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<vector<int>>hts(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0)
            {
                if(v[i][j]==0)
                hts[i][j]=1;
                else
                hts[i][j]=0;
            }
            else
            {
                if(v[i][j]==0)
                hts[i][j]=hts[i-1][j]+1;
                else
                hts[i][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,histarea(hts[i]));
    }
}
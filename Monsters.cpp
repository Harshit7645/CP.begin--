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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>dist(n,vector<ll>(m,-1));
    vector<vector<pair<ll,char>>>person(n,vector<pair<ll,char>>(m,{-1,' '}));
    vector<string>v(n);
    rep(i,0,n)
    {
        cin>>v[i];
    }
    if(n==1 && m==1)
    {
        if(v[0][0]=='A')
        {
            PYES;
            cout<<"0\n";
        }   
        else
        PNO;
        return 0;
    }
    queue<vector<ll>>q;
    int sx=0,sy=0;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(v[i][j]=='M')
            {
                q.push({i,j,0});
                dist[i][j]=0;
            }
            if(v[i][j]=='A')
            {
                sx=i;
                sy=j;
            }
        }
    }
    while(!q.empty())
    {
        auto tp=q.front();
        q.pop();
        int row=tp[0];
        int col=tp[1];
        int dst=tp[2];
        rep(i,0,4)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x<0 || y<0 || x>=n || y>=m || v[x][y]=='#')
            continue;
            if(dist[x][y]!=-1)
            continue;
            dist[x][y]=dst+1;
            q.push({x,y,dst+1});
        }
    }
    // rep(i,0,n)
    // {
    //     rep(j,0,m)
    //     {
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    //map<pair<ll,ll>,pair<ll,ll>>parent;

    while(!q.empty())
    q.pop();
    q.push({sx,sy,0});
    person[sx][sy].first=0;
    person[sx][sy].second='A';
    while(!q.empty())
    {
        auto tp=q.front();
        q.pop();
        int row=tp[0];
        int col=tp[1];
        int dst=tp[2];
        rep(i,0,4)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            //parent[{x,y}]={row,col};
            if(x<0 || y<0 || x>=n || y>=m || person[x][y].first!=-1 || v[x][y]=='#')
            continue;
            person[x][y].first=dst+1;
            if(i==0)
            person[x][y].second='D';
            else if(i==1)
            person[x][y].second='R';
            else if(i==2)
            person[x][y].second='U';
            else
            person[x][y].second='L';
            q.push({x,y,dst+1});
        }
    }
    // cout<<"\n";
    // rep(i,0,n)
    // {
    //     rep(j,0,m)
    //     {
    //         cout<<person[i][j].first<<" "<<person[i][j].second<<"   ";
    //     }
    //     cout<<"\n";
    // }
    string ans="";
    ll f=0;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(i==0 || j==0 || i==n-1 || j==m-1)
            {
                if(person[i][j].first==-1)
                continue;
                if(person[i][j].first<dist[i][j] || dist[i][j]==-1)
                {
                    char ch=person[i][j].second;
                    ans+=ch;
                    ll x=i,y=j,c=0;
                    while(ch!='A')
                    {
                        if(ch=='R')
                        y--;
                        else if(ch=='L')
                        y++;
                        else if(ch=='U')
                        x++;
                        else if(ch=='D')
                        x--;
                        else
                        break;
                        ch=person[x][y].second;
                        ans+=ch;
                        //c++;
                    }
                    f=1;
                }
            }
            if(f)
            break;
        }
        if(f)
        break;
    }
    if(f)
    {
        PYES;
        cout<<ans.length()-1<<"\n";
        reverse(ans.begin(),ans.end());
        rep(i,1,ans.length())
        {
            cout<<ans[i];
        }
    }
    else
    PNO;
}   
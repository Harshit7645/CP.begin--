#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <string>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define pb push_back
//#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int main() {
    freopen("ready_go_part_2_input.txt", "r", stdin);
    freopen("ready_go_part_2_output.txt", "w", stdout);
    int t;
    cin>>t;
    int k =t;
    while(t--) {
        int m,n;
        cin>>m>>n;
        vector<vector<char>> v(m,vector<char>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin>>v[i][j];
            }
        }
        int counter=1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(v[i][j]=='W' && vis[i][j]==0) {
                    int xx = -1;
                    int yy = -1;
                    int count=0;
                    int num=0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()) {
                        num++;
                        pair<int,int> p=q.front();
                        q.pop();
                        int x=p.first;
                        int y=p.second;
                        if(x-1>=0 && v[x-1][y]=='W' && vis[x-1][y]==0) {
                            q.push({x-1,y});
                            vis[x-1][y]=1;
                        }
                        if(x-1>=0 && v[x-1][y]=='.' && vis[x-1][y]!=counter) {
                            count++;
                            xx = x-1;
                            yy = y;
                            vis[x-1][y]=counter;
                        }
                        if(x+1<m && v[x+1][y]=='W' && vis[x+1][y]==0) {
                            q.push({x+1,y});
                            vis[x+1][y]=1;
                        }
                        if(x+1<m && v[x+1][y]=='.' && vis[x+1][y]!=counter) {
                            count++;
                            xx = x+1;
                            yy = y;
                            vis[x+1][y]=counter;
                        }
                        if(y-1>=0 && v[x][y-1]=='W' && vis[x][y-1]==0) {
                            q.push({x,y-1});
                            vis[x][y-1]=1;
                        }
                        if(y-1>=0 && v[x][y-1]=='.' && vis[x][y-1]!=counter) {
                            count++;
                            xx = x;
                            yy = y-1;
                            vis[x][y-1]=counter;
                        }
                        if(y+1<n && v[x][y+1]=='W' && vis[x][y+1]==0) {
                            q.push({x,y+1});
                            vis[x][y+1]=1;
                        }
                        if(y+1<n && v[x][y+1]=='.' && vis[x][y+1]!=counter) {
                            count++;
                            xx = x;
                            yy = y+1;
                            vis[x][y+1]=counter;
                        }
                    }
                    counter++;
                    if(count==1) {
                        ans[xx][yy] += num;
                    }
                }
            }
        }
        int max=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(ans[i][j]>max) {
                    max=ans[i][j];
                }
            }
        }
        cout<<"Case #"<<k-t<<": "<<max<<endl;
    }
    return 0;
}
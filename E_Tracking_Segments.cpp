#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

struct Node { 
    int zeros; 
    int ones; 
}; 

Node mergeNodes(Node& left,Node& right) { 
    Node merged; 
    merged.zeros = left.zeros + right.zeros; 
    merged.ones = left.ones + right.ones; 
    return merged; 
} 
// Function to build the segment tree 
void build_segment_tree(vector<Node>& tree, const vector<int>& a, int node, int start, int end) {
    if (start == end) {
        if (a[start] == 0) {
            tree[node].zeros = 1;
            tree[node].ones = 0;
        } else {
            tree[node].zeros = 0;
            tree[node].ones = 1;
        }
    } else {
        int mid = (start + end) / 2;
        build_segment_tree(tree, a, 2 * node, start, mid);
        build_segment_tree(tree, a, 2 * node + 1, mid + 1, end);
        tree[node].zeros = tree[2 * node].zeros + tree[2 * node + 1].zeros;
        tree[node].ones = tree[2 * node].ones + tree[2 * node + 1].ones;
    }
}
 
// Function to update the segment tree 
void update_segment_tree(vector<Node>& tree, int node, int start, int end, int index, int value) {
    if (start == end) {
        if (value == 0) {
            tree[node].zeros = 1;
            tree[node].ones = 0;
        } else {
            tree[node].zeros = 0;
            tree[node].ones = 1;
        }
    } else {
        int mid = (start + end) / 2;
        if (start <= index && index <= mid) {
            update_segment_tree(tree, 2 * node, start, mid, index, value);
        } else {
            update_segment_tree(tree, 2 * node + 1, mid + 1, end, index, value);
        }
        tree[node].zeros = tree[2 * node].zeros + tree[2 * node + 1].zeros;
        tree[node].ones = tree[2 * node].ones + tree[2 * node + 1].ones;
    }
}
 
// Function to query the segment tree for the number of ones and zeros in a range 
Node querySegmentTree(vector<Node>& tree, int node, int start, int end, int l, int r) { 
    if (start > r || end < l) { 
        Node nullNode; 
        nullNode.zeros = 0; 
        nullNode.ones = 0; 
        return nullNode; 
    } 
    if (l <= start && end <= r) { 
        return tree[node]; 
    } 
    int mid = (start + end) / 2; 
    Node left = querySegmentTree(tree, 2 * node, start, mid, l, r); 
    Node right = querySegmentTree(tree, 2 * node + 1, mid + 1, end, l, r); 
    return mergeNodes(left, right); 
} 
 
// Function to find the minimum change number after which at least one segment becomes beautiful 
int findBeautifulSegment(vector<int>& arr,vector<pair<int, int>>& segments,vector<int>& changes) { 
    ll n = arr.size(); 
    vector<Node> tree(2 * n); 
    build_segment_tree(tree, arr, 1, 0, n - 1); 
     
    rep(i,0,changes.size())
    { 
        int index = changes[i] - 1; 
        update_segment_tree(tree,1,0,n-1,index,1); 
        for (auto & segment : segments) 
        { 
            ll l=segment.first-1; 
            ll r=segment.second-1; 
            Node result = querySegmentTree(tree, 1, 0, n - 1, l, r); 
            if (result.ones > result.zeros)
            return i + 1; 
        } 
    } 
     
    return -1; 
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>arr(n,0);
        vector<pair<int,int>>v(m);
        rep(i,0,m)
        {
            cin>>v[i].first>>v[i].second;
        }
        ll q;
        cin>>q;
        vector<int>query(q);
        rep(i,0,q)
        {
            cin>>query[i];
        }
        cout<<findBeautifulSegment(arr,v,query)<<"\n";
    }
}   
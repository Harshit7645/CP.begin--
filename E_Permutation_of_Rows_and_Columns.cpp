#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
using namespace std;

// Helper function to create a sorted vector from rows of a matrix
vector<vector<ll>> get_sorted_rows(const vector<vector<ll>>& matrix) {
    vector<vector<ll>> sorted_rows(matrix);
    for (auto& row : sorted_rows) {
        sort(row.begin(), row.end());
    }
    sort(sorted_rows.begin(), sorted_rows.end());
    return sorted_rows;
}

// Helper function to create a sorted vector from columns of a matrix
vector<vector<ll>> get_sorted_columns(const vector<vector<ll>>& matrix, ll n, ll m) {
    vector<vector<ll>> columns(m, vector<ll>(n));
    rep(j,0,m) {
        rep(i,0,n) {
            columns[j][i] = matrix[i][j];
        }
        sort(columns[j].begin(), columns[j].end());
    }
    sort(columns.begin(), columns.end());
    return columns;
}

void solve() {
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m));
        vector<vector<ll>> b(n, vector<ll>(m));
        rep(i,0,n) 
        {
            rep(j,0,m) 
            {
                cin >> a[i][j];
            }
        }
        rep(i,0,n) 
        {
            rep(j,0,m) 
            {
                cin >> b[i][j];
            }
        }
        auto sorted_a_rows = get_sorted_rows(a);
        auto sorted_b_rows = get_sorted_rows(b);
        auto sorted_a_columns = get_sorted_columns(a, n, m);
        auto sorted_b_columns = get_sorted_columns(b, n, m);
        if (sorted_a_rows == sorted_b_rows && sorted_a_columns == sorted_b_columns)
            PYES;
        else 
            PNO;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

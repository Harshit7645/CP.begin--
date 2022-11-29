#include <bits/stdc++.h>
#define sz(C) ((int) C.size())
#define show(C) for (auto J: C) cout << J << " "; cout << endl;
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    map<int,set<int>> m;
    for (int i = 0; i < 2*n; i++) {
        int no;
        cin >> no;
        if (i < n) {
            m[no].insert(p[i]);
        } else {
            m[no].insert(p[i-n]);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int preference;
        cin >> preference;
        if (m[preference].empty()) {
            cout << "-1 ";
        } else {
            int toOut = *m[preference].begin();
            cout << toOut << " ";
            for (int s=1; s<=3;s++) {
                m[s].erase(toOut);
            }
        }
    }
    return 0;
}
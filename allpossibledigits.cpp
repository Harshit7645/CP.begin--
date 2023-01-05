#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
  int T;
  cin >> T;
  while (T--) {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);

    for (auto &it : a)
      cin >> it;

    int lst = a.back();

    set<int> bigSet(a.begin(),a.end());
    set<int> smallSet(a.begin(),a.end());

    if (smallSet.size() == p) {
      cout << 0 << endl;
      continue;
    }

    int carry = 1;
    a.back() = 0;
    repr(i, (int) a.size() - 2, 0) {
      a[i] += carry;
      if (a[i] >= p) {
        a[i] -= p;
        carry = 1;
      } else
        carry = 0;
    }

    if (carry == 1)
      a.insert(a.begin(), 1);

    for (auto it : a)
      bigSet.insert(it);

    bool missSmall = false;
    rep(i, 0, lst+1) {
      if (smallSet.find(i) == smallSet.end()) {
        missSmall = true;
        break;
      }
    }

    if (missSmall) {
      int found = -1;
      repr(i, lst - 1, 0) {
        if (bigSet.find(i) == bigSet.end()) {
          found = i;
          break;
        }
      }

      if (found == -1)
        cout << p - lst << endl;
      else
        cout << p - (lst - found) << endl;
    } else {
      int found = -1;
      repr(i, p - 1, lst) {
        if (smallSet.find(i) == smallSet.end()) {
          found = i;
          break;
        }
      }
      if (found == -1)
        cout << 0 << endl;
      else
        cout << found - lst << endl;
    }
  }
}

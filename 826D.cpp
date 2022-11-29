#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll ans=0;
ll merge(int *array, int l, int m, int r) {
    ans++;
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
      //return ans;
   }
   return ans;
}
void mergeSort(int array[], int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
pair<ll,ll> fun(ll left, ll right, vector<ll>& ar,ll &ans){

    if(left==right){
        return {ar[left],ar[right]};
    }

    int mid =left +((right-left)/2);
     pair<int,int> before = fun(mid+1,right,ar,ans);
    pair<int,int> after = fun(left,mid,ar,ans);

    if(after.second>before.first){
        ans++;
        swap(after,before);
    }

    if(after.second==before.first-1 && before.second-after.first==(right-left)){
        
        return {after.first,before.second};
    }else{
        ans = INT_MIN;
        return {after.first,before.second};
    }

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
     vector<ll>arr;
        rep(i,0,n)
        {
            ll x;
            cin>>x;
            arr.push_back(x);
        }
        ll ans=0;
        fun(0,n-1,arr,ans);
    if(ans<0){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
        //cout<<ans<<"\n";
    } 
}
}

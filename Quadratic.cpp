#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    double a,b,c,r1,r2;
    cin>>a>>b>>c;
    double D;
    if(b*b-4*a*c<0)
    cout<<"No Real Roots\n";
    else{
        D=sqrt(b*b-4*a*c);
        r1=(-1*b+sqrt(D))/(2*a);
        r2=(-1*b-sqrt(D))/(2*a);
        cout<<r1<<" "<<r2<<endl;
    }

}
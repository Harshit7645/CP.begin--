#include <iostream>
using namespace std;
long long convertToBase9(long long n)
{
    long long ans = 0;
 
    // Denotes the digit place
    long long a = 1;
 
    // Method to convert any number
    // to binary equivalent
    while (n > 0) {
        ans += (a * (n % 9));
        a *= 10;
        n /= 9;
    }
    return ans;
}
 
long long getNthnumber(long long base9,
                       long long K)
{
    long long ans = 0;
 
    // denotes the current digits place
    long long a = 1;
    while (base9 > 0) {
        int cur = base9 % 10;
 
        // If current digit is >= K
        // increment its value by 1
        if (cur >= K) {
            ans += a * (cur + 1);
        }
 
        // Else add the digit as it is
        else {
            ans += a * cur;
        }
        base9 /= 10;
 
        // Move to the next digit
        a *= 10;
    }
    return ans;
}
 
// Driver code
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int N = 10, K = 4;
        cin>>N;
    long long base9 = convertToBase9(N);
    cout << getNthnumber(base9, K)<<"\n";
    }
}
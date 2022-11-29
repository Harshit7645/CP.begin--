// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;
 
void towerOfHanoi(int n, char from_rod,
                    char to_rod, char aux_rod,int ct)
{
    if (n == 0)
    {
        return ;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod,ct);
    cout <<from_rod <<" "<<to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod,ct);
}
 
// Driver code
int main()
{
    int n;
    cin>>n; // Number of disks
    cout<<pow(2,n)-1<<endl;
    towerOfHanoi(n, '1', '3', '2',0); // A, B and C are names of rods
    return 0;
}
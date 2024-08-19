#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Fenwick Tree class for range sum and count queries
class FenwickTree {
public:
    FenwickTree(int size) : size(size), tree(size + 1, 0) {}

    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

private:
    int size;
    vector<int> tree;
};

// Function to compute the desired sum
long long compute_sum(const vector<int>& A) {
    int N = A.size();

    // Coordinate compression
    vector<int> sortedA(A);
    sort(sortedA.begin(), sortedA.end());
    unordered_map<int, int> compressed;
    for (int i = 0; i < N; ++i) {
        compressed[sortedA[i]] = i + 1;
    }

    // Fenwick Trees for counts and sums
    FenwickTree count_tree(N);
    FenwickTree sum_tree(N);
    long long total_sum = 0;

    // Traverse the array
    for (int i = 0; i < N; ++i) {
        int current = compressed[A[i]];

        // Calculate counts and sums of elements less than current
        long long count_less = count_tree.query(current - 1);
        long long sum_less = sum_tree.query(current - 1);

        // Calculate counts and sums of elements greater than current
        long long count_greater = count_tree.query(N) - count_tree.query(current);
        long long sum_greater = sum_tree.query(N) - sum_tree.query(current);

        // Contribution of current element to the total sum
        total_sum += count_less * A[i] + sum_less;
        total_sum += count_greater * A[i] - sum_greater;

        // Update Fenwick Trees
        count_tree.update(current, 1);
        sum_tree.update(current, A[i]);
    }

    return total_sum;
}

int main() {
    // Sample Input 1
    vector<int> A1 = {3, 1, 4};
    cout << compute_sum(A1) << endl; // Expected output: 8

    // Sample Input 2
    vector<int> A2 = {2, 7, 1, 8, 2, 8};
    cout << compute_sum(A2) << endl; // Expected output: 53

    // Sample Input 3
    vector<int> A3 = {3, 31, 314, 3141, 31415, 314159, 2, 27, 271, 2718, 27182, 271828};
    cout << compute_sum(A3) << endl; // Expected output: 592622

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

unsigned long genA_recur_helper(int n, vector<unsigned long>& memo) {
    if (n == 0) return 1;
    if (memo[n] != 0) return memo[n]; // Check if already computed

    unsigned long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += genA_recur_helper(i, memo) * genA_recur_helper(n - 1 - i, memo);
    }
    
    memo[n] = sum; // Store computed value
    return sum;
}

unsigned long genA_recur(int n) {
	vector<unsigned long> memo(n+1,0);
	return genA_recur_helper(n,memo);
}

unsigned long genA_iter(int n) {
    std::vector<unsigned long> A(n + 1, 0);
    A[0] = 1;

    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i < k; ++i) {
            A[k] += A[i] * A[k - 1 - i];
        }
    }

    return A[n];
}

#include <iostream>
#include <vector>

using namespace std;

// this function rucursively calculates the value of An using memoization
unsigned long genA_recur_helper(int n, vector<unsigned long>& memo) {
    if (n == 0) {
	return 1; // base case
    }
    if (memo[n] != 0) {
	return memo[n]; // check if the value is already computed
    }
    unsigned long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (genA_recur_helper(i, memo))*(genA_recur_helper(n - 1 - i, memo)); // multiply the two values then add to sum
    }
    memo[n] = sum; // store the computed value to avoid recomputation
    return sum; // return An
}

unsigned long genA_recur(int n) {
	vector<unsigned long> memo(n+1,0); // create a memoization array
	return genA_recur_helper(n,memo); // call the recursive function
}

unsigned long genA_iter(int n) {
    vector<unsigned long> A(n+1,0); // create an array to store computed values
    A[0] = 1; // base case
    for (int j = 1; j <= n; ++j) { // loop to compute Aj from 1 to n 
        for (int i = 0; i < j; ++i) { // compute Aj using the recurrence relation
            A[j] += A[i] * A[j - 1 - i];
        }
    }
    return A[n]; // return final computed value
}

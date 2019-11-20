/*
Description

A sorted list A contains 1, plus some number of primes. Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered? Return your answer as an array of ints, where answer[0] = p and answer[1] = q.
A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length - 1) / 2.


Example
Example 1:

Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]

Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.
Example 2:

Input: A = [1, 7], K = 1
Output: [1, 7]

Solution:
Binary search is used, time complexity O(log(max)n), space complexity: O(1)

*/

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    const int n = A.size();
    double l = 0;
    double r = 1.0;    
    while (l < r) {
      double m = (l + r) / 2;
      double max_f = 0.0;
      int total = 0;
      int p, q = 0;
      for (int i = 0, j = 1; i < n - 1; ++i) {
        while (j < n && A[i] > m * A[j]) ++j;
        if (n == j) break;
        total += (n - j);
        const double f = static_cast<double>(A[i]) / A[j];
        if (f > max_f) {
          p = i;
          q = j;
          max_f = f;
        }
      }
      if (total == K)
        return {A[p], A[q]};        
      else if (total > K)
        r = m;
      else
        l = m;
    }
    return {};
  }
};



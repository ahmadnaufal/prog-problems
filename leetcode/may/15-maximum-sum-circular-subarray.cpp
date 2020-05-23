#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 *  Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.
 *  Here, a circular array means the end of the array connects to the beginning of the array.
 *  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
 *  Also, a subarray may only include each element of the fixed buffer A at most once.
 *  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
 */

class Solution {
public:

  /**
   *  Explanation:
   *  We have 2 cases here to be handled:
   *  1. max subarray sum is located in the middle of the array
   *  2. max subarray sum is located in the circular section of the array
   *
   *  we can use regular kadane's algorithm (find the regular max subarray sum) for the 1st case
   *  however, for the 2nd case
   */
  int maxSubarraySumCircular(vector<int>& A) {
    int maxEnd = A[0];
    int maxTotal = A[0];
    int totalSum = A[0];
    int minEnd = A[0];
    int minTotal = A[0];

    for (int i = 1; i < A.size(); ++i) {
      totalSum += A[i];
      maxEnd = max(maxEnd + A[i], A[i]);
      maxTotal = max(maxEnd, maxTotal);
      minEnd = min(minEnd + A[i], A[i]);
      minTotal = min(minEnd, minTotal);
    }

    if (maxTotal < 0) return maxTotal;

    return max(maxTotal, totalSum - minTotal);
  }

  int maxSubarraySumCircularSol(vector<int>& A) {
    // case 1
    int maxReg = kadane(A);

    // case 2
    int maxWrap = 0;
    for (int i = 0; i < A.size(); ++i) {
      maxWrap += A[i];
      A[i] = -A[i];
    }

    maxWrap += kadane(A);

    return maxWrap == 0 ? maxReg : max(maxWrap, maxReg);
  }

  int kadane(vector<int>& A) {
    int maxEnd = A[0];
    int maxTotal = A[0];
    for (int i = 1; i < A.size(); ++i) {
      maxEnd += A[i];
      if (maxEnd < A[i]) maxEnd = A[i];
      if (maxEnd > maxTotal) maxTotal = maxEnd;
    }

    return maxTotal;
  }
};

int main() {
  string s;
  getline(cin, s);

  vector<string> raw;
  istringstream iss(s);
  for (string s; iss >> s; )
    raw.push_back(s);

  vector<int> nums;
  for (string s : raw)
    nums.push_back(stoi(s));

  Solution *solution = new Solution();
  cout << solution->maxSubarraySumCircular(nums) << endl;

  return 0;
}
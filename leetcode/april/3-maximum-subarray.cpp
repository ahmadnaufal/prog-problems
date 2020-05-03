#include <bits/stdc++.h>

using namespace std;

/**
 *  Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 *  Example:
 *  Input: [-2,1,-3,4,-1,2,1,-5,4],
 *  Output: 6
 *  Explanation: [4,-1,2,1] has the largest sum = 6.
 */

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  The idea is to solve it in a divide-and-conquer approach:
   *  Calculate maximum sum from left & right side of the array.
   *  Then, to compensate maximum sum from cross array (between left & right),
   *  get maximum sum from left & right side and add them to get the maximum cross sum
   *  Finally, compare the sums (left, right, and cross)
   */
  int maxSubArray(vector<int>& nums) {
    return maxSubArrayUtil(nums, 0, nums.size()-1);
  }

  int maxSubArrayCross(vector<int>& nums, int begin, int mid, int end) {
    int sum = nums[mid];
    int leftSum = nums[mid];
    for (int i = mid-1; i >= begin; i--) {
      sum += nums[i];
      if (sum > leftSum) leftSum = sum;
    }

    sum = nums[mid+1];
    int rightSum = nums[mid+1];
    for (int i = mid+2; i <= end; ++i) {
      sum += nums[i];
      if (sum > rightSum) rightSum = sum;
    }

    return leftSum + rightSum;
  }

  int maxSubArrayUtil(vector<int>& nums, int begin, int end) {
    if (begin >= end) return nums[begin];

    int mid = begin + (end - begin) / 2;
    int leftSum = maxSubArrayUtil(nums, begin, mid),
        rightSum = maxSubArrayUtil(nums, mid+1, end),
        crossSum = maxSubArrayCross(nums, begin, mid, end);

    return max(max(leftSum, rightSum), crossSum);
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
  int sol = solution->maxSubArray(nums);
  cout << sol << endl;

  return 0;
}

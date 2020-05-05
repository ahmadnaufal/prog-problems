#include <bits/stdc++.h>

using namespace std;

/**
 *  Given an array nums, write a function to move all 0's to the end of it,
 *  while maintaining the relative order of the non-zero elements.
 *  Input: [0,1,0,3,12]
 *  Output: [1,3,12,0,0]
 *
 *  You must do this in-place without making a copy of the array.
 *  Minimize the total number of operations.
 */

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  Hint:
   *  1. use xor (a xor a = 0)
   *  2. so, a ^ b ^ a = a ^ a ^ b = b -> the remaining single number
   */
  void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;
    while (i < nums.size()) {
      if (nums[i] == 0) {
        while (j < nums.size() && nums[j] == 0) j++;

        if (j < nums.size()) swap(nums[i], nums[j]);
      }

      i++; j++;
    }
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
  solution->moveZeroes(nums);
  for (auto el : nums)
    cout << el << " ";

  cout << endl;
  return 0;
}

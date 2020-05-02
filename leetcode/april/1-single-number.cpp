#include <bits/stdc++.h>

using namespace std;

/**
 *  Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 *  Note:
 *  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
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
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int a : nums)
      res = res ^ a;
    
    return res;
  }
};

int main() {
  string s;
  cin >> s;

  vector<string> raw;
  istringstream iss(s);
  for (string s; iss >> s; ) 
    raw.push_back(s);

  vector<int> nums;
  for (string s : raw)
    nums.push_back(stoi(s));

  Solution *solution = new Solution();
  int sol = solution->singleNumber(nums);
  cout << sol << endl;

  return 0;
}

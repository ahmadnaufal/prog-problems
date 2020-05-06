#include <bits/stdc++.h>

using namespace std;

/**
 *  Given an array of size n, find the majority element.
 *  The majority element is the element that appears more than floor(n/2) times.
 *  You may assume that the array is non-empty and the majority element always exist in the array.
 */

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  Actually this problem has many apporaches to the solution:
   *  1. You can store the count for each number in a map and get the key with value more than n/2, or
   *  2. Using Boyer-Moore Majority Voting Algorithm as defined in the solution below,
   *
   *  Essentially, what Boyer-Moore does is look for a suffix, suf, of nums where suf[0] is
   *  the majority element in that suffix. To do this, we maintain a count, which is incremented whenever
   *  we see an instance of our current candidate for majority element and decremented whenever we see anything else.
   *  Whenever count equals 0, we effectively forget about everything in nums up to the current index and
   *  consider the current number as the candidate for majority element.
   */
  int majorityElement(vector<int>& nums) {
    int n;
    int freq = 0;
    for (int num : nums) {
      if (freq == 0)
        n = num;

      freq += (num == n) ? 1 : -1;
    }

    return n;
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
  cout << solution->majorityElement(nums) << endl;

  return 0;
}

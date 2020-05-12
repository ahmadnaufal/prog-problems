#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 *  Given two strings S and T, return if they are equal when both are typed into empty text editors.
 *  # means a backspace character.
 *  Note that after backspacing an empty text, the text will continue empty.
 *
 *  Example:
 *  Input: S = "ab#c", T = "ad#c"
 *  Output: true
 *  Explanation: Both S and T become "ac".
 */

/**
 *  The solution class
 */
class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];

    int l = 0, r = nums.size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (mid % 2 == 0) {
        if (nums[mid] == nums[mid+1]) l = mid+2;
        else r = mid;
      } else {
        if (nums[mid] == nums[mid-1]) l = mid+1;
        else r = mid-1;
      }
    }

    return nums[l];
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

  Solution *solution = new Solution();;
  cout << solution->singleNonDuplicate(nums) << endl;

  return 0;
}

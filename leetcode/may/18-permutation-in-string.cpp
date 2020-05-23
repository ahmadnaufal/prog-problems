#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 *  Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
 *  In other words, one of the first string's permutations is the substring of the second string.
 *  Example:
 *  Input: s1 = "ab" s2 = "eidbaooo"
 *  Output: True
 *  Explanation: s2 contains one permutation of s1 ("ba").
 */

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    if (m > n) return false;

    vector<int> count(26, 0);
    for (int i = 0; i < m; ++i) {
      count[s1[i]-'a']++;
      count[s2[i]-'a']--;
    }

    if (isAllZero(count)) return true;

    for (int i = m; i < n; ++i) {
      count[s2[i]-'a']--;
      count[s2[i-m]-'a']++;
      if (isAllZero(count)) return true;
    }

    return false;
  }

  bool isAllZero(vector<int>& nums) {
    for (int el : nums)
      if (el != 0) return false;

    return true;
  }
};

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  Solution *solution = new Solution();
  cout << solution->checkInclusion(s1, s2) << endl;

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

/**
 *  Given an array of strings, group anagrams together.
 *  Example:
 *  Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 *  Output:
 *  [
 *    ["ate","eat","tea"],
 *    ["nat","tan"],
 *    ["bat"]
 *  ]
 */

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  Approach: categorize by sorted string. sort all strings, group them with map, and output the results
   */
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> results;
    map<string, vector<string>> groups;
    for (int i = 0; i < strs.size(); ++i) {
      string cur = strs[i];
      sort(cur.begin(), cur.end());
      groups[cur].push_back(strs[i]);
    }

    for (auto p : groups)
      results.push_back(p.second);

    return results;
  }

  /**
   *  Approach: categorize by char count
   */
  vector<vector<string>> groupAnagramsByCount(vector<string>& strs) {
    map<string, vector<string>> groups;
    for (string s : strs) {
      int count[26] = {0};
      for (char c : s) count[c - 'a']++;

      string grp = "";
      for (int cnt : count) grp += "#" + to_string(cnt);
      groups[grp].push_back(s);
    }

    vector<vector<string>> results;
    for (auto p : groups)
      results.push_back(p.second);

    return results;
  }
};

int main() {
  int n;
  cin >> n;

  vector<string> strs;
  while (n--) {
    string s;
    cin >> s;
    strs.push_back(s);
  }

  Solution *solution = new Solution();
  vector<vector<string>> res = solution->groupAnagramsByCount(strs);
  for (auto group : res) {
    for (auto s : group)
      cout << s << " ";
    cout << endl;
  }

  return 0;
}
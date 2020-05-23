#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 *  Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 *  Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 *  The order of output does not matter.
 */

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    if (s.length() < p.length()) return {};

    int m = s.length(), n = p.length();
    vector<int> countP(26, 0), countS(26, 0);
    vector<int> res;

    for (int i = 0; i < n; ++i) {
      countP[p[i]-'a']++;
      countS[s[i]-'a']++;
    }

    for (int i = n; i < m; ++i) {
      if (countP == countS) res.push_back(i-n);
      countS[s[i]-'a']++;
      countS[s[i-n]-'a']--;
    }

    if (countP == countS) res.push_back(m-n);
    return res;
  }
};

int main() {
  string s, p;
  cin >> s >> p;

  Solution *solution = new Solution();
  vector<int> sol = solution->findAnagrams(s, p);
  for (int el : sol) cout << el << " ";
  cout << endl;

  return 0;
}
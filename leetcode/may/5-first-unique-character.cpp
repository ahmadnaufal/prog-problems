#include <bits/stdc++.h>

using namespace std;

/**
 *  Given a string, find the first non-repeating character in it and return it's index.
 *  If it doesn't exist, return -1.
 */

/**
 *  The solution class
 */
class Solution {
public:
  int firstUniqChar(string s) {
    map<char, int> m;
    for (int i = 0; i < s.length(); ++i)
      m[s[i]]++;

    for (int i = 0; i < s.length(); ++i)
      if (m[s[i]] == 1) return i;

    return -1;
  }
};

int main() {
  string st;
  cin >> st;

  Solution *s = new Solution();
  cout << s->firstUniqChar(st) << endl;

  return 0;
}

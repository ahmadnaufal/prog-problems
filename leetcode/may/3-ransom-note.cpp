#include <bits/stdc++.h>

using namespace std;

/**
 *  Given an arbitrary ransom note string and another string containing letters from all the magazines,
 *  write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 *  Each letter in the magazine string can only be used once in your ransom note.
 *  Note:
 *  You may assume that both strings contain only lowercase letters.
 */

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  Steps:
   *  1. store characters from magazine in a count vector
   *  2. for every occurence in ransom note, reduce the number of available char in the count vector
   *  3. if not enough char (remaining char in magazine < 0), return false
   */
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> collection(26);
    for (char c : magazine)
      collection[c-'a']++;

    for (char c : ransomNote)
      if (--collection[c-'a'] < 0) return false;

    return true;
  }
};

int main() {
  string note, magazine;
  cin >> note;
  cin >> magazine;

  Solution *s = new Solution();
  cout << s->canConstruct(note, magazine) << endl;

  return 0;
}

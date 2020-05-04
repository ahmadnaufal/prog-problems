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
  int findComplement(int num) {
    int shift = 1;
    while (shift < num)
      shift = (shift << 1) + 1;

    return num ^ shift;
  }
};

int main() {
  int n;
  cin >> n;

  Solution *s = new Solution();
  cout << s->findComplement(n) << endl;

  return 0;
}

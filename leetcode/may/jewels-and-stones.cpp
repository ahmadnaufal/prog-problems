#include <bits/stdc++.h>

using namespace std;

/**
 *  You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
 *  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
 *  The letters in J are guaranteed distinct, and all characters in J and S are letters.
 *  Letters are case sensitive, so "a" is considered a different type of stone from "A".
 */

/**
 *  The solution class
 */ 
class Solution {
public:
  /**
   *  Hint:
   *  1. store jewels in a map
   *  2. for every stone, check if its a jewel
   */
  int numJewelsInStones(string J, string S) {
    map<char, int> jewels;
    for (char js : J)
      jewels[js] = 1;
    
    int count = 0;
    for (char s : S) {
      if (jewels[s] == 1) count++;
    }
    
    return count;
  }
};

int main() {
  string J, S;
  cin >> J;
  cin >> S;

  Solution *s = new Solution();
  int numOfJewels = s->numJewelsInStones(J, S);
  cout << numOfJewels << endl;

  return 0;
}

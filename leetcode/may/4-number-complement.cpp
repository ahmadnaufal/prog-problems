#include <bits/stdc++.h>

using namespace std;

/**
 *  Given a positive integer, output its complement number.
 *  The complement strategy is to flip the bits of its binary representation.
 *
 *  Input: 5
 *  Output: 2
 *  Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010.
 *  So you need to output 2.
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

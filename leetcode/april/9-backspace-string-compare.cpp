#include <iostream>
#include <string>
#include <stack>

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
  /**
   *  Approach:
   *  Use two stacks to store the final results of the two strings
   *  If # is found, pop the last character. Else, push the char to the stack.
   *  Then, empty the stacks while checking if the top element is the same.
   *  Two strings are the same if in the end, the two stacks are empty.
   */
  bool backspaceCompare(string S, string T) {
    stack<char> st, tt;
    for (char c : S) {
      if (c == '#') {
        if (!st.empty()) st.pop();
      } else {
        st.push(c);
      }
    }

    for (char c : T) {
      if (c == '#') {
        if (!tt.empty()) tt.pop();
      } else {
        tt.push(c);
      }
    }

    while (!st.empty() && !tt.empty() && st.top() == tt.top()) {
      st.pop(); tt.pop();
    }

    return st.empty() && tt.empty();
  }
};

int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);

  Solution *s = new Solution();
  cout << s->backspaceCompare(s1, s2) << endl;

  return 0;
}

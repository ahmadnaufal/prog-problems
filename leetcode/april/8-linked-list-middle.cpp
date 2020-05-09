#include <bits/stdc++.h>
#include "../../lib/list.h"

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  Approach: by using two pointers to iterate through list: fast & slow.
   *  Fast pointer is twice as fast as the slow pointer.
   *  So, if the fast pointer is already at the end of the list, then
   *  the slow pointer must be in the middle of the list.
   */
  ListNode* middleNode(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};

int main() {
  string s;
  getline(cin, s);

  vector<string> raw;
  istringstream iss(s);
  for (string s; iss >> s; )
    raw.push_back(s);

  ListNode* list = NULL;
  for (string s : raw)
    insertNodeToList(&list, stoi(s));

  Solution* sol = new Solution();
  ListNode* mid = sol->middleNode(list);
  printList(mid);

  return 0;
}
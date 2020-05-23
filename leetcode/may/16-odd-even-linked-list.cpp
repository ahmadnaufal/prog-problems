#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../../lib/list.h"

using namespace std;

/**
 *  Given a singly linked list, group all odd nodes together followed by the even nodes.
 *  Please note here we are talking about the node number and not the value in the nodes.
 *  You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 */

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* odd = head;
    ListNode* even = head->next;

    ListNode* firstEven = even;
    while (even && even->next) {
      odd->next = even->next;
      odd = even->next;
      even->next = odd->next;
      even = odd->next;
    }

    odd->next = firstEven;

    return head;
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
  ListNode* res = sol->oddEvenList(list);
  printList(res);

  return 0;
}
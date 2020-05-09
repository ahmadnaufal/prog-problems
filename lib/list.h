#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Print list
void printList(ListNode* head) {
  ListNode* temp = head;
  while (temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}

// Function to insert node
void insertNodeToList(ListNode** root, int val) {
  ListNode* temp = new ListNode(val);
  temp->next = NULL;

  if (*root == NULL) {
    *root = temp;
    return;
  }

  ListNode* ptr = *root;
  while (ptr->next != NULL) ptr = ptr->next;
  ptr->next = temp;
}
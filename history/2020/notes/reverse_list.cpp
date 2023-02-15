#include <iostream>

using namespace std;

struct ListNode {
  int _val;
  ListNode* _next;
  ListNode(int val, ListNode* next = nullptr)
    : _val(val), _next(next) { }
};


ListNode* ReverseList(ListNode* head) {
  ListNode* pre = NULL, * tmp;
  while (head) {
    tmp = head->_next;
    head->_next = pre;
    pre = head;
    head = tmp;
  }
  return pre;
}

int main() {
  ListNode* head = new ListNode(0, nullptr);
  ListNode* curr = head;

  for (int i = 1; i < 10; ++i) {
    ListNode* temp = new ListNode(i, nullptr);
    curr->_next = temp;
    curr = temp;
  }

  curr = head;

  for (int i = 1; i < 10; ++i) {
    curr = curr->_next;
    std::cout << curr->_val << " ";
  }
  std::cout << "\n";

  ListNode* head2 = ReverseList(head);

  curr = head2;
  for (int i = 1; i < 10; ++i) {
    std::cout << curr->_val << " ";
    curr = curr->_next;
  }
  std::cout << "\n";
}
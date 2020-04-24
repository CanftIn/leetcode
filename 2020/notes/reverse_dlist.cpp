#include <iostream>

using namespace std;

struct ListNode {
  int _val;
  ListNode* _prev;
  ListNode* _next;
  ListNode(int val, ListNode* prev = nullptr, ListNode* next = nullptr)
    : _val(val), _prev(prev), _next(next) { }
};


ListNode* ReverseDList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* temp;
  while(head) {
    temp = head->_next;
    head->_next = prev;
    head->_prev = temp;
    prev = head;
    head = temp;
  }
  return prev;
}

int main() {
  ListNode* head = new ListNode(0, nullptr, nullptr);
  ListNode* curr = head;
  ListNode* tmp;

  for (int i = 1; i < 10; ++i) {
    ListNode* temp = new ListNode(i, nullptr, nullptr);
    tmp = curr;
    curr->_next = temp;
    curr = temp;
    temp->_prev = tmp;
  }

  curr = head;

  for (int i = 1; i < 10; ++i) {
    curr = curr->_next;
    std::cout << curr->_val << " ";
  }
  std::cout << "\n";

  ListNode* head2 = ReverseDList(head);

  curr = head2;
  for (int i = 1; i < 10; ++i) {
    std::cout << curr->_val << " ";
    curr = curr->_next;
  }
  std::cout << "\n";
}
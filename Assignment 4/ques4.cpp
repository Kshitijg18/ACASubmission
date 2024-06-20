# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;
    
    ListNode* last = head;
    int length = 1;
    while (last->next != NULL) {
        last = last->next;
        length++;
    }
    
    k = k % length;
    if (k == 0) return head;
    
    last->next = head;
    
    ListNode* newLast = head;
    for (int i = 0; i < length - k - 1; i++) {
        newLast = newLast->next;
    }
    
    ListNode* newHead = newLast->next;
    newLast->next = NULL;
    return newHead;
}
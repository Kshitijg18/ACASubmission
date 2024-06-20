# include <iostream>
# include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return true;
    
    vector<int> values;
    ListNode* current = head;
    while (current != nullptr) {
        values.push_back(current->val);
        current = current->next;
    }
    vector<int> reversed_values = values;
    reverse(reversed_values.begin(), reversed_values.end());
    return values == reversed_values;
}
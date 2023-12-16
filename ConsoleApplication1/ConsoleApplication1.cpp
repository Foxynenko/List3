#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main() {
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;

    cout << "Example 1: " << (hasCycle(head1) ? "true" : "false") << endl;

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2;

    cout << "Example 2: " << (hasCycle(head2) ? "true" : "false") << endl;

    ListNode* head3 = new ListNode(1);

    cout << "Example 3: " << (hasCycle(head3) ? "true" : "false") << endl;

    return 0;
}

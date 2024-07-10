/*
    This program removes a duplicate element from a sorted linked list
*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

// Helper function to create a linked list with a cycle
ListNode* createListWithCycle(std::vector<int>& values, int pos) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    ListNode* cycleEntry = nullptr;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
        if (i == pos) {
            cycleEntry = current;
        }
    }

    if (pos != -1) {
        current->next = cycleEntry;
    }

    return head;
}

int main() {
    Solution solution;

    // Example 1
    std::vector<int> values1 = {3, 2, 0, -4};
    ListNode* head1 = createListWithCycle(values1, 1);
    std::cout << std::boolalpha << solution.hasCycle(head1) << std::endl; // Output: true

    // Example 2
    std::vector<int> values2 = {1, 2};
    ListNode* head2 = createListWithCycle(values2, 0);
    std::cout << std::boolalpha << solution.hasCycle(head2) << std::endl; // Output: true

    // Example 3
    std::vector<int> values3 = {1};
    ListNode* head3 = createListWithCycle(values3, -1);
    std::cout << std::boolalpha << solution.hasCycle(head3) << std::endl; // Output: false

    // Clean up memory (for this simple test we will assume the lists are not too large)
    // In real use cases, you'd need to be careful about freeing memory in case of cycles
    // Here we do it manually since we created lists with cycles
    delete head1->next->next->next; // -4
    delete head1->next->next; // 0
    delete head1->next; // 2
    delete head1; // 3

    delete head2->next; // 2
    delete head2; // 1

    delete head3; // 1

    return 0;
}

/*
    Reverse a singly linked list.
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Initialize the current node as the head of the list
        ListNode* current = head;
        
        // Traverse the list
        while (current != nullptr && current->next != nullptr) {
            // Compare the current node with the next node
            if (current->val == current->next->val) {
                // Duplicate found, bypass the next node
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;  // Free the memory of the duplicate node
            } else {
                // Move to the next node
                current = current->next;
            }
        }
        
        // Return the head of the modified list
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Example 1
    vector<int> values1 = {1, 1, 2};
    ListNode* head1 = createList(values1);
    head1 = solution.deleteDuplicates(head1);
    printList(head1);  // Output: 1 2

    // Example 2
    vector<int> values2 = {1, 1, 2, 3, 3};
    ListNode* head2 = createList(values2);
    head2 = solution.deleteDuplicates(head2);
    printList(head2);  // Output: 1 2 3

    // Free the remaining nodes
    ListNode* current = head1;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    current = head2;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

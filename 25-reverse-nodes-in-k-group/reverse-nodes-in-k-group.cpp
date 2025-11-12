/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Function to reverse a linked list and return new head
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // new head
    }

    // Function to get the kth node from a given node
    ListNode* getKthNode(ListNode* temp, int k) {
        k = k - 1;
        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    // Main function to reverse in groups of k
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1) return head;
        
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        ListNode* newHead = NULL;

        while (temp != NULL) {
            ListNode* kthNode = getKthNode(temp, k);
            if (kthNode == NULL) {
                // less than k nodes remaining, no reversal
                if (prevLast != NULL)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            // reverse current k-group
            ListNode* reversedHead = reverseLinkedList(temp);

            // connect previous part
            if (newHead == NULL) {
                newHead = reversedHead; // first group's new head
            } else {
                prevLast->next = reversedHead;
            }

            prevLast = temp; // temp is now the last node after reversal
            temp = nextNode; // move to next group
        }

        return newHead == NULL ? head : newHead;
    }
};

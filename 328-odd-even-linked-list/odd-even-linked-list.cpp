class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // base case

        vector<int> arr;
        ListNode* temp = head;

        // Collect odd-indexed nodes
        while (temp != NULL) {
            arr.push_back(temp->val);
            if (temp->next == NULL) break; // check before skipping
            temp = temp->next->next;
        }

        // Collect even-indexed nodes
        temp = head->next;
        while (temp != NULL) {
            arr.push_back(temp->val);
            if (temp->next == NULL) break;
            temp = temp->next->next;
        }

        // Rewrite the list with rearranged values
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};

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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next != NULL && fast->next->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* mergesort(ListNode* list1, ListNode* list2){
        ListNode* dummynode= new ListNode(-1);
        ListNode* temp=dummynode;

        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1){
            temp->next=list1;
            }
        else{
            temp->next=list2;
        }

        return  dummynode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* middle=findmiddle(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=NULL;

        ListNode* left= sortList(lefthead);
        ListNode* right= sortList(righthead);

        return mergesort(left, right);


    }
};
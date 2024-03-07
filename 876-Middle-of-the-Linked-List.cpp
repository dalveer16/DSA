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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr =head;
        ListNode* mid =head;
        int currIndex=1;
        while(curr != NULL){
            if(currIndex%2==0){       
                mid=mid->next;
            }
            curr=curr->next;
            currIndex++;
        }
        return mid;
    }
};

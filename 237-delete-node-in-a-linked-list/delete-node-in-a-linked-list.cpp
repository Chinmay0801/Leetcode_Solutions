/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    node->val = node->next->val;    // step 1: overwrite value
    node->next = node->next->next;  // step 2: skip next node
}
};
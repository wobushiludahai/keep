/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct ListNode *p = list1, *q = list2, *head = NULL;
    if (p->val < q->val) {
        head = p;
        p = p->next;
    } else {
        head = q;
        q = q->next;
    }
    
    struct ListNode *cur = head;
    while (p != NULL && q != NULL) {
        if (p->val < q->val) {
            cur->next = p;
            p = p->next;
        } else {
            cur->next = q;
            q = q->next;
        }
        cur = cur->next;
    }

    if (p != NULL) cur->next = p;
    if (q != NULL) cur->next = q;
    return head;
}
// @lc code=end


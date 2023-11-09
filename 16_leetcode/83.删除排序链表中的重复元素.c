/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p = head;
    struct ListNode *next = NULL;

    while (p) {
        next = p->next;
        if (next == NULL) {
            break;
        }

        if (p->val == next->val) {
            p->next = next->next;
            free(next);
            next = NULL;
        } else {
            p = next;
        }
    }


    return head;
}
// @lc code=end


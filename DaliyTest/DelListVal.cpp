//1.删除链表中等于给定值 val 的所有节点
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL)
			return NULL;

		ListNode* pre = head;
		ListNode* cur = head->next;

		while (cur){
			if (cur->val == val){
				pre->next = cur->next;
			}
			else{
				pre = pre->next;
			}
			cur = cur->next;
		}
		return head->val == val ? head->next : head;
	}
};
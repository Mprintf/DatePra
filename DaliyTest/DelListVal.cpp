//1.ɾ�������е��ڸ���ֵ val �����нڵ�
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
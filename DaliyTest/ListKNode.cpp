//输入一个链表，输出该链表中倒数第k个结点。
//(1)用两个指针，快指针先走K步，慢指针一次走一步，两个指针同时往后移动，直到快指针走到链表的末尾（null）

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0)
			return NULL;
		ListNode* pFast = pListHead;
		ListNode* pSlow = pListHead;
		for (int i = 0; i<k; i++){
			if (pFast == NULL)
				return NULL;
			pFast = pFast->next;
		}
		while (pFast){
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		return pSlow;
	}
};


//(2)用两个指针，快指针先走（K—1）步，慢指针一次走一步，两个指针同时往后移动，直到快指针走到链表的最后一个节点
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0)
			return NULL;
		ListNode* pFast = pListHead;
		ListNode* pSlow = pListHead;
		for (int i = 0; i<k - 1; i++){
			if (pFast == NULL)
				return NULL;
			pFast = pFast->next;
		}
		if (NULL == pFast)
			return NULL;
		while (pFast->next){
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		return pSlow;
	}
};
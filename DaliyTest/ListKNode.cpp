//����һ����������������е�����k����㡣
//(1)������ָ�룬��ָ������K������ָ��һ����һ��������ָ��ͬʱ�����ƶ���ֱ����ָ���ߵ������ĩβ��null��

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


//(2)������ָ�룬��ָ�����ߣ�K��1��������ָ��һ����һ��������ָ��ͬʱ�����ƶ���ֱ����ָ���ߵ���������һ���ڵ�
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
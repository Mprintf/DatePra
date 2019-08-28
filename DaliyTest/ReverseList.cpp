//������
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode* pre = NULL;          
		ListNode* cur = head;
		ListNode* next = NULL;
		while (cur){
			next = cur->next;			//����Cur����һ���ڵ�
			cur->next = pre;			//Curָ��ԭ����ǰһ���ڵ�
			pre = cur;					//����Cur��ǰһ���ڵ�
			cur = next;					//Curÿ������ƶ�һ���ڵ�
		}
		return pre;
	}
};

//ͷ���˼��
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pCur = head;
		ListNode* pNewHead = NULL;
		while (pCur) {
			head = pCur->next;      //ͷ���ָ��cur����һ���ڵ㣬����һ���ڵ㱣������
			pCur->next = pNewHead;    //cur����������ĵ�һ���ڵ�
			pNewHead = pCur;
			pCur = head;	            //cur�ƶ���ԭ����cur��next
		}
		return pNewHead;
	}
};
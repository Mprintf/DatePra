//迭代法
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode* pre = NULL;          
		ListNode* cur = head;
		ListNode* next = NULL;
		while (cur){
			next = cur->next;			//保存Cur的下一个节点
			cur->next = pre;			//Cur指向原链表前一个节点
			pre = cur;					//保存Cur的前一个节点
			cur = next;					//Cur每次向后移动一个节点
		}
		return pre;
	}
};

//头插的思想
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pCur = head;
		ListNode* pNewHead = NULL;
		while (pCur) {
			head = pCur->next;      //头结点指向cur的下一个节点，将下一个节点保存起来
			pCur->next = pNewHead;    //cur就是新链表的第一个节点
			pNewHead = pCur;
			pCur = head;	            //cur移动到原链表cur的next
		}
		return pNewHead;
	}
};
#include"BinTree.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>

BTNode* BuyBinTreeNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;

	return pNewNode;
}

BTNode* _CreateBinTree(BTDataType* array, int size,int* index,BTDataType invalid)
{
	BTNode* pRoot = NULL;
	if (*index < size && invalid != array[*index])
	{
		//���ڵ�
		pRoot = BuyBinTreeNode(array[*index]);
		
		//����������
		++(*index);
		pRoot->_pLeft = _CreateBinTree(array, size, index,invalid);

		//����������
		++(*index);
		pRoot->_pRight = _CreateBinTree(array, size, index,invalid);
	}
	return pRoot;
}

//�������Ĵ���
BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	return _CreateBinTree(array, size, &index, invalid);
}

// �������Ŀ��� 
BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode* NewpRoot = NULL;
	if (NULL == pRoot)
		return 0;
	NewpRoot = BuyBinTreeNode(pRoot->_data);
	NewpRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
	NewpRoot->_pRight = CopyBinTree(pRoot->_pRight);

	return NewpRoot;
}

//ǰ�����
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

//�������
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

//�������
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c", pRoot->_data);
	}
}

// ������� 
void LevelOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;

	Queue q;
	QueueInin(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		printf("%c", pCur->_data);
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);

		QueuePop(&q);
	}
	QueueDestroy(&q);
	printf("\n");
}

// ��ȡ�������нڵ���� 
int GetBinTreeSize(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;

	return GetBinTreeSize(pRoot->_pLeft) + GetBinTreeSize(pRoot->_pRight) + 1;

}

// ��ȡ�������е�K��ڵ���� 
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (NULL == pRoot || K <= 0)
		return 0;
	if (1 == K)
		return 1;
	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);
}

// ��ȡ��������Ҷ�ӽڵ���� 
int GetLeafCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;

	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

// ��ȡ���������(�߶�) 
int GetBinTreeHeight(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;

	int maxLeft = GetBinTreeHeight(pRoot->_pLeft);
	int maxRight = GetBinTreeHeight(pRoot->_pRight);
	if (maxLeft < maxRight)
		return maxRight+1;
	return maxLeft+1;
}

// ���ֵΪx��Ԫ���Ƿ��ڶ������У��ڷ��ظýڵ�ĵ�ַ�����򷵻�NULL 
BTNode* BinaryTreeFind(BTNode* pRoot, BTDataType x)
{
	BTNode* pRet = NULL;
	if (NULL == pRoot)
		return NULL;

	if (pRoot->_data == x)
		return pRoot;
	
	if (pRet = BinaryTreeFind(pRoot->_pLeft, x))
		return pRet;

	return BinaryTreeFind(pRoot->_pRight, x);
}

void Swap(BTNode* pLeft, BTNode* pRight)
{
	BTNode* pTemp = pLeft;
	pLeft = pRight;
	pRight = pTemp;
}
// �������ľ��� 
void Mirror(BTNode* pRoot)
{
	if (pRoot)
	{
		Swap(&pRoot->_pLeft, &pRoot->_pRight);
		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}
void Mirror(BTNode* pRoot)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		Swap(&pRoot->_pLeft, &pRoot->_pRight);

		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight)

			QueuePop(&q);
	}
}
// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root)
{
	int BinaryTreeComplete(BTNode* pRoot) {
		if (pRoot == NULL)
			return 1;
		Queue q;
		QueueInit(&q);
		QueuePush(&q, pRoot);
		while (pRoot != NULL) {//���ڵ㲻Ϊ�գ��ͽ��г����У�����ӽڵ�����Һ���
			pRoot = QueueFront(&q);
			QueuePop(&q);
			if (pRoot != NULL) {
				QueuePush(&q, pRoot->_pLeft);
				QueuePush(&q, pRoot->_pRight);
			}
		}
		while (!QueueEmpty(&q)) {//�ڵ�ΪNULL�����в���ʱ
			pRoot = QueueFront(&q);
			QueuePop(&q);
			if (pRoot == NULL)//�ڷǿսڵ���ֳ�����NULL�ڵ㣬˵��������ȫ������
				return -1;
		}
		return 1;
	}
}
//������������
void DestroyBinTree(BTNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(pRoot);
	}
}


void Test()
{
	char* str = "ABD$$$CE$$F";
	BTNode* pRoot = CreateBinTree(str, strlen(str), '$');

	printf("ǰ����������");
	PreOrder(pRoot);
	printf("\n");

	printf("������������");
	InOrder(pRoot);
	printf("\n");

	printf("������������");
	PostOrder(pRoot);
	printf("\n");

	printf("LeafCount=:%d\n",GetLeafCount(pRoot));

	if (BinaryTreeFind(pRoot, 'C'))
	{
		printf("C is in");
	}
	else
	{
		printf("is not in");
	}

	printf("height=%d",GetBinTreeHeight(pRoot));
}


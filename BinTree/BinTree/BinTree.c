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
		//根节点
		pRoot = BuyBinTreeNode(array[*index]);
		
		//根的左子树
		++(*index);
		pRoot->_pLeft = _CreateBinTree(array, size, index,invalid);

		//根的右子树
		++(*index);
		pRoot->_pRight = _CreateBinTree(array, size, index,invalid);
	}
	return pRoot;
}

//二叉树的创建
BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	return _CreateBinTree(array, size, &index, invalid);
}

// 二叉树的拷贝 
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

//前序遍历
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

//中序遍历
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

//后序遍历
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c", pRoot->_data);
	}
}

// 层序遍历 
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

// 获取二叉树中节点个数 
int GetBinTreeSize(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;

	return GetBinTreeSize(pRoot->_pLeft) + GetBinTreeSize(pRoot->_pRight) + 1;

}

// 获取二叉树中第K层节点个数 
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (NULL == pRoot || K <= 0)
		return 0;
	if (1 == K)
		return 1;
	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);
}

// 获取二叉树中叶子节点个数 
int GetLeafCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;

	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

// 获取二叉树深度(高度) 
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

// 检测值为x的元素是否在二叉树中，在返回该节点的地址，否则返回NULL 
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
// 二叉树的镜像 
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
// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root)
{
	int BinaryTreeComplete(BTNode* pRoot) {
		if (pRoot == NULL)
			return 1;
		Queue q;
		QueueInit(&q);
		QueuePush(&q, pRoot);
		while (pRoot != NULL) {//若节点不为空，就进行出队列，并入队节点的左右孩子
			pRoot = QueueFront(&q);
			QueuePop(&q);
			if (pRoot != NULL) {
				QueuePush(&q, pRoot->_pLeft);
				QueuePush(&q, pRoot->_pRight);
			}
		}
		while (!QueueEmpty(&q)) {//节点为NULL但队列不空时
			pRoot = QueueFront(&q);
			QueuePop(&q);
			if (pRoot == NULL)//在非空节点后又出现了NULL节点，说明不是完全二叉树
				return -1;
		}
		return 1;
	}
}
//二叉树的销毁
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

	printf("前序遍历结果：");
	PreOrder(pRoot);
	printf("\n");

	printf("中序遍历结果：");
	InOrder(pRoot);
	printf("\n");

	printf("后序遍历结果：");
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


//二叉树的层序遍历
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//将结果存储在一个一维数组中
class solution{
public:
	vector<int> LevelOrder(TreeNode* root){
		vector<int> ret;
		queue<TreeNode*> q;
		if (root == NULL)
			return ret;
		q.push(root);
		while (!q.empty){
			TreeNode* cur = q.front();
			q.pop();
			ret.push_back(cur->val);
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
		return ret;
	}
};

//将结果存储在一个二维数组中，每一行存储一层
class Solution{
	vector<vector<int>> LevelOrder(TreeNode* root){
		vector<vector<int>> ret;  
		vector<int> level;           //存储每一行的节点
		queue<TreeNode*> q;
		if (root == NULL)
			return ret;
		q.push(root);
		q.push(NULL);                //每一行以NULL节点为结束
		while (!q.empty()){
			TreeNode* cur = q.front;
			q.pop();
			if (cur){
				level.push_back(cur->val);
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
			else{
				if (!level.empty()){
					level.push_back(NULL);
					ret.push_back(level);
					level.clear();
				}
			}
		}
		return ret;
	}
};
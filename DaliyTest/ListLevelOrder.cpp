//�������Ĳ������
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//������洢��һ��һά������
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

//������洢��һ����ά�����У�ÿһ�д洢һ��
class Solution{
	vector<vector<int>> LevelOrder(TreeNode* root){
		vector<vector<int>> ret;  
		vector<int> level;           //�洢ÿһ�еĽڵ�
		queue<TreeNode*> q;
		if (root == NULL)
			return ret;
		q.push(root);
		q.push(NULL);                //ÿһ����NULL�ڵ�Ϊ����
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
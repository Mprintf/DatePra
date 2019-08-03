//����һ����ά�ľ��󣬰��� 'X' �� 'O'����ĸ O����
//�ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ��䡣
//����:https://leetcode-cn.com/problems/surrounded-regions/
class Solution {
public:
	void DFS(vector<vector<char>>& board, int row, int col, int x, int y){
		static int pos[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		board[x][y] = '#';
		for (int i = 0; i<4; i++){
			int nx = x + pos[i][0];
			int ny = y + pos[i][1];
			//�жϱ߽�
			if (nx >= row || nx<0 || ny >= col || ny<0)
				continue;
			if (board[nx][ny] != '#'&&board[nx][ny] != 'X')
				DFS(board, row, col, nx, ny);
		}
	}
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;

		int row = board.size();
		int col = board[0].size();
		//������һ�к����һ��
		for (int i = 0; i<col; i++){
			if (board[0][i] == 'O'){
				DFS(board, row, col, 0, i);
			}
			if (board[row - 1][i] == 'O'){
				DFS(board, row, col, row - 1, i);
			}
		}
		//������һ�к����һ��
		for (int i = 0; i<row; i++){
			if (board[i][0] == 'O'){
				DFS(board, row, col, i, 0);
			}
			if (board[i][col - 1] == 'O'){
				DFS(board, row, col, i, col - 1);
			}
		}
		for (int i = 0; i<row; i++){
			for (int j = 0; j<col; j++){
				if (board[i][j] == '#')
					board[i][j] = 'O';
				else if (board[i][j] == 'O')
					board[i][j] = 'X';
			}
		}
	}
};
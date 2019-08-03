//给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
//找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
//链接:https://leetcode-cn.com/problems/surrounded-regions/
class Solution {
public:
	void DFS(vector<vector<char>>& board, int row, int col, int x, int y){
		static int pos[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		board[x][y] = '#';
		for (int i = 0; i<4; i++){
			int nx = x + pos[i][0];
			int ny = y + pos[i][1];
			//判断边界
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
		//遍历第一行和最后一行
		for (int i = 0; i<col; i++){
			if (board[0][i] == 'O'){
				DFS(board, row, col, 0, i);
			}
			if (board[row - 1][i] == 'O'){
				DFS(board, row, col, row - 1, i);
			}
		}
		//遍历第一列和最后一列
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
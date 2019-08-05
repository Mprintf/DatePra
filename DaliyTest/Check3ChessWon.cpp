//对于一个给定的井字棋棋盘，给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为 - 1代表是对方玩家的棋子,判断当前玩家是否获胜
//井字棋有四种情况表示当前玩家获胜，1代表当前玩家棋子
//1. 行全为1， 即行的和为3
//2. 列全为1， 列的和为3
//3. 主对角全为1， 对角和为3
//4. 副对角全为1， 对角和为3
//5. 如果扩展为N*N的话，判断和是否等于N，下面代码适用任何情况


class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int i, j, sum;
		int row = board.size();
		//判断行的和是否为row
		for (i = 0; i<row; i++){
			sum = 0;
			for (j = 0; j<row; j++){
				sum += board[i][j];
			}
			if (sum == row)
				return true;
		}
		//判断列的和是否为row
		for (i = 0; i<row; i++){
			sum = 0;
			for (j = 0; j<row; j++){
				sum += board[j][i];
			}
			if (sum == row)
				return true;
		}
		//判断主对角线之和是否为row
		sum = 0;
		for (i = 0; i<row; i++){
			sum += board[i][i];
		}
		if (sum == row)
			return true;
		//判断副对角线之和是否为row
		sum = 0;
		for (i = 0; i<row; i++){
			sum += board[i][row - 1 - i];
		}
		if (sum == row)
			return true;
		return false;
	}
};
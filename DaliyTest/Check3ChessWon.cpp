//����һ�������ľ��������̣�����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ - 1�����ǶԷ���ҵ�����,�жϵ�ǰ����Ƿ��ʤ
//�����������������ʾ��ǰ��һ�ʤ��1����ǰ�������
//1. ��ȫΪ1�� ���еĺ�Ϊ3
//2. ��ȫΪ1�� �еĺ�Ϊ3
//3. ���Խ�ȫΪ1�� �ԽǺ�Ϊ3
//4. ���Խ�ȫΪ1�� �ԽǺ�Ϊ3
//5. �����չΪN*N�Ļ����жϺ��Ƿ����N��������������κ����


class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int i, j, sum;
		int row = board.size();
		//�ж��еĺ��Ƿ�Ϊrow
		for (i = 0; i<row; i++){
			sum = 0;
			for (j = 0; j<row; j++){
				sum += board[i][j];
			}
			if (sum == row)
				return true;
		}
		//�ж��еĺ��Ƿ�Ϊrow
		for (i = 0; i<row; i++){
			sum = 0;
			for (j = 0; j<row; j++){
				sum += board[j][i];
			}
			if (sum == row)
				return true;
		}
		//�ж����Խ���֮���Ƿ�Ϊrow
		sum = 0;
		for (i = 0; i<row; i++){
			sum += board[i][i];
		}
		if (sum == row)
			return true;
		//�жϸ��Խ���֮���Ƿ�Ϊrow
		sum = 0;
		for (i = 0; i<row; i++){
			sum += board[i][row - 1 - i];
		}
		if (sum == row)
			return true;
		return false;
	}
};
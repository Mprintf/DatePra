//������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,�ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������
//���ڷ�0��������a1,a2...an��Ҫ������ȡֵ����ÿһ������ n = sum(a1...an) - a1 + 1��Ҳ����������ȥ��Сֵ֮���һ��
//���Զ���������������ɫ�������������У���Ҫ����ÿһ����ɫ������С����leftsum = ��������� - �����Сֵ + 1�� rightsum = �ұ������� - �ұߵ���Сֵ + 1��
//��������0���ڵģ�����Ҫ���ۼӣ���֤����ÿһ����ɫ��
class Gloves
{
public:
    int findMinimum(int n, vector<int> left, vector<int> right)
    {
        // write code here
        int sum = 0;
        int leftmin = INT_MAX, rightmin = INT_MAX;
        int leftsum = 0, rightsum = 0;
        for (int i = 0; i<n; i++)
        {
            //������Ϊ0��ɫ�����ۼ�
            if (left[i] * right[i] == 0)
                sum += left[i] + right[i];
            //��ֻ�ֶ��е���ɫ��������ܺ�-��Сֵ+1
            else
            {
                leftsum += left[i];
                rightsum += right[i];
                leftmin = min(leftmin, left[i]);
                rightmin = min(rightmin, right[i]);
            }
        }
        //��������Ҷ����������������еĽ��+��0����ɫ����+1
        return sum + min(leftsum - leftmin + 1, rightsum - rightmin + 1) + 1;
    }
};
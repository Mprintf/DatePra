//给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。
//对于非0递增序列a1,a2...an，要想最终取值覆盖每一个种类 n = sum(a1...an) - a1 + 1（也就是总数减去最小值之后加一）
//所以对于左右手手套颜色都有数量的序列，想要覆盖每一种颜色，则最小数量leftsum = 左边数量和 - 左边最小值 + 1， rightsum = 右边数量和 - 右边的最小值 + 1。
//而对于有0存在的，则需要做累加，保证覆盖每一种颜色。
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
            //手套数为0颜色，则累加
            if (left[i] * right[i] == 0)
                sum += left[i] + right[i];
            //两只手都有的颜色，则计算总和-最小值+1
            else
            {
                leftsum += left[i];
                rightsum += right[i];
                leftmin = min(leftmin, left[i]);
                rightmin = min(rightmin, right[i]);
            }
        }
        //计算出左右都有数量的手套序列的结果+有0的颜色手套+1
        return sum + min(leftsum - leftmin + 1, rightsum - rightmin + 1) + 1;
    }
};
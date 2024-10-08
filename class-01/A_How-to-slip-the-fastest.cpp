#include <stdio.h>
#include <math.h>



// 思路：计算距离与R的关系
// 1）距离小于R，则用2步
// 2）距离大于等于R：
//     - 不能整除，向大取整
//     - 可以整除，取结果


int main()
{
    int R, x, y;
    while (scanf("%d%d%d", &R, &x, &y) != EOF)
    {
        float distance = sqrt(x * x + y * y);
        float pace = distance / R;
        if (distance < R) // 距离小于R
        {
            printf("%d\n", 2);
        }
        else if ((int)pace < pace)  //非整数步，加1
        {
            printf("%d\n", (int)pace + 1);
        }
        else  //整数，走直线
        {
            printf("%d\n", (int)pace);
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Hannoi(int a, int b, int n) // 起点，终点，盘子个数
{
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, 'A' + a, 'A' + b);
    }
    else
    {
        // 将n-1个盘子从起始柱子移动到辅助柱子,中间柱子的计算方式为3-a-b
        Hannoi(a, 3 - a - b, n - 1);
        printf("Move disk %d from %c to %c\n", n, 'A' + a, 'A' + b);
        Hannoi(3 - a - b, b, n - 1);
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
        Hannoi(0, 2, n); // 从0号柱子转移n个盘子到2号柱子
    return 0;
}
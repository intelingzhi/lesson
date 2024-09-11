#include <stdio.h>

#define SIZE 100000


// 思路：暴力算法，一个个算

int main()
{
    int N = 0;
    int arr[SIZE] = {0};
    int times = 0;
    scanf("%d", &N);

    // 输入数组
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 统计每一个数字
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)  //统计该数字有多少个符合条件的其他数字
        {
            if ((arr[i] - arr[j]) % 200 == 0)
            {
                times++;
            }
        }
    }
    printf("%d\n", times);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

// 思路：暴力算法，一个个算，但是时间为n^2

// int main()
// {
//     int N = 0;
//     int arr[SIZE] = {0};
//     int times = 0;
//     scanf("%d", &N);

//     // 输入数组
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     // 统计每一个数字
//     for (int i = N - 1; i >= 0; i--)
//     {
//         for (int j = i - 1; j >= 0; j--)  //统计该数字有多少个符合条件的其他数字
//         {
//             if ((arr[i] - arr[j]) % 200 == 0)
//             {
//                 times++;
//             }
//         }
//     }
//     printf("%d\n", times);
//     return 0;
// }

// 使用余数进行计算，时间复杂度为n
int main()
{
    int N = 0;
    // int arr[SIZE] = {0};       // 定义序列A
    int *arr;                  // 动态分配的数组指针
    int counts_arr[200] = {0}; // 初始化余数计数数组
    int count = 0;             // 初始化计数器

    scanf("%d", &N);

    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL)
    {
        printf("内存分配失败！\n");
        return 1;
    }

    // 输入数组
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        counts_arr[arr[i] % 200]++; // 遍历数组，统计每个余数的出现次数，本质就是分组
    }

    // 计算各组的个数
    for (int i = 0; i < 200; i++)
    {
        if (counts_arr[i] > 0)
        {
            count += (counts_arr[i] * (counts_arr[i] - 1)) / 2;
        }
    }

    // 输出结果
    printf("%d\n", count);

    return 0;
}
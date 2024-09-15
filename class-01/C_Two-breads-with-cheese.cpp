#include <stdio.h>

#define SIZE 100

// 思路：取数组1的最大值，数组2的最小值，计算两者之间的数字个数。

int main()
{
    int N = 0;
    int arr1[SIZE] = {0};
    int arr2[SIZE] = {0};

    scanf("%d", &N);

    // 输入数组1
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr1[i]);
    }
    // 输入数组2
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int max = 0;
    int min = 1000;

    for (int i = 0; i < N; i++)
    {
        // 找出数组1的最大值
        if (max < arr1[i])
        {
            max = arr1[i];
        }
        // 找出数组2的最小值
        if (min > arr2[i])
        {
            min = arr2[i];
        }
    }

    int x = 0;
    if (max < min)
    {
        x = min - max + 1;
    }

    printf("%d\n", x);

    return 0;
}
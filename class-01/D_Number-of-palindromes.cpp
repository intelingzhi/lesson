#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 0≤N≤10^9
// 思路：
// 1、去除左边的0（右边的0无需去除，输入int时会自动去掉）
// 2、转换为字符串，通过字符串的前后位来比较

// 去除右边的零
int removeRightZeros(int num)
{
    while (num % 10 == 0 && num != 0)
    {
        num /= 10;
    }
    return num;
}

// 判断回文
int charge(char str[])
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main()
{
    int num;
    scanf("%d", &num);
    num = removeRightZeros(num); // 去除右边的零

    // 将整数转换为字符串
    char str[10];
    sprintf(str, "%d", num);

    // 判断
    if (charge(str))
    {
        printf("yes\n"); 
    }
    else
    {
        printf("no\n"); // 不是回文
    }

    return 0;
}
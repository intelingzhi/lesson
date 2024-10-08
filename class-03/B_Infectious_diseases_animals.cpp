#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long Solve(int x, int n) // x为传染动物数 = 10， n为轮次
{
    // TODO: 递推第 n 轮的结果
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return Solve(x, n - 1) * x + Solve(x, n - 1); // 110 + 11
    }
}
int main()
{
    long long x, n;
    while (scanf("%lld%lld", &x, &n) != EOF)
    {
        printf("%lld\n", Solve(x, n));
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int mod = 100003;
int n, k;
int ans[1111111];

int main()
{
    while (scanf("%d%d", &n, &k) != EOF)
    {
        ans[0] = 1;
        // TODO: 递推得到 ans[n]
        if (n == 0)
        {
            ans[0] = 1;
        }
        else
        {
            ans[0] = 1;
            for (int i = 1; i <= n; i++)
            {
                ans[i] = 0;
                for (int j = 1; j <= k; j++)
                {
                    if (i - j >= 0) // 大于等于0才可以走，假设我像调到x级，那就先找出到x-1级有多少种，x-2级有多少种，依次相加。
                    {
                        ans[i] += ans[i - j];
                        ans[i] = ans[i] % mod;
                    }
                }
            }
        }
        printf("%d\n", ans[n]);
    }
    return 0;
}
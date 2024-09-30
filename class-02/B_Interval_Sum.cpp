#include <stdio.h>


int main()
{
    int n = 0, times = 0;
    scanf("%d%d", &n, &times);
    long long* nums = new long long[n+1];

    // vector<int> i_arr(times);
    // vector<int> j_arr(times);
    // vector<vector<int>> matrix(n, vector<int>(n));
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     matrix[i][i] = nums[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         matrix[i][j] = nums[j] + matrix[i][j - 1];
    //     }
    // }
    // // for (int i = 0; i < n; i++)
    // // {
    // //     for (int j = 0; j < n; j++)
    // //     {
    // //         cout << matrix[i][j] << " ";
    // //     }
    // //     cout << endl;
    // // }
    // for (int i = 0; i < times; i++)
    // {
    //     cin >> i_arr[i] >> j_arr[i];
    // }
    // for (int i = 0; i < times; i++)
    // {
    //     cout << matrix[i_arr[i] - 1][j_arr[i] - 1] << endl;
    // }
    // 上面的占内存太多了

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &nums[i]);
        nums[i] += nums[i - 1];
    }
    for (int i = 0; i < times; i++)
    {
        int left, right;
        scanf("%d%d", &left, &right);
        printf("%lld\n", nums[right] - nums[left - 1]);
    }

    return 0;
}

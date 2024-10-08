#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n = 0;
    int min_i = 0, min_j = 0, min_abs = INT_MAX;
    cin >> n;
    vector<int> nums(n);
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // 暴力算
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            matrix[i][j] = abs(nums[i] + nums[j]);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] < min_abs)
            {
                min_abs = matrix[i][j];
                min_i = i + 1;
                min_j = j + 1;
            }
        }
    }
    cout << min_i << " "<< min_j << endl;
    return 0;
}


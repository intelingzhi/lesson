#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0, times = 0;
    cin >> n >> times;

    vector<int> nums(2000);

    for (int i = 0; i < n; i++)
    {
        int pos = 0;
        scanf("%d", &pos);
        nums[pos + 1000] += 1;
    }
    for (int i = 0; i < times; i++)
    {
        int k, count = 0;
        scanf("%d", &k);
        for (int j = 0; j <= 1000 + k; j++)
        {
            count += nums[j];
        }
        printf("%d\n", n - count);
    }

    return 0;
}

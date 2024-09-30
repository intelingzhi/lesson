#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0, times = 0;
    cin >> n >> times;

    vector<long long> nums(n);
    long long input_v;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &nums[i]);
    }
    for (int i = 0; i < times; i++)
    {
        scanf("%lld", &input_v);
        long long low = 0, high = n, mid = 0;
        while (low < high)   // 经典二分查找
        {
            mid = (low + high) / 2;
            if (input_v <= nums[mid])
                high = mid;
            else
                low = mid + 1;
        }
        printf("%lld\n", low + 1);
    }

    return 0;
}

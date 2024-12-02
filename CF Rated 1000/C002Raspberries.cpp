#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int mini = INT32_MAX;

        if (k == 4)
        {
            int even = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] % 4 == 0)
                {
                    even = 2;
                    break;
                }
                if (nums[i] % 2 == 0)
                {
                    even++;
                }
            }

            if (even >= 2)
            {
                mini = 0;
            }
            if (even == 1)
            {
                mini = 1;
            }
            if (even == 0)
            {
                mini = 2;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % k == 0)
            {
                mini = 0;
                break;
            }
            else
            {
                int diff = k - nums[i] % k;
                mini = min(mini, diff);
            }
        }

        cout << mini << endl;
    }

    return 0;
}
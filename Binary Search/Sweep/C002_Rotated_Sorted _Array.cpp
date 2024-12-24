#include <bits/stdc++.h>

using namespace std;

bool check(int mid, vector<int> &nums)
{
    if (nums[mid] < nums[0])
    {
        return true;
    }
    return false;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int lo = 0, hi = n - 1, ans = 0;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, nums))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
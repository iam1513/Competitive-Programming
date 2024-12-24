#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int> &nums)
{
    if (mid == nums.size() - 1)
        return true;
    if (nums[mid] > nums[mid + 1])
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
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        vector<vector<int>> ans;

        int lo = 0, hi = n - 1, peak = 0;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, nums))
            {
                peak = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        while (q--)
        {
            int k;
            cin >> k;

            lo = 0, hi = peak;
            int ans1 = -1;

            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] == k)
                {
                    ans1 = mid;
                    break;
                }
                else if (nums[mid] > k)
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }

            lo = peak + 1, hi = n - 1;
            int ans2 = -1;

            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] == k)
                {
                    ans2 = mid;
                    break;
                }
                else if (nums[mid] < k)
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }

            vector<int> store;

            if (ans1 != -1)
            {
                store.push_back(ans1 + 1);
            }

            if (ans2 != -1)
            {
                store.push_back(ans2 + 1);
            }

            if (!store.empty())
            {
                ans.push_back(store);
            }
        }

        for (const auto &row : ans)
        {
            for (const auto &col : row)
            {
                cout << col << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

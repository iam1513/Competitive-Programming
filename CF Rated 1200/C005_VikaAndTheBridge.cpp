#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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

        vector<int> last(k, -1);
        vector<int> maxi(k), maxi2(k);
        for (int i = 0; i < n; i++)
        {
            int step = i - last[nums[i] - 1];
            if (step > maxi[nums[i] - 1])
            {
                maxi2[nums[i] - 1] = maxi[nums[i] - 1];
                maxi[nums[i] - 1] = step;
            }
            else if (step > maxi2[nums[i] - 1])
            {
                maxi2[nums[i] - 1] = step;
            }
            last[nums[i] - 1] = i;
        }

        for (int i = 0; i < k; ++i)
        {
            int step = n - last[i];
            if (step > maxi[i])
            {
                maxi2[i] = maxi[i];
                maxi[i] = step;
            }
            else if (step > maxi2[i])
            {
                maxi2[i] = step;
            }
        }

        int ans = 1e9;
        for (int i = 0; i < k; i++)
        {
            ans = min(ans, max((maxi[i] + 1) / 2, maxi2[i]));
        }

        cout << ans - 1 << "\n";
    }

    return 0;
}

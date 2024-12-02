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

        bool ans = false;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == k)
            {
                ans = true;
            }
        }

        ans ? cout << "YES" << endl : cout << "NO" << endl;
    }

    return 0;
}